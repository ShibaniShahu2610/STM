################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/STM32/Workspace/PWR_STOP_RTC/Src/main.c \
D:/STM32/Workspace/PWR_STOP_RTC/Src/stm32l0xx_hal_msp.c \
D:/STM32/Workspace/PWR_STOP_RTC/Src/stm32l0xx_it.c 

OBJS += \
./Example/User/main.o \
./Example/User/stm32l0xx_hal_msp.o \
./Example/User/stm32l0xx_it.o 

C_DEPS += \
./Example/User/main.d \
./Example/User/stm32l0xx_hal_msp.d \
./Example/User/stm32l0xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Example/User/main.o: D:/STM32/Workspace/PWR_STOP_RTC/Src/main.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_STM32L0538_DISCO -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Example/User/stm32l0xx_hal_msp.o: D:/STM32/Workspace/PWR_STOP_RTC/Src/stm32l0xx_hal_msp.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_STM32L0538_DISCO -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Example/User/stm32l0xx_it.o: D:/STM32/Workspace/PWR_STOP_RTC/Src/stm32l0xx_it.c Example/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_STM32L0538_DISCO -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Example-2f-User

clean-Example-2f-User:
	-$(RM) ./Example/User/main.cyclo ./Example/User/main.d ./Example/User/main.o ./Example/User/main.su ./Example/User/stm32l0xx_hal_msp.cyclo ./Example/User/stm32l0xx_hal_msp.d ./Example/User/stm32l0xx_hal_msp.o ./Example/User/stm32l0xx_hal_msp.su ./Example/User/stm32l0xx_it.cyclo ./Example/User/stm32l0xx_it.d ./Example/User/stm32l0xx_it.o ./Example/User/stm32l0xx_it.su

.PHONY: clean-Example-2f-User
