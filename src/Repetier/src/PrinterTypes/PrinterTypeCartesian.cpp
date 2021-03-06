/*
    This file is part of Repetier-Firmware.

    Repetier-Firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Repetier-Firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Repetier-Firmware.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "Repetier.h"

#if PRINTER_TYPE == PRINTER_TYPE_CARTESIAN

float PrinterType::bedRectangle[2][2];
uint16_t PrinterType::eprStart;

bool PrinterType::homeAxis(fast8_t axis) {
    return Motion1::simpleHome(axis);
}

/** Check if given position pos is an allowed position. Coordinate system here
 * is the transformed coordinates. In addition zOfficial is the z position in 
 * official coordinates.
 */
bool PrinterType::positionAllowed(float pos[NUM_AXES], float zOfficial) {
    if (Printer::isNoDestinationCheck()) {
        return true;
    }
    if (Printer::isHoming() || Motion1::endstopMode == EndstopMode::PROBING) {
        return true;
    }
    // Extra contrain to protect Z conditionbased on official coordinate system
    if (zOfficial < Motion1::minPos[Z_AXIS] - 0.01 || zOfficial > Motion1::maxPos[Z_AXIS] + 0.01) {
        return false;
    }
    for (fast8_t i = 0; i < Z_AXIS; i++) {
        if (Motion1::axesHomed & axisBits[i]) {
            if (pos[i] < Motion1::minPosOff[i]
                || pos[i] > Motion1::maxPosOff[i]) {
                return false;
            }
        }
    }
    return true;
}

void PrinterType::closestAllowedPositionWithNewXYOffset(float pos[NUM_AXES], float offX, float offY, float safety) {
    // offX and offY are with sign as stored in tool not when assigned later!
    // pos is in official coordinate system
    float offsets[3] = { offX, offY, 0 };
    float tOffMin, tOffMax;
    for (fast8_t i = 0; i <= Z_AXIS; i++) {
        Tool::minMaxOffsetForAxis(i, tOffMin, tOffMax);

        float p = pos[i] - offsets[i];
        float minP = Motion1::minPos[i] + safety - tOffMax;
        float maxP = Motion1::maxPos[i] - safety - tOffMin;
        if (p < minP) {
            pos[i] += minP - p;
        } else if (p > maxP) {
            pos[i] -= p - maxP;
        }
    }
}

bool PrinterType::positionOnBed(float pos[2]) {
    return pos[X_AXIS] >= bedRectangle[X_AXIS][0] && pos[X_AXIS] <= bedRectangle[X_AXIS][1] && pos[Y_AXIS] >= bedRectangle[Y_AXIS][0] && pos[Y_AXIS] <= bedRectangle[Y_AXIS][1];
}

void PrinterType::getBedRectangle(float& xmin, float& xmax, float& ymin, float& ymax) {
    xmin = bedRectangle[X_AXIS][0];
    xmax = bedRectangle[X_AXIS][1];
    ymin = bedRectangle[Y_AXIS][0];
    ymax = bedRectangle[Y_AXIS][1];
}

void PrinterType::M360() {
    Com::config(PSTR("PrinterType:Cartesian"));
    Com::config(PSTR("BedXMin:"), bedRectangle[X_AXIS][0]);
    Com::config(PSTR("BedYMin:"), bedRectangle[Y_AXIS][0]);
    Com::config(PSTR("BedXMax:"), bedRectangle[X_AXIS][1]);
    Com::config(PSTR("BedYMax:"), bedRectangle[Y_AXIS][1]);
}

void PrinterType::transform(float pos[NUM_AXES], int32_t motor[NUM_AXES]) {
    FOR_ALL_AXES(i) {
        motor[i] = lroundf(pos[i] * Motion1::resolution[i]);
    }
}

void PrinterType::disableAllowedStepper() {
    if (DISABLE_X)
        Motion1::motors[X_AXIS]->disable();
    if (DISABLE_Y)
        Motion1::motors[Y_AXIS]->disable();
    if (DISABLE_Z)
        Motion1::motors[Z_AXIS]->disable();
    for (fast8_t i = A_AXIS; i < NUM_AXES; i++) {
        Motion1::motors[i]->disable();
    }
}

float PrinterType::accelerationForMoveSteps(fast8_t axes) {
    float acceleration = 500.0f;
    if (axes & 8) {
        FOR_ALL_AXES(i) {
            if (axes & axisBits[i]) {
                acceleration = RMath::min(acceleration, Motion1::maxTravelAcceleration[i]);
            }
        }
    } else {
        FOR_ALL_AXES(i) {
            if (axes & axisBits[i]) {
                acceleration = RMath::min(acceleration, Motion1::maxAcceleration[i]);
            }
        }
    }
    return acceleration;
}

float PrinterType::feedrateForMoveSteps(fast8_t axes) {
    float feedrate = 100.0f;
    FOR_ALL_AXES(i) {
        if (axes & axisBits[i]) {
            feedrate = RMath::min(feedrate, Motion1::homingFeedrate[i]);
        }
    }
    return feedrate;
}

void PrinterType::deactivatedTool(fast8_t id) { }
void PrinterType::activatedTool(fast8_t id) { }
void PrinterType::eepromHandle() {
    EEPROM::handlePrefix(PSTR("Printer"));
    EEPROM::handleFloat(eprStart + 0, PSTR("Bed X Min [mm]"), 2, bedRectangle[X_AXIS][0]);
    EEPROM::handleFloat(eprStart + 4, PSTR("Bed X Max [mm]"), 2, bedRectangle[X_AXIS][1]);
    EEPROM::handleFloat(eprStart + 8, PSTR("Bed Y Min [mm]"), 2, bedRectangle[Y_AXIS][0]);
    EEPROM::handleFloat(eprStart + 12, PSTR("Bed Y Max [mm]"), 2, bedRectangle[Y_AXIS][1]);
    EEPROM::removePrefix();
}
void PrinterType::restoreFromConfiguration() {
    bedRectangle[X_AXIS][0] = BED_X_MIN;
    bedRectangle[X_AXIS][1] = BED_X_MAX;
    bedRectangle[Y_AXIS][0] = BED_Y_MIN;
    bedRectangle[Y_AXIS][1] = BED_Y_MAX;
}
void PrinterType::init() {
    restoreFromConfiguration();
    eprStart = EEPROM::reserve(EEPROM_SIGNATURE_CARTESIAN, 1, 4 * 4);
}
void PrinterType::updateDerived() { }
void PrinterType::enableMotors(fast8_t axes) {
    FOR_ALL_AXES(i) {
        if ((axes & axisBits[i]) != 0 && Motion1::motors[i]) {
            Motion1::motors[i]->enable();
        }
    }
    if ((axes & axisBits[E_AXIS]) != 0 && Motion1::dittoMode) {
        for (fast8_t i = 1; i <= Motion1::dittoMode; i++) {
            Tool::getTool(i)->enableMotor();
        }
    }
    Printer::unsetAllSteppersDisabled();
}

void PrinterType::setDittoMode(fast8_t count, bool mirror) {
    Motion1::dittoMode = count;
    Motion1::dittoMirror = mirror;
}

void PrinterType::transformedToOfficial(float trans[NUM_AXES], float official[NUM_AXES]) {
    Motion1::transformFromPrinter(
        trans[X_AXIS],
        trans[Y_AXIS],
        trans[Z_AXIS],
        official[X_AXIS],
        official[Y_AXIS],
        official[Z_AXIS]);
    official[X_AXIS] -= Motion1::toolOffset[X_AXIS]; // Offset from active extruder or z probe
    official[Y_AXIS] -= Motion1::toolOffset[Y_AXIS];
    official[Z_AXIS] -= Motion1::toolOffset[Z_AXIS];
    for (fast8_t i = E_AXIS; i < NUM_AXES; i++) {
        official[i] = trans[i];
    }
}

void PrinterType::officialToTransformed(float official[NUM_AXES], float trans[NUM_AXES]) {
    Motion1::transformToPrinter(official[X_AXIS] + Motion1::toolOffset[X_AXIS],
                                official[Y_AXIS] + Motion1::toolOffset[Y_AXIS],
                                official[Z_AXIS] + Motion1::toolOffset[Z_AXIS],
                                trans[X_AXIS],
                                trans[Y_AXIS],
                                trans[Z_AXIS]);
    for (fast8_t i = E_AXIS; i < NUM_AXES; i++) {
        trans[i] = official[i];
    }
}

bool PrinterType::canSelectTool(fast8_t toolId) {
    return true;
}

void PrinterType::M290(GCode* com) {
    InterruptProtectedBlock lock;
    if (com->hasX()) {
        float x = constrain(com->X, -2, 2);
        Motion2::openBabysteps[X_AXIS] += x * Motion1::resolution[X_AXIS];
    }
    if (com->hasY()) {
        float y = constrain(com->Y, -2, 2);
        Motion2::openBabysteps[Y_AXIS] += y * Motion1::resolution[Y_AXIS];
    }
    if (com->hasZ()) {
        float z = constrain(com->Z, -2, 2);
        Motion1::totalBabystepZ += z;
        Motion2::openBabysteps[Z_AXIS] += z * Motion1::resolution[Z_AXIS];
    }
    lock.unprotect();
    Com::printFLN(PSTR("BabystepZ:"), Motion1::totalBabystepZ, 4);
}

bool PrinterType::runMCode(GCode* com) {
    switch (com->M) {
    case 290:
        M290(com);
        return false;
    case 360:
        M360();
        return false;
    }
    return true;
}

bool PrinterType::runGCode(GCode* com) {
    return false;
}

PGM_P PrinterType::getGeometryName() {
    return PSTR("Cartesian");
}
#endif
