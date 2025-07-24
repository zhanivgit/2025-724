#include "Servo.h"
#include "ti_msp_dl_config.h" // SysConfig 锟斤拷锟缴碉拷头锟侥硷拷

// 锟斤拷锟斤拷使锟斤拷 TIMERA0, 通锟斤拷0, 锟斤拷锟斤拷锟斤拷 P1.5

#define SERVO_MIN_PULSE 200 
#define SERVO_MAX_PULSE 1000  
#define SERVO_PERIOD    8000 




void Servo_SetAngle(uint8_t angle)
{
    if(angle > 180) angle = 180;
    uint32_t pulse = SERVO_MIN_PULSE + ((SERVO_MAX_PULSE - SERVO_MIN_PULSE) * angle) / 180;

    DL_TimerA_setCaptureCompareValue(PWM_SERVO_INST   ,pulse, DL_TIMER_CC_0_INDEX);
}