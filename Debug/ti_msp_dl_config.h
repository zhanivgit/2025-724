/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_MOTOR */
#define PWM_MOTOR_INST                                                     TIMA0
#define PWM_MOTOR_INST_IRQHandler                               TIMA0_IRQHandler
#define PWM_MOTOR_INST_INT_IRQN                                 (TIMA0_INT_IRQn)
#define PWM_MOTOR_INST_CLK_FREQ                                          8000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_MOTOR_C0_PORT                                             GPIOA
#define GPIO_PWM_MOTOR_C0_PIN                                     DL_GPIO_PIN_21
#define GPIO_PWM_MOTOR_C0_IOMUX                                  (IOMUX_PINCM46)
#define GPIO_PWM_MOTOR_C0_IOMUX_FUNC                 IOMUX_PINCM46_PF_TIMA0_CCP0
#define GPIO_PWM_MOTOR_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_MOTOR_C1_PORT                                             GPIOA
#define GPIO_PWM_MOTOR_C1_PIN                                     DL_GPIO_PIN_22
#define GPIO_PWM_MOTOR_C1_IOMUX                                  (IOMUX_PINCM47)
#define GPIO_PWM_MOTOR_C1_IOMUX_FUNC                 IOMUX_PINCM47_PF_TIMA0_CCP1
#define GPIO_PWM_MOTOR_C1_IDX                                DL_TIMER_CC_1_INDEX

/* Defines for PWM_SERVO */
#define PWM_SERVO_INST                                                     TIMA1
#define PWM_SERVO_INST_IRQHandler                               TIMA1_IRQHandler
#define PWM_SERVO_INST_INT_IRQN                                 (TIMA1_INT_IRQn)
#define PWM_SERVO_INST_CLK_FREQ                                           400000
/* GPIO defines for channel 0 */
#define GPIO_PWM_SERVO_C0_PORT                                             GPIOA
#define GPIO_PWM_SERVO_C0_PIN                                     DL_GPIO_PIN_15
#define GPIO_PWM_SERVO_C0_IOMUX                                  (IOMUX_PINCM37)
#define GPIO_PWM_SERVO_C0_IOMUX_FUNC                 IOMUX_PINCM37_PF_TIMA1_CCP0
#define GPIO_PWM_SERVO_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_SERVO_C1_PORT                                             GPIOA
#define GPIO_PWM_SERVO_C1_PIN                                     DL_GPIO_PIN_16
#define GPIO_PWM_SERVO_C1_IOMUX                                  (IOMUX_PINCM38)
#define GPIO_PWM_SERVO_C1_IOMUX_FUNC                 IOMUX_PINCM38_PF_TIMA1_CCP1
#define GPIO_PWM_SERVO_C1_IDX                                DL_TIMER_CC_1_INDEX




/* Defines for I2C_OLED */
#define I2C_OLED_INST                                                       I2C1
#define I2C_OLED_INST_IRQHandler                                 I2C1_IRQHandler
#define I2C_OLED_INST_INT_IRQN                                     I2C1_INT_IRQn
#define I2C_OLED_BUS_SPEED_HZ                                             400000
#define GPIO_I2C_OLED_SDA_PORT                                             GPIOB
#define GPIO_I2C_OLED_SDA_PIN                                      DL_GPIO_PIN_3
#define GPIO_I2C_OLED_IOMUX_SDA                                  (IOMUX_PINCM16)
#define GPIO_I2C_OLED_IOMUX_SDA_FUNC                   IOMUX_PINCM16_PF_I2C1_SDA
#define GPIO_I2C_OLED_SCL_PORT                                             GPIOB
#define GPIO_I2C_OLED_SCL_PIN                                      DL_GPIO_PIN_2
#define GPIO_I2C_OLED_IOMUX_SCL                                  (IOMUX_PINCM15)
#define GPIO_I2C_OLED_IOMUX_SCL_FUNC                   IOMUX_PINCM15_PF_I2C1_SCL

/* Defines for I2C_LSM6DSV16X */
#define I2C_LSM6DSV16X_INST                                                 I2C0
#define I2C_LSM6DSV16X_INST_IRQHandler                           I2C0_IRQHandler
#define I2C_LSM6DSV16X_INST_INT_IRQN                               I2C0_INT_IRQn
#define I2C_LSM6DSV16X_BUS_SPEED_HZ                                      1000000
#define GPIO_I2C_LSM6DSV16X_SDA_PORT                                       GPIOA
#define GPIO_I2C_LSM6DSV16X_SDA_PIN                               DL_GPIO_PIN_10
#define GPIO_I2C_LSM6DSV16X_IOMUX_SDA                            (IOMUX_PINCM21)
#define GPIO_I2C_LSM6DSV16X_IOMUX_SDA_FUNC               IOMUX_PINCM21_PF_I2C0_SDA
#define GPIO_I2C_LSM6DSV16X_SCL_PORT                                       GPIOA
#define GPIO_I2C_LSM6DSV16X_SCL_PIN                               DL_GPIO_PIN_11
#define GPIO_I2C_LSM6DSV16X_IOMUX_SCL                            (IOMUX_PINCM22)
#define GPIO_I2C_LSM6DSV16X_IOMUX_SCL_FUNC               IOMUX_PINCM22_PF_I2C0_SCL


/* Defines for UART_OPENMV */
#define UART_OPENMV_INST                                                   UART0
#define UART_OPENMV_INST_FREQUENCY                                      40000000
#define UART_OPENMV_INST_IRQHandler                             UART0_IRQHandler
#define UART_OPENMV_INST_INT_IRQN                                 UART0_INT_IRQn
#define GPIO_UART_OPENMV_RX_PORT                                           GPIOA
#define GPIO_UART_OPENMV_TX_PORT                                           GPIOA
#define GPIO_UART_OPENMV_RX_PIN                                    DL_GPIO_PIN_1
#define GPIO_UART_OPENMV_TX_PIN                                    DL_GPIO_PIN_0
#define GPIO_UART_OPENMV_IOMUX_RX                                 (IOMUX_PINCM2)
#define GPIO_UART_OPENMV_IOMUX_TX                                 (IOMUX_PINCM1)
#define GPIO_UART_OPENMV_IOMUX_RX_FUNC                  IOMUX_PINCM2_PF_UART0_RX
#define GPIO_UART_OPENMV_IOMUX_TX_FUNC                  IOMUX_PINCM1_PF_UART0_TX
#define UART_OPENMV_BAUD_RATE                                             (9600)
#define UART_OPENMV_IBRD_40_MHZ_9600_BAUD                                  (260)
#define UART_OPENMV_FBRD_40_MHZ_9600_BAUD                                   (27)





/* Port definition for Pin Group GPIO_LED */
#define GPIO_LED_PORT                                                    (GPIOB)

/* Defines for PIN_LED1: GPIOB.22 with pinCMx 50 on package pin 21 */
#define GPIO_LED_PIN_LED1_PIN                                   (DL_GPIO_PIN_22)
#define GPIO_LED_PIN_LED1_IOMUX                                  (IOMUX_PINCM50)
/* Port definition for Pin Group GPIO_BUTTON */
#define GPIO_BUTTON_PORT                                                 (GPIOB)

/* Defines for PIN_S2: GPIOB.21 with pinCMx 49 on package pin 20 */
#define GPIO_BUTTON_PIN_S2_PIN                                  (DL_GPIO_PIN_21)
#define GPIO_BUTTON_PIN_S2_IOMUX                                 (IOMUX_PINCM49)
/* Port definition for Pin Group GPIO_LSM6DSV16X */
#define GPIO_LSM6DSV16X_PORT                                             (GPIOB)

/* Defines for PIN_INT: GPIOB.9 with pinCMx 26 on package pin 61 */
// pins affected by this interrupt request:["PIN_INT"]
#define GPIO_LSM6DSV16X_INT_IRQN                                (GPIOB_INT_IRQn)
#define GPIO_LSM6DSV16X_INT_IIDX                (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_LSM6DSV16X_PIN_INT_IIDX                         (DL_GPIO_IIDX_DIO9)
#define GPIO_LSM6DSV16X_PIN_INT_PIN                              (DL_GPIO_PIN_9)
#define GPIO_LSM6DSV16X_PIN_INT_IOMUX                            (IOMUX_PINCM26)
/* Port definition for Pin Group GPIO_BUZZER */
#define GPIO_BUZZER_PORT                                                 (GPIOB)

/* Defines for PIN_buzzer: GPIOB.13 with pinCMx 30 on package pin 1 */
#define GPIO_BUZZER_PIN_buzzer_PIN                              (DL_GPIO_PIN_13)
#define GPIO_BUZZER_PIN_buzzer_IOMUX                             (IOMUX_PINCM30)
/* Defines for PIN_FL1: GPIOB.14 with pinCMx 31 on package pin 2 */
#define GPIO_MOTOR_PIN_FL1_PORT                                          (GPIOB)
#define GPIO_MOTOR_PIN_FL1_PIN                                  (DL_GPIO_PIN_14)
#define GPIO_MOTOR_PIN_FL1_IOMUX                                 (IOMUX_PINCM31)
/* Defines for PIN_FL2: GPIOB.15 with pinCMx 32 on package pin 3 */
#define GPIO_MOTOR_PIN_FL2_PORT                                          (GPIOB)
#define GPIO_MOTOR_PIN_FL2_PIN                                  (DL_GPIO_PIN_15)
#define GPIO_MOTOR_PIN_FL2_IOMUX                                 (IOMUX_PINCM32)
/* Defines for PIN_FR1: GPIOB.16 with pinCMx 33 on package pin 4 */
#define GPIO_MOTOR_PIN_FR1_PORT                                          (GPIOB)
#define GPIO_MOTOR_PIN_FR1_PIN                                  (DL_GPIO_PIN_16)
#define GPIO_MOTOR_PIN_FR1_IOMUX                                 (IOMUX_PINCM33)
/* Defines for PIN_FR2: GPIOA.12 with pinCMx 34 on package pin 5 */
#define GPIO_MOTOR_PIN_FR2_PORT                                          (GPIOA)
#define GPIO_MOTOR_PIN_FR2_PIN                                  (DL_GPIO_PIN_12)
#define GPIO_MOTOR_PIN_FR2_IOMUX                                 (IOMUX_PINCM34)
/* Defines for PIN_FSTBY: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_MOTOR_PIN_FSTBY_PORT                                        (GPIOA)
#define GPIO_MOTOR_PIN_FSTBY_PIN                                (DL_GPIO_PIN_13)
#define GPIO_MOTOR_PIN_FSTBY_IOMUX                               (IOMUX_PINCM35)
/* Defines for PIN_TRACK1: GPIOA.23 with pinCMx 53 on package pin 24 */
#define GPIO_TRACK_PIN_TRACK1_PORT                                       (GPIOA)
#define GPIO_TRACK_PIN_TRACK1_PIN                               (DL_GPIO_PIN_23)
#define GPIO_TRACK_PIN_TRACK1_IOMUX                              (IOMUX_PINCM53)
/* Defines for PIN_TRACK2: GPIOB.24 with pinCMx 52 on package pin 23 */
#define GPIO_TRACK_PIN_TRACK2_PORT                                       (GPIOB)
#define GPIO_TRACK_PIN_TRACK2_PIN                               (DL_GPIO_PIN_24)
#define GPIO_TRACK_PIN_TRACK2_IOMUX                              (IOMUX_PINCM52)
/* Defines for PIN_TRACK3: GPIOA.24 with pinCMx 54 on package pin 25 */
#define GPIO_TRACK_PIN_TRACK3_PORT                                       (GPIOA)
#define GPIO_TRACK_PIN_TRACK3_PIN                               (DL_GPIO_PIN_24)
#define GPIO_TRACK_PIN_TRACK3_IOMUX                              (IOMUX_PINCM54)
/* Defines for PIN_TRACK4: GPIOA.25 with pinCMx 55 on package pin 26 */
#define GPIO_TRACK_PIN_TRACK4_PORT                                       (GPIOA)
#define GPIO_TRACK_PIN_TRACK4_PIN                               (DL_GPIO_PIN_25)
#define GPIO_TRACK_PIN_TRACK4_IOMUX                              (IOMUX_PINCM55)
/* Defines for PIN_TRACK5: GPIOB.25 with pinCMx 56 on package pin 27 */
#define GPIO_TRACK_PIN_TRACK5_PORT                                       (GPIOB)
#define GPIO_TRACK_PIN_TRACK5_PIN                               (DL_GPIO_PIN_25)
#define GPIO_TRACK_PIN_TRACK5_IOMUX                              (IOMUX_PINCM56)
/* Defines for PIN_TRACK6: GPIOB.26 with pinCMx 57 on package pin 28 */
#define GPIO_TRACK_PIN_TRACK6_PORT                                       (GPIOB)
#define GPIO_TRACK_PIN_TRACK6_PIN                               (DL_GPIO_PIN_26)
#define GPIO_TRACK_PIN_TRACK6_IOMUX                              (IOMUX_PINCM57)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_MOTOR_init(void);
void SYSCFG_DL_PWM_SERVO_init(void);
void SYSCFG_DL_I2C_OLED_init(void);
void SYSCFG_DL_I2C_LSM6DSV16X_init(void);
void SYSCFG_DL_UART_OPENMV_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
