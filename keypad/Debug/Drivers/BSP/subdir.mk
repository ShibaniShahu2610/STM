################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/key.c \
../Drivers/BSP/keypad.c 

OBJS += \
./Drivers/BSP/key.o \
./Drivers/BSP/keypad.o 

C_DEPS += \
./Drivers/BSP/key.d \
./Drivers/BSP/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/%.o Drivers/BSP/%.su Drivers/BSP/%.cyclo: ../Drivers/BSP/%.c Drivers/BSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L053xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32/Workspace/keypad/Drivers/BSP" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP

clean-Drivers-2f-BSP:
	-$(RM) ./Drivers/BSP/key.cyclo ./Drivers/BSP/key.d ./Drivers/BSP/key.o ./Drivers/BSP/key.su ./Drivers/BSP/keypad.cyclo ./Drivers/BSP/keypad.d ./Drivers/BSP/keypad.o ./Drivers/BSP/keypad.su

.PHONY: clean-Drivers-2f-BSP

