################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Drivers/Motor\ copy/motor.o: ../Drivers/Motor\ copy/motor.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Drivers/LSM6DSV16X" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Drivers/VL53L0X" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Drivers/Motor" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Drivers/WIT" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Drivers/BNO08X_UART_RVC" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Drivers/Ultrasonic_GPIO" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Drivers/Ultrasonic_Capture" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Drivers/OLED_Hardware_I2C" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Drivers/OLED_Hardware_SPI" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Drivers/OLED_Software_I2C" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Drivers/OLED_Software_SPI" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Drivers/MPU6050" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Debug" -I"C:/ti/mspm0_sdk_2_05_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_05_01_00/source" -I"C:/Users/24778/workspace_ccstheia/oled-hardware-i2c/Drivers/MSPM0" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Drivers/Motor copy/motor.d_raw" -MT"Drivers/Motor\ copy/motor.o"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


