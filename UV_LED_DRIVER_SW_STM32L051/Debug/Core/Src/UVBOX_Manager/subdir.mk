################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/UVBOX_Manager/uvbox_Manager.c 

OBJS += \
./Core/Src/UVBOX_Manager/uvbox_Manager.o 

C_DEPS += \
./Core/Src/UVBOX_Manager/uvbox_Manager.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/UVBOX_Manager/uvbox_Manager.o: ../Core/Src/UVBOX_Manager/uvbox_Manager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F051x8 -DDEBUG -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/home/chris/Projects/Embedded/UV_LED_Driver_SW_STM32F051/UV_LED_DRIVER_SW_STM32L051/Core/Src/UVBOX_Manager" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/UVBOX_Manager/uvbox_Manager.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

