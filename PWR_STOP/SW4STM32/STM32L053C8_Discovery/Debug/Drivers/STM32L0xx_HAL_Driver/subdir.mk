################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal.c \
D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_adc.c \
D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_adc_ex.c \
D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_cortex.c \
D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_dma.c \
D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash.c \
D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash_ex.c \
D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_gpio.c \
D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr.c \
D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr_ex.c \
D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc.c \
D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc_ex.c \
D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_spi.c 

OBJS += \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal.o \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc.o \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc_ex.o \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_cortex.o \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_dma.o \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash.o \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash_ex.o \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_gpio.o \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr.o \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr_ex.o \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc.o \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc_ex.o \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_spi.o 

C_DEPS += \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal.d \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc.d \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc_ex.d \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_cortex.d \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_dma.d \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash.d \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash_ex.d \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_gpio.d \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr.d \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr_ex.d \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc.d \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc_ex.d \
./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_spi.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal.o: D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal.c Drivers/STM32L0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc.o: D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_adc.c Drivers/STM32L0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc_ex.o: D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_adc_ex.c Drivers/STM32L0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_cortex.o: D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_cortex.c Drivers/STM32L0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_dma.o: D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_dma.c Drivers/STM32L0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash.o: D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash.c Drivers/STM32L0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash_ex.o: D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash_ex.c Drivers/STM32L0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_gpio.o: D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_gpio.c Drivers/STM32L0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr.o: D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr.c Drivers/STM32L0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr_ex.o: D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr_ex.c Drivers/STM32L0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc.o: D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc.c Drivers/STM32L0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc_ex.o: D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc_ex.c Drivers/STM32L0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_spi.o: D:/STM32/Workspace/PWR_STOP/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_spi.c Drivers/STM32L0xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32L053xx -DUSE_HAL_DRIVER -c -I../../../Inc -I../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../../../Drivers/STM32L0xx_HAL_Driver/Inc -I../../../Drivers/BSP/STM32L0538-Discovery -I../../../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-STM32L0xx_HAL_Driver

clean-Drivers-2f-STM32L0xx_HAL_Driver:
	-$(RM) ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal.cyclo ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal.d ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal.o ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal.su ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc.cyclo ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc.d ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc.o ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc.su ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc_ex.cyclo ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc_ex.d ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc_ex.o ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_adc_ex.su ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_cortex.cyclo ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_cortex.d ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_cortex.o ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_cortex.su ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_dma.cyclo ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_dma.d ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_dma.o ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_dma.su ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash.cyclo ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash.d ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash.o ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash.su ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash_ex.cyclo ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash_ex.d ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash_ex.o ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_flash_ex.su ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_gpio.cyclo ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_gpio.d ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_gpio.o ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_gpio.su ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr.cyclo ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr.d ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr.o ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr.su ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr_ex.cyclo ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr_ex.d ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr_ex.o ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_pwr_ex.su ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc.cyclo ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc.d ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc.o ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc.su ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc_ex.cyclo ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc_ex.d ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc_ex.o ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_rcc_ex.su ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_spi.cyclo ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_spi.d ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_spi.o ./Drivers/STM32L0xx_HAL_Driver/stm32l0xx_hal_spi.su

.PHONY: clean-Drivers-2f-STM32L0xx_HAL_Driver

