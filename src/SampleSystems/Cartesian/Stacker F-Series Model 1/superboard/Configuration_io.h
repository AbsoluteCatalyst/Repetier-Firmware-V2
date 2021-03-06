/*

This file defines io solutions used. This is the lowest level and is the base
for all higher level functions using io operations. At several places we need
subsets of these list of operations. To make configuration easy and easy to
understand, we use a technique called "x macros". This requires that only
predefined macro names for IO are used here. Do NOT add anything else here
or compilation/functionality will break.

Rules:
1. Each definition will create a class that is named like the first parameter.
This class is later used as input to templates building higher functions. By
convention the names should start with IO followed by something that helps you
identify the function.
2. Do not use a semicolon at the end. Macro definition gets different meanings
and will add the semicolon if required.

*/
/* Define motor pins here. Each motor needs a setp, dir and enable pin. */

ENDSTOP_NONE(endstopNone)

// X Motor left

IO_OUTPUT(IOX1Step, ORIG_X_STEP_PIN)
IO_OUTPUT(IOX1Dir, ORIG_X_DIR_PIN)
IO_OUTPUT_INVERTED(IOX1Enable, ORIG_X_ENABLE_PIN)

// X Motor right

IO_OUTPUT(IOAStep, ORIG_E2_STEP_PIN)
IO_OUTPUT_INVERTED(IOADir, ORIG_E2_DIR_PIN)
IO_OUTPUT_INVERTED(IOAEnable, ORIG_E2_ENABLE_PIN)

// Y Motor

IO_OUTPUT(IOY1Step, ORIG_Y_STEP_PIN)
IO_OUTPUT_INVERTED(IOY1Dir, ORIG_Y_DIR_PIN)
IO_OUTPUT_INVERTED(IOY1Enable, ORIG_Y_ENABLE_PIN)

// Z Motor

IO_OUTPUT(IOZ1Step, ORIG_Z_STEP_PIN)
IO_OUTPUT_INVERTED(IOZ1Dir, ORIG_Z_DIR_PIN)
IO_OUTPUT_INVERTED(IOZ1Enable, ORIG_Z_ENABLE_PIN)

// Z2 Motor

IO_OUTPUT(IOZ2Step, ORIG_E0_STEP_PIN)
IO_OUTPUT(IOZ2Dir, ORIG_E0_DIR_PIN)
IO_OUTPUT_INVERTED(IOZ2Enable, ORIG_E0_ENABLE_PIN)

// E0 Motor

IO_OUTPUT(IOE1Step, ORIG_E1_STEP_PIN)
IO_OUTPUT_INVERTED(IOE1Dir, ORIG_E1_DIR_PIN)
IO_OUTPUT_INVERTED(IOE1Enable, ORIG_E1_ENABLE_PIN)

// Controller input pins

#if UI_ENCODER_CLICK >= 0
IO_INPUT_INVERTED_PULLUP(ControllerClick, UI_ENCODER_CLICK)
#else
IO_INPUT_DUMMY(ControllerClick, false)
#endif
#if UI_ENCODER_A >= 0
IO_INPUT_INVERTED_PULLUP(ControllerEncA, UI_ENCODER_A)
#else
IO_INPUT_DUMMY(ControllerEncA, false)
#endif
#if UI_ENCODER_B >= 0
IO_INPUT_INVERTED_PULLUP(ControllerEncB, UI_ENCODER_B)
#else
IO_INPUT_DUMMY(ControllerEncB, false)
#endif
#if UI_BACK_PIN >= 0
IO_INPUT_PULLUP(ControllerBack, UI_BACK_PIN)
#else
IO_INPUT_DUMMY(ControllerBack, false)
#endif
#if UI_RESET_PIN >= 0
IO_INPUT_PULLUP(ControllerReset, UI_RESET_PIN)
#else
IO_INPUT_DUMMY(ControllerReset, false)
#endif

// Define your endstops inputs

// IO_INPUT_PULLUP(IOEndstopXMax, ORIG_X_MAX_PIN)
IO_INPUT_INVERTED_PULLUP(IOEndstopXMin, ORIG_X_MIN_PIN)
IO_INPUT_INVERTED_PULLUP(IOEndstopYMin, ORIG_Y_MIN_PIN)
IO_INPUT(IOJam1, ORIG_Z_MAX_PIN)

// Define our endstops solutions
// You need to define all min and max endstops for all
// axes except E even if you have none!

ENDSTOP_SWITCH_HW(endstopXMin, IOEndstopXMin, X_AXIS, false)
ENDSTOP_SWITCH_HW(endstopYMin, IOEndstopYMin, Y_AXIS, false)
ENDSTOP_NONE(endstopXMax)
ENDSTOP_NONE(endstopYMax)

#ifdef STACKER_2_Z_END_STOPS
IO_INPUT_INVERTED_PULLUP(IOEndstopZMax1, ORIG_Z_MAX_PIN) // TODO: Set correct pin
IO_INPUT_INVERTED_PULLUP(IOEndstopZMax2, ORIG_Z_MAX_PIN) // TODO: Set correct pin
ENDSTOP_SWITCH_HW(endstopZMax1, IOEndstopZMax1, -1, true)
ENDSTOP_SWITCH_HW(endstopZMax2, IOEndstopZMax2, -1, true)
ENDSTOP_MERGE2(endstopZMax, endstopZMax1, endstopZMax2, Z_AXIS, true)
#else
ENDSTOP_NONE(endstopZMax)
#endif
// Set to nullptr for no zprobe or &endstopName for a switch
#ifdef STACKER_WITH_ZPROBE
IO_INPUT_PULLUP(IOEndstopZProbe, ORIG_Z_MIN_PIN)
ENDSTOP_SWITCH_HW(endstopZProbe, IOEndstopZProbe, ZPROBE_AXIS, false)
ENDSTOP_NONE(endstopZMin)
#undef ZPROBE_ADDRESS
#define ZPROBE_ADDRESS &endstopZProbe
#else
IO_INPUT_INVERTED_PULLUP(IOEndstopZMin, ORIG_Z_MIN_PIN)
ENDSTOP_SWITCH_HW(endstopZMin, IOEndstopZMin, Z_AXIS, false)
#undef ZPROBE_ADDRESS
#define ZPROBE_ADDRESS nullptr
#endif

// Define fans

IO_OUTPUT(IOFan1, ORIG_FAN_PIN)
IO_OUTPUT(IOCoolerFan1, ORIG_FAN2_PIN)
IO_OUTPUT(IOBoardFan, HEATER_7_PIN)
IO_PWM_SOFTWARE(Fan1NoKSPWM, IOFan1, 0)
IO_PWM_SOFTWARE(CoolerFan, IOCoolerFan1, 0)
// IO_PWM_HARDWARE(Fan1PWM, 37,5000)
// IO_PDM_SOFTWARE(Fan1NoKSPWM, IOFan1) // alternative to PWM signals
IO_PWM_KICKSTART(Fan1PWM, Fan1NoKSPWM, 20, 85)
IO_PWM_SOFTWARE(BoardFan, IOBoardFan, 4)
COOLER_MANAGER_MOTORS(BoardFanController, BoardFan, 0, 192,
                      10) // reduced max power for more silent fan
// Define temperature sensors

// Typically they require an analog input (12 bit) so define
// them first.

IO_ANALOG_INPUT(IOAnalogBed1, TEMP_1_PIN, 5)
IO_ANALOG_INPUT(IOAnalogExt1, THERMOCOUPLE_0_PIN, 5)

// Need a conversion table for epcos NTC
IO_TEMP_TABLE_NTC(TempTableATC_104GT, ATC_104GT)
IO_TEMP_TABLE_PTC(TempTablePT100, PT100_STACKER)
// Now create the temperature inputs

IO_TEMPERATURE_TABLE(TempBed1, IOAnalogBed1, TempTableATC_104GT)
IO_TEMPERATURE_TABLE(TempExt1, IOAnalogExt1, TempTablePT100)

// Use PWM outputs to heat. If using hardware PWM make sure
// that the selected pin can be used as hardware pwm otherwise
// select a software pwm model whcih works on all pins.

IO_OUTPUT(IOBed1, HEATER_1_PIN)
IO_PWM_HARDWARE(PWMExtruder1, HEATER_0_PIN, 5000)
IO_PWM_SOFTWARE(PWMBed1, IOBed1, 1)

// IO_OUTPUT(IOCooler1, FAN2_PIN)
// IO_PWM_SOFTWARE(PWMCoolerExt1, FAN2_PIN, 0)

// Define all stepper motors used
// For deltas the top is the minumum position in motor coordinates
// therefore the max endstops of a delta need to be entered as
// minimum endstop here!
STEPPER_SIMPLE(XMotor, IOX1Step, IOX1Dir, IOX1Enable, endstopNone, endstopNone)
STEPPER_SIMPLE(YMotor, IOY1Step, IOY1Dir, IOY1Enable, endstopNone, endstopNone)
#ifdef STACKER_2_Z_END_STOPS
STEPPER_SIMPLE(Z1Motor, IOZ1Step, IOZ1Dir, IOZ1Enable, endstopNone, endstopZMax1)
STEPPER_SIMPLE(Z2Motor, IOZ2Step, IOZ2Dir, IOZ2Enable, endstopNone, endstopZMax2)
#else
STEPPER_SIMPLE(Z1Motor, IOZ1Step, IOZ1Dir, IOZ1Enable, endstopNone, endstopNone)
STEPPER_SIMPLE(Z2Motor, IOZ2Step, IOZ2Dir, IOZ2Enable, endstopNone, endstopNone)
#endif
STEPPER_MIRROR2(ZMotor, Z1Motor, Z2Motor, endstopNone, endstopNone)
STEPPER_SIMPLE(E1Motor, IOE1Step, IOE1Dir, IOE1Enable, endstopNone, endstopNone)

// Heat manages are used for every component that needs to
// control temperature. Higher level classes take these as input
// and simple heater like a heated bed use it directly.
HEAT_MANAGER_PID(HeatedBed1, 'B', 0, TempBed1, PWMBed1, 120, 255, 1000, 10,
                 300000, 196.0, 33.0, 290, 80, 255, false)
HEAT_MANAGER_PID(HeaterExtruder1, 'E', 0, TempExt1, PWMExtruder1, 310, 255,
                 1000, 20, 20000, 20.0, 4.0, 48, 40, 255, false)
// Extruder temperature must be in a +/-2°C corridor for 20 seconds when we wait for
// target temperature. Stops after 300 seconds with error if it does not succeed.
HEAT_MANAGER_DEFINE_HYSTERESIS(HeaterExtruder1, 2.0, 20000, 300000)
COOLER_MANAGER_SENSOR(ExtruderCooler, TempExt1, CoolerFan, 70, 200, 150, 255)

// Coolers are stand alone functions that allow it to control
// a fan with external sensors. Many extruders require a cooling
// fan pointer to the extruder to prevent heat rising up.
// These can be controlled by the cooler. Since it is
// independent you just tell what part needs cooling.
// Other use cases are board cooling and heated chambers.

// Define tools. They get inserted into a tool array in configuration.h
// Typical tools are:

TOOL_EXTRUDER(ToolExtruder1, 0, 0, 0, HeaterExtruder1, E1Motor, 1.75, 440, 20,
              50, 5000, 177, "", "", &Fan1PWM)

// IO_INPUT_LOG(IOJam1Mon, IOJam1, true)
// IO_INPUT_LOG(IOJam2Mon, IOJam2, true)
FILAMENT_DETECTOR(JamDetector1, IOJam1, ToolExtruder1)

// IO_OUTPUT(caseLightPin, HEATER_6_PIN)
IO_PWM_HARDWARE(caseLightPWM, HEATER_6_PIN, 500)
LIGHT_STATE_PWM(caseLightState)
LIGHT_COND(caseLightState, true, Printer::caseLightMode, 255, 255, 255,
           Printer::caseLightBrightness)
LIGHT_COND(caseLightState, GUI::statusLevel == GUIStatusLevel::ERROR,
           LIGHT_STATE_BLINK_SLOW, 255, 255, 255, Printer::caseLightBrightness)
LIGHT_SOURCE_PWM(caseLightDriver, caseLightPWM, caseLightState)

// Define beeper output
#if BEEPER_PIN > -1
IO_OUTPUT(IOBeeperMain, BEEPER_PIN)
BEEPER_SOURCE_IO(MainBeeper, IOBeeperMain)
#endif
