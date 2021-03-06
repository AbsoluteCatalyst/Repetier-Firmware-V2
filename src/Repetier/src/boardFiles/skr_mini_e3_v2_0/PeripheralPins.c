/*
 *******************************************************************************
 * Copyright (c) 2019, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 * Automatically generated from STM32F103R(8-B)Tx.xml and STM32F103R(C-D-E)Tx.xml
 */

#include "Arduino.h"
#include "PeripheralPins.h"

/* =====
 * Note: Commented lines are alternative possibilities which are not used per default.
 *       If you change them, you will have to know what you do
 * =====
 */ 

const PinName digitalPin[] = {
    PA_0,  //D0
    PA_1,  //D1
    PA_2,  //D2
    PA_3,  //D3
    PA_4,  //D4
    PA_5,  //D5
    PA_6,  //D6
    PA_7,  //D7
    PA_8,  //D8
    PA_9,  //D9
    PA_10, //D10
    PA_11, //D11
    PA_12, //D12
    PA_13, //D13
    PA_14, //D14
    PA_15, //D15
    PB_0,  //D16
    PB_1,  //D17
    PB_2,  //D18
    PB_3,  //D19
    PB_4,  //D20
    PB_5,  //D21
    PB_6,  //D22
    PB_7,  //D23
    PB_8,  //D24
    PB_9,  //D25
    PB_10, //D26
    PB_11, //D27
    PB_12, //D28
    PB_13, //D29
    PB_14, //D30
    PB_15, //D31
    PC_0,  //D32
    PC_1,  //D33
    PC_2,  //D34
    PC_3,  //D35
    PC_4,  //D36
    PC_5,  //D37
    PC_6,  //D38
    PC_7,  //D39
    PC_8,  //D40
    PC_9,  //D41
    PC_10, //D42
    PC_11, //D43
    PC_12, //D44
    PC_13, //D45
    PC_14, //D46
    PC_15, //D47
    PD_0,  //D48
    PD_1,  //D49
    PD_2   //D50
};

const uint32_t analogInputPin[] = {
    PA_0, //A0
    PA_1, //A1
    PA_2, //A2
    PA_3, //A3
    PA_4, //A4
    PA_5, //A5
    PA_6, //A6
    PA_7, //A7
    PB_0, //A8
    PB_1, //A9
    PC_0, //A10
    PC_1, //A11
    PC_2, //A12
    PC_3, //A13
    PC_4, //A14
    PC_5  //A15
};

//*** ADC ***
#ifdef HAL_ADC_MODULE_ENABLED
const PinMap PinMap_ADC[] = {
    { PA_0, ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 0, 0) }, // ADC1_IN0
// {PA_0,  ADC2,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 0, 0)}, // ADC2_IN0
#ifdef STM32F103xE
// {PA_0,  ADC3,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 0, 0)}, // ADC3_IN0
#endif
    { PA_1, ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 1, 0) }, // ADC1_IN1
// {PA_1,  ADC2,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 1, 0)}, // ADC2_IN1
#ifdef STM32F103xE
// {PA_1,  ADC3,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 1, 0)}, // ADC3_IN1
#endif
    // {PA_2,  ADC1,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 2, 0)}, // ADC1_IN2
    { PA_2, ADC2, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 2, 0) }, // ADC2_IN2
#ifdef STM32F103xE
// {PA_2,  ADC3,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 2, 0)}, // ADC3_IN2
#endif
#ifndef STM32F103xE
    // {PA_3,  ADC1,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 3, 0)}, // ADC1_IN3
    { PA_3, ADC2, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 3, 0) }, // ADC2_IN3
#else
    { PA_3, ADC3, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 3, 0) },        // ADC3_IN3
#endif
    // {PA_4,  ADC1,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 4, 0)}, // ADC1_IN4
    { PA_4, ADC2, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 4, 0) }, // ADC2_IN4
    { PA_5, ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 5, 0) }, // ADC1_IN5
    // {PA_5,  ADC2,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 5, 0)}, // ADC2_IN5
    // {PA_6,  ADC1,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 6, 0)}, // ADC1_IN6
    { PA_6, ADC2, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 6, 0) }, // ADC2_IN6
    { PA_7, ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 7, 0) }, // ADC1_IN7
    // {PA_7,  ADC2,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 7, 0)}, // ADC2_IN7
    // {PB_0,  ADC1,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 8, 0)}, // ADC1_IN8
    { PB_0, ADC2, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 8, 0) }, // ADC2_IN8
    { PB_1, ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 9, 0) }, // ADC1_IN9
    // {PB_1,  ADC2,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 9, 0)}, // ADC2_IN9
    // {PC_0,  ADC1,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 10, 0)}, // ADC1_IN10
    { PC_0, ADC2, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 10, 0) }, // ADC2_IN10
#ifdef STM32F103xE
// {PC_0,  ADC3,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 10, 0)}, // ADC3_IN10
#endif
    { PC_1, ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 11, 0) }, // ADC1_IN11
// {PC_1,  ADC2,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 11, 0)}, // ADC2_IN11
#ifdef STM32F103xE
// {PC_1,  ADC3,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 11, 0)}, // ADC3_IN11
#endif
    // {PC_2,  ADC1,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 12, 0)}, // ADC1_IN12
    { PC_2, ADC2, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 12, 0) }, // ADC2_IN12
#ifdef STM32F103xE
// {PC_2,  ADC3,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 12, 0)}, // ADC3_IN12
#endif
#ifndef STM32F103xE
    { PC_3, ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 13, 0) }, // ADC1_IN13
// {PC_3,  ADC2,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 13, 0)}, // ADC2_IN13
#else
    { PC_3, ADC3, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 13, 0) },       // ADC3_IN13
#endif
    // {PC_4,  ADC1,  STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 14, 0)}, // ADC1_IN14
    { PC_4, ADC2, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 14, 0) },      // ADC2_IN14
    { PC_5, ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 15, 0) },      // ADC1_IN15
    { PADC_TEMP, ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 16, 0) }, // CPU TEMP
    { PADC_VREF, ADC1, STM_PIN_DATA_EXT(STM_MODE_ANALOG, GPIO_NOPULL, 0, 17, 0) }, // CPU VREF
    { NC, NP, 0 }
};
#endif

//*** I2C ***
#ifdef HAL_I2C_MODULE_ENABLED
const PinMap PinMap_I2C_SDA[] = {
    { PB_7, I2C1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, AFIO_NONE) },
    { PB_9, I2C1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, AFIO_I2C1_ENABLE) },
    { PB_11, I2C2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, AFIO_NONE) },
    { NC, NP, 0 }
};
const PinMap PinMap_I2C_SCL[] = {
    { PB_6, I2C1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, AFIO_NONE) },
    { PB_8, I2C1, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, AFIO_I2C1_ENABLE) },
    { PB_10, I2C2, STM_PIN_DATA(STM_MODE_AF_OD, GPIO_NOPULL, AFIO_NONE) },
    { NC, NP, 0 }
};
#endif

//*** PWM ***
#ifdef HAL_TIM_MODULE_ENABLED
const PinMap PinMap_PWM[] = {
    { PA_0, TIM2, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 1, 0) }, // TIM2_CH1
// {PA_0,  TIM2,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM2_PARTIAL_2, 1, 0)}, // TIM2_CH1
#ifdef STM32F103xE
// {PA_0,  TIM5,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 1, 0)}, // TIM5_CH1
#endif
    { PA_1, TIM2, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 2, 0) }, // TIM2_CH2
// {PA_1,  TIM2,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM2_PARTIAL_2, 2, 0)}, // TIM2_CH2
#ifdef STM32F103xE
// {PA_1,  TIM5,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 2, 0)}, // TIM5_CH2
#endif
#if 0
    { PA_2, TIM2, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 3, 0) }, // TIM2_CH3
#endif
// {PA_2,  TIM2,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM2_PARTIAL_1, 3, 0)}, // TIM2_CH3
//#ifdef STM32F103xE
#if 1
    { PA_2, TIM5, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 3, 0) }, // TIM5_CH3
#endif
#ifndef STM32F103xE
    { PA_3, TIM2, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 4, 0) }, // TIM2_CH4
// {PA_3,  TIM2,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM2_PARTIAL_1, 4, 0)}, // TIM2_CH4
#else
    { PA_3, TIM5, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 4, 0) }, // TIM5_CH4
#endif
    { PA_6, TIM3, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 1, 0) }, // TIM3_CH1
#ifndef STM32F103xE
    { PA_7, TIM1, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM1_PARTIAL, 1, 1) }, // TIM1_CH1N
// {PA_7,  TIM3,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 2, 0)}, // TIM3_CH2
#else
    { PA_7, TIM8, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 1, 1) }, // TIM8_CH1N
#endif
    { PA_8, TIM1, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 1, 0) }, // TIM1_CH1
    // {PA_8,  TIM1,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM1_PARTIAL, 1, 0)}, // TIM1_CH1
    { PA_9, TIM1, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 2, 0) }, // TIM1_CH2
    // {PA_9,  TIM1,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM1_PARTIAL, 2, 0)}, // TIM1_CH2
    { PA_10, TIM1, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 3, 0) }, // TIM1_CH3
    // {PA_10, TIM1,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM1_PARTIAL, 3, 0)}, // TIM1_CH3
    { PA_11, TIM1, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 4, 0) }, // TIM1_CH4
    // {PA_11, TIM1,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM1_PARTIAL, 4, 0)}, // TIM1_CH4
    { PA_15, TIM2, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM2_PARTIAL_1, 1, 0) }, // TIM2_CH1
    // {PA_15, TIM2,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM2_ENABLE, 1, 0)}, // TIM2_CH1
    // {PB_0,  TIM1,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM1_PARTIAL, 2, 1)}, // TIM1_CH2N
    // {PB_0,  TIM3,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 3, 0)}, // TIM3_CH3
    { PB_0, TIM3, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 3, 0) }, // TIM3_CH3
#ifdef STM32F103xE
// {PB_0,  TIM8,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 2, 1)}, // TIM8_CH2N
#endif
    { PB_1, TIM1, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM1_PARTIAL, 3, 1) }, // TIM1_CH3N
// {PB_1,  TIM3,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 4, 0)}, // TIM3_CH4
// {PB_1,  TIM3,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM3_PARTIAL, 4, 0)}, // TIM3_CH4
#ifdef STM32F103xE
// {PB_1,  TIM8,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 3, 1)}, // TIM8_CH3N
#endif
    { PB_3, TIM2, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM2_PARTIAL_1, 2, 0) }, // TIM2_CH2
    // {PB_3,  TIM2,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM2_ENABLE, 2, 0)}, // TIM2_CH2
    { PB_4, TIM3, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM3_PARTIAL, 1, 0) },    // TIM3_CH1
    { PB_5, TIM3, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM3_PARTIAL, 2, 0) },    // TIM3_CH2
    { PB_6, TIM4, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 1, 0) },            // TIM4_CH1
    { PB_7, TIM4, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 2, 0) },            // TIM4_CH2
    { PB_8, TIM4, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 3, 0) },            // TIM4_CH3
    { PB_9, TIM4, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 4, 0) },            // TIM4_CH4
    { PB_10, TIM2, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM2_PARTIAL_2, 3, 0) }, // TIM2_CH3
    // {PB_10, TIM2,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM2_ENABLE, 3, 0)}, // TIM2_CH3
    { PB_11, TIM2, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM2_PARTIAL_2, 4, 0) }, // TIM2_CH4
    // {PB_11, TIM2,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM2_ENABLE, 4, 0)}, // TIM2_CH4
    { PB_13, TIM1, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 1, 1) },       // TIM1_CH1N
    { PB_14, TIM1, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 2, 1) },       // TIM1_CH2N
    { PB_15, TIM1, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 3, 1) },       // TIM1_CH3N
    { PC_6, TIM3, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM3_ENABLE, 1, 0) }, // TIM3_CH1
#ifdef STM32F103xE
// {PC_6,  TIM8,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 1, 0)}, // TIM8_CH1
#endif
    { PC_7, TIM3, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM3_ENABLE, 2, 0) }, // TIM3_CH2
#ifdef STM32F103xE
// {PC_7,  TIM8,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 2, 0)}, // TIM8_CH2
#endif

#ifndef STM32F103xE
    { PC_8, TIM3, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM3_ENABLE, 3, 0) }, // TIM3_CH3
#else
    { PC_8, TIM8, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 3, 0) }, // TIM8_CH3
#endif
#if 0
  {PC_9,  TIM3,   STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_TIM3_ENABLE, 4, 0)},
#endif
    { PC_9, TIM8, STM_PIN_DATA_EXT(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE, 4, 0) }, // TIM8_CH4
    { NC, NP, 0 }
};
#endif

//*** SERIAL ***
#ifdef HAL_UART_MODULE_ENABLED
const PinMap PinMap_UART_TX[] = {
    { PA_2, USART2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
    { PA_9, USART1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
    { PB_6, USART1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_USART1_ENABLE) },
//{ PB_10, USART3, STM_PIN_DATA(STM_MODE_INPUT, GPIO_PULLUP, AFIO_NONE) },
#if 0 // Moses - Remapped UART4 to USART3
    { PC_10, UART4, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, AFIO_NONE) },
#else
    { PC_10, USART3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_NOPULL, AFIO_USART3_PARTIAL) },
#endif
#ifdef STM32F103xE
    { PC_12, UART5, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
#endif
    { NC, NP, 0 }
};
const PinMap PinMap_UART_RX[] = {
    { PA_3, USART2, STM_PIN_DATA(STM_MODE_INPUT, GPIO_PULLUP, AFIO_NONE) },
    { PA_10, USART1, STM_PIN_DATA(STM_MODE_INPUT, GPIO_PULLUP, AFIO_NONE) },
    { PB_7, USART1, STM_PIN_DATA(STM_MODE_INPUT, GPIO_PULLUP, AFIO_USART1_ENABLE) },
//{ PB_11, USART3, STM_PIN_DATA(STM_MODE_INPUT, GPIO_PULLUP, AFIO_NONE) },
#if 0 // Moses - Remapped UART4 to USART3
    { PC_11, UART4, STM_PIN_DATA(STM_MODE_INPUT, GPIO_PULLUP, AFIO_NONE) },
#else
    { PC_11, USART3, STM_PIN_DATA(STM_MODE_INPUT, GPIO_PULLUP, AFIO_NONE) },
#endif
#ifdef STM32F103xE
    { PD_2, UART5, STM_PIN_DATA(STM_MODE_INPUT, GPIO_PULLUP, AFIO_NONE) },
#endif
    { NC, NP, 0 }
};
const PinMap PinMap_UART_RTS[] = {
    { PA_1, USART2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
    { PA_12, USART1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
    { PB_14, USART3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
    { PB_14, USART3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_USART3_PARTIAL) },
    { NC, NP, 0 }
};
const PinMap PinMap_UART_CTS[] = {
    { PA_0, USART2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
    { PA_11, USART1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
    { PB_13, USART3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
    { PB_13, USART3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_USART3_PARTIAL) },
    { NC, NP, 0 }
};
#endif

//*** SPI ***

#ifdef HAL_SPI_MODULE_ENABLED
const PinMap PinMap_SPI_MOSI[] = {
    { PA_7, SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
#ifndef STM32F103xE
    { PB_5, SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_SPI1_ENABLE) },
#else
    { PB_5, SPI3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
#endif
    { PB_15, SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
    { NC, NP, 0 }
};
const PinMap PinMap_SPI_MISO[] = {
    { PA_6, SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
#ifndef STM32F103xE
    { PB_4, SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_SPI1_ENABLE) },
#else
    { PB_4, SPI3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
#endif
    { PB_14, SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
    { NC, NP, 0 }
};
const PinMap PinMap_SPI_SCLK[] = {
    { PA_5, SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
#ifndef STM32F103xE
    { PB_3, SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_SPI1_ENABLE) },
#else
    { PB_3, SPI3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
#endif
    { PB_13, SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
    { NC, NP, 0 }
};
const PinMap PinMap_SPI_SSEL[] = {
    { PA_4, SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
#ifndef STM32F103xE
    { PA_15, SPI1, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_SPI1_ENABLE) },
#else
    { PA_15, SPI3, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
#endif
    { PB_12, SPI2, STM_PIN_DATA(STM_MODE_AF_PP, GPIO_PULLUP, AFIO_NONE) },
    { NC, NP, 0 }
};
#endif

//*** USB ***
#ifdef HAL_PCD_MODULE_ENABLED
const PinMap PinMap_USB[] = {
    { PA_11, USB, STM_PIN_DATA(STM_MODE_INPUT, GPIO_NOPULL, AFIO_NONE) }, // USB_DM
    { PA_12, USB, STM_PIN_DATA(STM_MODE_INPUT, GPIO_NOPULL, AFIO_NONE) }, // USB_DP
    { NC, NP, 0 }
};
 

#endif
