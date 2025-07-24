#include "track.h"

// Manually define missing pins from SysConfig
#define GPIO_TRACK_PIN_TRACK5_PORT      (GPIOB)
#define GPIO_TRACK_PIN_TRACK5_PIN       (DL_GPIO_PIN_25)
#define GPIO_TRACK_PIN_TRACK5_IOMUX     (IOMUX_PINCM56)

#define GPIO_TRACK_PIN_TRACK6_PORT      (GPIOB)
#define GPIO_TRACK_PIN_TRACK6_PIN       (DL_GPIO_PIN_26)
#define GPIO_TRACK_PIN_TRACK6_IOMUX     (IOMUX_PINCM57)


void Track_Init(void)
{
    // Configure TRACK1 (PA23) as input with pull-up resistor
    DL_GPIO_initDigitalInputFeatures(GPIO_TRACK_PIN_TRACK1_IOMUX,
                                     DL_GPIO_INVERSION_DISABLE,
                                     DL_GPIO_RESISTOR_PULL_UP,
                                     DL_GPIO_HYSTERESIS_DISABLE,
                                     DL_GPIO_WAKEUP_DISABLE);

    // Configure TRACK2 (PB24) as input with pull-up resistor
    DL_GPIO_initDigitalInputFeatures(GPIO_TRACK_PIN_TRACK2_IOMUX,
                                     DL_GPIO_INVERSION_DISABLE,
                                     DL_GPIO_RESISTOR_PULL_UP,
                                     DL_GPIO_HYSTERESIS_DISABLE,
                                     DL_GPIO_WAKEUP_DISABLE);

    // Configure TRACK3 (PA24) as input with pull-up resistor
    DL_GPIO_initDigitalInputFeatures(GPIO_TRACK_PIN_TRACK3_IOMUX,
                                     DL_GPIO_INVERSION_DISABLE,
                                     DL_GPIO_RESISTOR_PULL_UP,
                                     DL_GPIO_HYSTERESIS_DISABLE,
                                     DL_GPIO_WAKEUP_DISABLE);

    // Configure TRACK4 (PA25) as input with pull-up resistor
    DL_GPIO_initDigitalInputFeatures(GPIO_TRACK_PIN_TRACK4_IOMUX,
                                     DL_GPIO_INVERSION_DISABLE,
                                     DL_GPIO_RESISTOR_PULL_UP,
                                     DL_GPIO_HYSTERESIS_DISABLE,
                                     DL_GPIO_WAKEUP_DISABLE);
    
    // Configure TRACK5 (PB25) as input with pull-up resistor
    DL_GPIO_initDigitalInputFeatures(GPIO_TRACK_PIN_TRACK5_IOMUX,
                                     DL_GPIO_INVERSION_DISABLE,
                                     DL_GPIO_RESISTOR_PULL_UP,
                                     DL_GPIO_HYSTERESIS_DISABLE,
                                     DL_GPIO_WAKEUP_DISABLE);

    // Configure TRACK6 (PB26) as input with pull-up resistor
    DL_GPIO_initDigitalInputFeatures(GPIO_TRACK_PIN_TRACK6_IOMUX,
                                     DL_GPIO_INVERSION_DISABLE,
                                     DL_GPIO_RESISTOR_PULL_UP,
                                     DL_GPIO_HYSTERESIS_DISABLE,
                                     DL_GPIO_WAKEUP_DISABLE);
}

uint8_t Track_Get_State(void)
{
    uint8_t state = 0;

    // Read the state of each sensor and combine into a single byte
    // A '1' on the bit means the sensor is on the line (reading LOW).
    if (DL_GPIO_readPins(GPIO_TRACK_PIN_TRACK1_PORT, GPIO_TRACK_PIN_TRACK1_PIN) == 0)
    {
        state |= (1 << 0);
    }
    if (DL_GPIO_readPins(GPIO_TRACK_PIN_TRACK2_PORT, GPIO_TRACK_PIN_TRACK2_PIN) == 0)
    {
        state |= (1 << 1);
    }
    if (DL_GPIO_readPins(GPIO_TRACK_PIN_TRACK3_PORT, GPIO_TRACK_PIN_TRACK3_PIN) == 0)
    {
        state |= (1 << 2);
    }
    if (DL_GPIO_readPins(GPIO_TRACK_PIN_TRACK4_PORT, GPIO_TRACK_PIN_TRACK4_PIN) == 0)
    {
        state |= (1 << 3);
    }
    if (DL_GPIO_readPins(GPIO_TRACK_PIN_TRACK5_PORT, GPIO_TRACK_PIN_TRACK5_PIN) == 0)
    {
        state |= (1 << 4);
    }
    if (DL_GPIO_readPins(GPIO_TRACK_PIN_TRACK6_PORT, GPIO_TRACK_PIN_TRACK6_PIN) == 0)
    {
        state |= (1 << 5);
    }

    return state;
}
