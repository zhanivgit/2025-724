
#include "ti_msp_dl_config.h"
void buzzer_on()
    {
    DL_GPIO_setPins(GPIO_BUZZER_PORT,GPIO_BUZZER_PIN_buzzer_PIN);
    }
void buzzer_off()
    {
        DL_GPIO_setPins(GPIO_BUZZER_PORT,GPIO_BUZZER_PIN_buzzer_PIN);
    }