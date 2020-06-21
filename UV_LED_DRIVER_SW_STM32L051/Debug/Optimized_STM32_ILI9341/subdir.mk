################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/chris/Projects/Embedded/Optimized_STM32_ILI9341/ILI9341_GFX.c \
/home/chris/Projects/Embedded/Optimized_STM32_ILI9341/ILI9341_STM32_Driver.c \
/home/chris/Projects/Embedded/Optimized_STM32_ILI9341/STMBasicGui.c \
/home/chris/Projects/Embedded/Optimized_STM32_ILI9341/fade_log_seq.c 

OBJS += \
./Optimized_STM32_ILI9341/ILI9341_GFX.o \
./Optimized_STM32_ILI9341/ILI9341_STM32_Driver.o \
./Optimized_STM32_ILI9341/STMBasicGui.o \
./Optimized_STM32_ILI9341/fade_log_seq.o 

C_DEPS += \
./Optimized_STM32_ILI9341/ILI9341_GFX.d \
./Optimized_STM32_ILI9341/ILI9341_STM32_Driver.d \
./Optimized_STM32_ILI9341/STMBasicGui.d \
./Optimized_STM32_ILI9341/fade_log_seq.d 


# Each subdirectory must supply rules for building sources it contributes
Optimized_STM32_ILI9341/ILI9341_GFX.o: /home/chris/Projects/Embedded/Optimized_STM32_ILI9341/ILI9341_GFX.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F051x8 -DDEBUG -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/home/chris/Projects/Embedded/Optimized_STM32_ILI9341" -I"/home/chris/Projects/Embedded/UV_LED_Driver_SW_STM32F051/UV_LED_DRIVER_SW_STM32L051/Core/Src/UvboxManager" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Optimized_STM32_ILI9341/ILI9341_GFX.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Optimized_STM32_ILI9341/ILI9341_STM32_Driver.o: /home/chris/Projects/Embedded/Optimized_STM32_ILI9341/ILI9341_STM32_Driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F051x8 -DDEBUG -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/home/chris/Projects/Embedded/Optimized_STM32_ILI9341" -I"/home/chris/Projects/Embedded/UV_LED_Driver_SW_STM32F051/UV_LED_DRIVER_SW_STM32L051/Core/Src/UvboxManager" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Optimized_STM32_ILI9341/ILI9341_STM32_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Optimized_STM32_ILI9341/STMBasicGui.o: /home/chris/Projects/Embedded/Optimized_STM32_ILI9341/STMBasicGui.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F051x8 -DDEBUG -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/home/chris/Projects/Embedded/Optimized_STM32_ILI9341" -I"/home/chris/Projects/Embedded/UV_LED_Driver_SW_STM32F051/UV_LED_DRIVER_SW_STM32L051/Core/Src/UvboxManager" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Optimized_STM32_ILI9341/STMBasicGui.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Optimized_STM32_ILI9341/fade_log_seq.o: /home/chris/Projects/Embedded/Optimized_STM32_ILI9341/fade_log_seq.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F051x8 -DDEBUG -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I"/home/chris/Projects/Embedded/Optimized_STM32_ILI9341" -I"/home/chris/Projects/Embedded/UV_LED_Driver_SW_STM32F051/UV_LED_DRIVER_SW_STM32L051/Core/Src/UvboxManager" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Optimized_STM32_ILI9341/fade_log_seq.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

