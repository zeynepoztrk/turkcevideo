################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ethernet/socket.c \
../Core/Src/ethernet/wizchip_conf.c 

OBJS += \
./Core/Src/ethernet/socket.o \
./Core/Src/ethernet/wizchip_conf.o 

C_DEPS += \
./Core/Src/ethernet/socket.d \
./Core/Src/ethernet/wizchip_conf.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/ethernet/%.o Core/Src/ethernet/%.su Core/Src/ethernet/%.cyclo: ../Core/Src/ethernet/%.c Core/Src/ethernet/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-ethernet

clean-Core-2f-Src-2f-ethernet:
	-$(RM) ./Core/Src/ethernet/socket.cyclo ./Core/Src/ethernet/socket.d ./Core/Src/ethernet/socket.o ./Core/Src/ethernet/socket.su ./Core/Src/ethernet/wizchip_conf.cyclo ./Core/Src/ethernet/wizchip_conf.d ./Core/Src/ethernet/wizchip_conf.o ./Core/Src/ethernet/wizchip_conf.su

.PHONY: clean-Core-2f-Src-2f-ethernet

