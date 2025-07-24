#include "motor.h"

void Motor_On(void)
{
    DL_GPIO_setPins(GPIO_MOTOR_PIN_FSTBY_PORT, GPIO_MOTOR_PIN_FSTBY_PIN);
    DL_Timer_startCounter(PWM_MOTOR_INST);
}

void Motor_Off(void)
{
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FSTBY_PORT, GPIO_MOTOR_PIN_FSTBY_PIN);
   

    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL1_PORT, GPIO_MOTOR_PIN_FL1_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL2_PORT, GPIO_MOTOR_PIN_FL2_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR1_PORT, GPIO_MOTOR_PIN_FR1_PIN);
    DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR2_PORT, GPIO_MOTOR_PIN_FR2_PIN);

   
}

void Set_Speed(uint8_t side, int8_t duty)
{
    uint32_t compareValue = 0;
    if(side == 0)
    {
        if(duty < 0)
        {
            compareValue = 8000 - 8000 * (duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_0_INDEX);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_FL1_PORT, GPIO_MOTOR_PIN_FL1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL2_PORT, GPIO_MOTOR_PIN_FL2_PIN);

        }
        else if(duty > 0)
        {
            compareValue =  8000 - 8000 * (duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_0_INDEX);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL1_PORT, GPIO_MOTOR_PIN_FL1_PIN);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_FL2_PORT, GPIO_MOTOR_PIN_FL2_PIN);

          
        }
        else 
        {
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FL1_PORT, GPIO_MOTOR_PIN_FL1_PIN);
            
           
        }
    }
    else
    {
        if(duty < 0)
        {
            compareValue =  8000 - 8000 * (duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue,  GPIO_PWM_MOTOR_C0_IDX);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_FR1_PORT, GPIO_MOTOR_PIN_FR1_PIN);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR2_PORT, GPIO_MOTOR_PIN_FR2_PIN);

           
        }
        else if(duty > 0)
        {
            compareValue =  8000 - 8000 * (duty/100.0);
            DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue,  GPIO_PWM_MOTOR_C1_IDX);
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR1_PORT, GPIO_MOTOR_PIN_FR1_PIN);
            DL_GPIO_setPins(GPIO_MOTOR_PIN_FR2_PORT, GPIO_MOTOR_PIN_FR2_PIN);

           
        }
        else 
        {
            DL_GPIO_clearPins(GPIO_MOTOR_PIN_FR1_PORT, GPIO_MOTOR_PIN_FR1_PIN);
            
           
        }
    }
}