################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/UvboxManager/EventManager.c \
../Core/Src/UvboxManager/LedManager.c \
../Core/Src/UvboxManager/RotaryEncoder.c \
../Core/Src/UvboxManager/UvboxManager.c 

OBJS += \
./Core/Src/UvboxManager/EventManager.o \
./Core/Src/UvboxManager/LedManager.o \
./Core/Src/UvboxManager/RotaryEncoder.o \
./Core/Src/UvboxManager/UvboxManager.o 

C_DEPS += \
./Core/Src/UvboxManager/EventManager.d \
./Core/Src/UvboxManager/LedManager.d \
./Core/Src/UvboxManager/RotaryEncoder.d \
./Core/Src/UvboxManager/UvboxManager.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/UvboxManager/EventManager.o: ../Core/Src/UvboxManager/EventManager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F051x8 -DDEBUG -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/home/chris/Projects/Embedded/UV_LED_Driver_SW_STM32F051/UV_LED_DRIVER_SW_STM32L051/Core/Src/UvboxManager" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/UvboxManager/EventManager.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/UvboxManager/LedManager.o: ../Core/Src/UvboxManager/LedManager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F051x8 -DDEBUG -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/home/chris/Projects/Embedded/UV_LED_Driver_SW_STM32F051/UV_LED_DRIVER_SW_STM32L051/Core/Src/UvboxManager" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/UvboxManager/LedManager.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/UvboxManager/RotaryEncoder.o: ../Core/Src/UvboxManager/RotaryEncoder.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F051x8 -DDEBUG -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/home/chris/Projects/Embedded/UV_LED_Driver_SW_STM32F051/UV_LED_DRIVER_SW_STM32L051/Core/Src/UvboxManager" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/UvboxManager/RotaryEncoder.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/UvboxManager/UvboxManager.o: ../Core/Src/UvboxManager/UvboxManager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F051x8 -DDEBUG -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/home/chris/Projects/Embedded/UV_LED_Driver_SW_STM32F051/UV_LED_DRIVER_SW_STM32L051/Core/Src/UvboxManager" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/UvboxManager/UvboxManager.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

