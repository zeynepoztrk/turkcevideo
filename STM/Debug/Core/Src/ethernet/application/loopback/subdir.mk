################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ethernet/application/loopback/loopback.c 

OBJS += \
./Core/Src/ethernet/application/loopback/loopback.o 

C_DEPS += \
./Core/Src/ethernet/application/loopback/loopback.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/ethernet/application/loopback/%.o Core/Src/ethernet/application/loopback/%.su Core/Src/ethernet/application/loopback/%.cyclo: ../Core/Src/ethernet/application/loopback/%.c Core/Src/ethernet/application/loopback/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-ethernet-2f-application-2f-loopback

clean-Core-2f-Src-2f-ethernet-2f-application-2f-loopback:
	-$(RM) ./Core/Src/ethernet/application/loopback/loopback.cyclo ./Core/Src/ethernet/application/loopback/loopback.d ./Core/Src/ethernet/application/loopback/loopback.o ./Core/Src/ethernet/application/loopback/loopback.su

.PHONY: clean-Core-2f-Src-2f-ethernet-2f-application-2f-loopback

