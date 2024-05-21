################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/STM32/Workspace/PWR_STANDBY/Drivers/BSP/STM32L0538-Discovery/stm32l0538_discovery.c 

OBJS += \
./Drivers/BSP/STM32L053R8_Discovery/stm32l0538_discovery.o 

C_DEPS += \
./Drivers/BSP/STM32L053R8_Discovery/stm32l0538_discovery.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32L053R8_Discovery/stm32l0538_discovery.o: D:/STM32/Workspace/PWR_STANDBY/Drivers/BSP/STM32L0538-Discovery/stm32l0538_discovery.c Drivers/BSP/STM32L053R8_Discovery/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32L053R8_Discovery

clean-Drivers-2f-BSP-2f-STM32L053R8_Discovery:
	-$(RM) ./Drivers/BSP/STM32L053R8_Discovery/stm32l0538_discovery.cyclo ./Drivers/BSP/STM32L053R8_Discovery/stm32l0538_discovery.d ./Drivers/BSP/STM32L053R8_Discovery/stm32l0538_discovery.o ./Drivers/BSP/STM32L053R8_Discovery/stm32l0538_discovery.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32L053R8_Discovery

