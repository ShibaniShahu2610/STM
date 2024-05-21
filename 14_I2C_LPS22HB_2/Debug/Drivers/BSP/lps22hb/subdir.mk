################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/lps22hb/lps22hb_reg.c 

OBJS += \
./Drivers/BSP/lps22hb/lps22hb_reg.o 

C_DEPS += \
./Drivers/BSP/lps22hb/lps22hb_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/lps22hb/%.o Drivers/BSP/lps22hb/%.su Drivers/BSP/lps22hb/%.cyclo: ../Drivers/BSP/lps22hb/%.c Drivers/BSP/lps22hb/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L053xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32/Workspace/14_I2C_LPS22HB_2/Drivers/BSP/lps22hb" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-lps22hb

clean-Drivers-2f-BSP-2f-lps22hb:
	-$(RM) ./Drivers/BSP/lps22hb/lps22hb_reg.cyclo ./Drivers/BSP/lps22hb/lps22hb_reg.d ./Drivers/BSP/lps22hb/lps22hb_reg.o ./Drivers/BSP/lps22hb/lps22hb_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-lps22hb

