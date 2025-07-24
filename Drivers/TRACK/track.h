#ifndef __TRACK_H
#define __TRACK_H

#include "ti_msp_dl_config.h"

/**
 * @brief  Initializes the GPIO pins for the 6-channel tracking sensor.
 * @note   This function configures the pins as inputs with internal pull-up resistors.
 *         It is assumed the tracking sensor outputs a LOW signal when it detects a line.
 */
void Track_Init(void);

/**
 * @brief  Reads the state of the 6-channel tracking sensor.
 * @return A 6-bit value representing the state of the sensors.
 *         Bit 0: TRACK1 (PA23)
 *         Bit 1: TRACK2 (PB24)
 *         Bit 2: TRACK3 (PA24)
 *         Bit 3: TRACK4 (PA25)
 *         Bit 4: TRACK5 (PB25)
 *         Bit 5: TRACK6 (PB26)
 *         A '1' indicates the sensor is on the line (reading LOW).
 *         A '0' indicates the sensor is off the line (reading HIGH).
 */
uint8_t Track_Get_State(void);

/**
 * @brief  Executes one cycle of the PID line following logic.
 * @note   This function reads the sensors, calculates the error,
 *         computes the PID output, and sets the motor speeds.
 */
void Track_PID_Ctrl(void);

/**
 * @brief  Gets the last calculated PID error.
 * @return The last error value.
 */
int16_t Track_Get_Error(void);

/**
 * @brief  Gets the last calculated left motor speed.
 * @return The last left motor speed value.
 */
int16_t Track_Get_Left_Speed(void);

/**
 * @brief  Gets the last calculated right motor speed.
 * @return The last right motor speed value.
 */
int16_t Track_Get_Right_Speed(void);

#endif
