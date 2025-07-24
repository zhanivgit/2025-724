/*
 * Copyright (c) 2021, Texas Instruments Incorporated
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

#include "ti_msp_dl_config.h"
#include "main.h"
#include "stdio.h"
#include "track.h"

uint8_t oled_buffer[32];
int16_t rxbuf = 0, cx = 160;
int16_t baseSpeed = 15;
int16_t SpeedL = 0, SpeedR = 0,angle=90;
float Kp = 0.1;
int i=0; 
void Motor_Ctrl(void);
int main(void)
{
    SYSCFG_DL_init();
    SysTick_Init();
    NVIC_ClearPendingIRQ(UART_OPENMV_INST_INT_IRQN);
    NVIC_EnableIRQ(UART_OPENMV_INST_INT_IRQN);
    //uint8_t t=' ';
    LSM6DSV16X_Init();

    // MPU6050_Init();
    OLED_Init();
    Track_Init();
   
    // while(DL_GPIO_readPins(GPIO_BUTTON_PORT, GPIO_BUTTON_PIN_S2_PIN));
    // DL_UART_transmitDataBlocking(UART_OPENMV_INST, 'S');
    // uint8_t angle=90;
     
    /* Don't remove this! */
    Interrupt_Init();
    OLED_Clear();
    Motor_On();
    buzzer_on();
    delay_ms(1000);
    buzzer_off();
    // DL_TimerA_startCounter(PWM_SERVO_INST);

    // OLED_ShowString(0,7,(uint8_t *)"LSM6DSV16X Demo",8);

    // OLED_ShowString(0,0,(uint8_t *)"Pitch",8);
    // OLED_ShowString(0,2,(uint8_t *)" Roll",8);
    // OLED_ShowString(0,4,(uint8_t *)"  Yaw",8);

    // OLED_ShowString(16*6,3,(uint8_t *)"Accel",8);
    // OLED_ShowString(17*6,4,(uint8_t *)"Gyro",8);
    while (1) 
    {
        Track_PID_Ctrl();

        // Clear previous display
        OLED_ShowString(0, 0, (uint8_t *)"                ", 16);
        OLED_ShowString(0, 2, (uint8_t *)"                ", 16);

        // Display Error on line 0
        OLED_ShowString(0, 0, (uint8_t *)"Err:", 16);
        sprintf((char *)oled_buffer, "%-4d", Track_Get_Error());
        OLED_ShowString(8*4, 0, oled_buffer, 16);

        // Display Speeds on line 2
        OLED_ShowString(0, 2, (uint8_t *)"L:", 16);
        sprintf((char *)oled_buffer, "%-3d", Track_Get_Left_Speed());
        OLED_ShowString(8*2, 2, oled_buffer, 16);

        OLED_ShowString(8*7, 2, (uint8_t *)"R:", 16);
        sprintf((char *)oled_buffer, "%-3d", Track_Get_Right_Speed());
        OLED_ShowString(8*9, 2, oled_buffer, 16);
        
        delay_ms(20); // PID control loop should run reasonably fast
    }
}
void Motor_Ctrl(void)
{
    SpeedL = baseSpeed - (cx - 160)*Kp;
    SpeedR = baseSpeed + (cx - 160)*Kp;
    //angle=180*cx/320;
    if(SpeedL > 30)
        SpeedL = 30;
    else if(SpeedL < 0)
        SpeedL = 0;

    if(SpeedR > 30)
        SpeedR = 30;
    else if(SpeedR < 0)
        SpeedR = 0;

    Set_Speed(0, SpeedL);
    Set_Speed(1, SpeedR);
    //Servo_SetAngle(angle);
}
void UART_OPENMV_INST_IRQHandler(void)
{
    uint8_t gData;
    angle++;
    switch (DL_UART_Main_getPendingInterrupt(UART_OPENMV_INST)) {
        case DL_UART_MAIN_IIDX_RX:
            gData = DL_UART_Main_receiveData(UART_OPENMV_INST);
            if(gData == 'S')
            {
                Motor_Off();
            }
            else if(gData == '#')
                rxbuf = 0;
            else if(gData == '$')
                cx = rxbuf;
            else
                rxbuf = rxbuf*10 + (gData - '0');
            break;
        default:
            break;
    }
}
