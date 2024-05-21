################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Bsp/components/sht21/sht2x_for_stm32_hal.c 

OBJS += \
./Drivers/Bsp/components/sht21/sht2x_for_stm32_hal.o 

C_DEPS += \
./Drivers/Bsp/components/sht21/sht2x_for_stm32_hal.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Bsp/components/sht21/%.o Drivers/Bsp/components/sht21/%.su Drivers/Bsp/components/sht21/%.cyclo: ../Drivers/Bsp/components/sht21/%.c Drivers/Bsp/components/sht21/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L053xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32/Workspace/13_I2C_SHT21_RTC/Drivers/Bsp/components/sht21" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-Bsp-2f-components-2f-sht21

clean-Drivers-2f-Bsp-2f-components-2f-sht21:
	-$(RM) ./Drivers/Bsp/components/sht21/sht2x_for_stm32_hal.cyclo ./Drivers/Bsp/components/sht21/sht2x_for_stm32_hal.d ./Drivers/Bsp/components/sht21/sht2x_for_stm32_hal.o ./Drivers/Bsp/components/sht21/sht2x_for_stm32_hal.su

.PHONY: clean-Drivers-2f-Bsp-2f-components-2f-sht21

