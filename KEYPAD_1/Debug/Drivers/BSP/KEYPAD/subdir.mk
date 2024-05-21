################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/KEYPAD/MY_Keypad4x4.c 

OBJS += \
./Drivers/BSP/KEYPAD/MY_Keypad4x4.o 

C_DEPS += \
./Drivers/BSP/KEYPAD/MY_Keypad4x4.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/KEYPAD/%.o Drivers/BSP/KEYPAD/%.su Drivers/BSP/KEYPAD/%.cyclo: ../Drivers/BSP/KEYPAD/%.c Drivers/BSP/KEYPAD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L053xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32/Workspace/KEYPAD_1/Drivers/BSP/KEYPAD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-KEYPAD

clean-Drivers-2f-BSP-2f-KEYPAD:
	-$(RM) ./Drivers/BSP/KEYPAD/MY_Keypad4x4.cyclo ./Drivers/BSP/KEYPAD/MY_Keypad4x4.d ./Drivers/BSP/KEYPAD/MY_Keypad4x4.o ./Drivers/BSP/KEYPAD/MY_Keypad4x4.su

.PHONY: clean-Drivers-2f-BSP-2f-KEYPAD

