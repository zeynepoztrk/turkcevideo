################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ethernet/W5500/w5500.c 

OBJS += \
./Core/Src/ethernet/W5500/w5500.o 

C_DEPS += \
./Core/Src/ethernet/W5500/w5500.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/ethernet/W5500/%.o Core/Src/ethernet/W5500/%.su Core/Src/ethernet/W5500/%.cyclo: ../Core/Src/ethernet/W5500/%.c Core/Src/ethernet/W5500/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-ethernet-2f-W5500

clean-Core-2f-Src-2f-ethernet-2f-W5500:
	-$(RM) ./Core/Src/ethernet/W5500/w5500.cyclo ./Core/Src/ethernet/W5500/w5500.d ./Core/Src/ethernet/W5500/w5500.o ./Core/Src/ethernet/W5500/w5500.su

.PHONY: clean-Core-2f-Src-2f-ethernet-2f-W5500

