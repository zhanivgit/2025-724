#include "track.h"
#include "motor.h"
// Manually define missing pins from SysConfig
#define GPIO_TRACK_PIN_TRACK5_PORT      (GPIOB)
#define GPIO_TRACK_PIN_TRACK5_PIN       (DL_GPIO_PIN_25)
#define GPIO_TRACK_PIN_TRACK5_IOMUX     (IOMUX_PINCM56)

#define GPIO_TRACK_PIN_TRACK6_PORT      (GPIOB)
#define GPIO_TRACK_PIN_TRACK6_PIN       (DL_GPIO_PIN_26)
#define GPIO_TRACK_PIN_TRACK6_IOMUX     (IOMUX_PINCM57)

// PID Controller parameters
static float Kp = 0.5f;  // Proportional gain
static float Ki = 0.0f;  // Integral gain
static float Kd = 0.2f;  // Derivative gain

static int16_t error = 0;
static int16_t last_error = 0;
static int32_t integral = 0;
static int16_t derivative = 0;

// Static variables to store motor speeds for debugging
static int16_t g_left_speed = 0;
static int16_t g_right_speed = 0;

// Sensor weights for error calculation (from left to right)
const int8_t weights[] = {-10, -5, -1, 1, 5, 10};

void Track_Init(void)
{
    // Configure TRACK1 (PA23) as input with pull-up resistor
    DL_GPIO_initDigitalInputFeatures(GPIO_TRACK_PIN_TRACK1_IOMUX, DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP, DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    // Configure TRACK2 (PB24) as input with pull-up resistor
    DL_GPIO_initDigitalInputFeatures(GPIO_TRACK_PIN_TRACK2_IOMUX, DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP, DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    // Configure TRACK3 (PA24) as input with pull-up resistor
    DL_GPIO_initDigitalInputFeatures(GPIO_TRACK_PIN_TRACK3_IOMUX, DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP, DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    // Configure TRACK4 (PA25) as input with pull-up resistor
    DL_GPIO_initDigitalInputFeatures(GPIO_TRACK_PIN_TRACK4_IOMUX, DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP, DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    // Configure TRACK5 (PB25) as input with pull-up resistor
    DL_GPIO_initDigitalInputFeatures(GPIO_TRACK_PIN_TRACK5_IOMUX, DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP, DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    // Configure TRACK6 (PB26) as input with pull-up resistor
    DL_GPIO_initDigitalInputFeatures(GPIO_TRACK_PIN_TRACK6_IOMUX, DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP, DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
}

uint8_t Track_Get_State(void)
{
    uint8_t state = 0;
    if (DL_GPIO_readPins(GPIO_TRACK_PIN_TRACK1_PORT, GPIO_TRACK_PIN_TRACK1_PIN) == 0) state |= (1 << 0);
    if (DL_GPIO_readPins(GPIO_TRACK_PIN_TRACK2_PORT, GPIO_TRACK_PIN_TRACK2_PIN) == 0) state |= (1 << 1);
    if (DL_GPIO_readPins(GPIO_TRACK_PIN_TRACK3_PORT, GPIO_TRACK_PIN_TRACK3_PIN) == 0) state |= (1 << 2);
    if (DL_GPIO_readPins(GPIO_TRACK_PIN_TRACK4_PORT, GPIO_TRACK_PIN_TRACK4_PIN) == 0) state |= (1 << 3);
    if (DL_GPIO_readPins(GPIO_TRACK_PIN_TRACK5_PORT, GPIO_TRACK_PIN_TRACK5_PIN) == 0) state |= (1 << 4);
    if (DL_GPIO_readPins(GPIO_TRACK_PIN_TRACK6_PORT, GPIO_TRACK_PIN_TRACK6_PIN) == 0) state |= (1 << 5);
    return state;
}

void Track_PID_Ctrl(void)
{
    uint8_t state = Track_Get_State();
    int32_t weighted_sum = 0;
    uint8_t active_sensors = 0;

    for (int i = 0; i < 6; i++) {
        if ((state >> i) & 0x01) {
            weighted_sum += weights[i];
            active_sensors++;
        }
    }

    if (active_sensors > 0) {
        error = weighted_sum; // No need to average if weights are tuned
    } else {
        // If no sensors are on the line, use the last error
        // This helps handle line gaps or sharp turns
        error = last_error;
    }

    integral += error;
    // Integral windup prevention
    if (integral > 100) integral = 100;
    if (integral < -100) integral = -100;

    derivative = error - last_error;
    last_error = error;

    int16_t pid_output = (int16_t)(Kp * error + Ki * integral + Kd * derivative);

    int16_t base_speed = 20; // Base speed for the motors
    int16_t left_speed = base_speed - pid_output;
    int16_t right_speed = base_speed + pid_output;

    // Clamp motor speeds to a valid range (e.g., 0-30)
    if (left_speed > 30) left_speed = 30;
    if (left_speed < 0) left_speed = 0;
    if (right_speed > 30) right_speed = 30;
    if (right_speed < 0) right_speed = 0;

    // Store speeds for debugging
    g_left_speed = left_speed;
    g_right_speed = right_speed;

    Set_Speed(0, g_left_speed);  // Assuming 0 is the left motor
    Set_Speed(1, g_right_speed); // Assuming 1 is the right motor
}

int16_t Track_Get_Error(void)
{
    return error;
}

int16_t Track_Get_Left_Speed(void)
{
    return g_left_speed;
}

int16_t Track_Get_Right_Speed(void)
{
    return g_right_speed;
}
