################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Optimized_STM32_ILI9341/subdir.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/UvboxManager/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
UV_LED_DRIVER_SW_STM32L051.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
UV_LED_DRIVER_SW_STM32L051.list \

OBJCOPY_BIN += \
UV_LED_DRIVER_SW_STM32L051.bin \


# All Target
all: UV_LED_DRIVER_SW_STM32L051.elf secondary-outputs

# Tool invocations
UV_LED_DRIVER_SW_STM32L051.elf: $(OBJS) $(USER_OBJS) /home/chris/Projects/Embedded/UV_LED_Driver_SW_STM32F051/UV_LED_DRIVER_SW_STM32L051/STM32F051K8TX_FLASH.ld
	arm-none-eabi-gcc -o "UV_LED_DRIVER_SW_STM32L051.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"/home/chris/Projects/Embedded/UV_LED_Driver_SW_STM32F051/UV_LED_DRIVER_SW_STM32L051/STM32F051K8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="UV_LED_DRIVER_SW_STM32L051.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

UV_LED_DRIVER_SW_STM32L051.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "UV_LED_DRIVER_SW_STM32L051.list"
	@echo 'Finished building: $@'
	@echo ' '

UV_LED_DRIVER_SW_STM32L051.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "UV_LED_DRIVER_SW_STM32L051.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
