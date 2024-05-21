################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
D:/STM32/Workspace/PWR_STOP_RTC/SW4STM32/startup_stm32l053xx.s 

OBJS += \
./Example/SW4STM32/startup_stm32l053xx.o 

S_DEPS += \
./Example/SW4STM32/startup_stm32l053xx.d 


# Each subdirectory must supply rules for building sources it contributes
Example/SW4STM32/startup_stm32l053xx.o: D:/STM32/Workspace/PWR_STOP_RTC/SW4STM32/startup_stm32l053xx.s Example/SW4STM32/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0plus -g3 -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Example-2f-SW4STM32

clean-Example-2f-SW4STM32:
	-$(RM) ./Example/SW4STM32/startup_stm32l053xx.d ./Example/SW4STM32/startup_stm32l053xx.o

.PHONY: clean-Example-2f-SW4STM32

