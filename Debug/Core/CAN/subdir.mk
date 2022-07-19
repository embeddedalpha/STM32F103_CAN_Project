################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/CAN/CAN.c 

OBJS += \
./Core/CAN/CAN.o 

C_DEPS += \
./Core/CAN/CAN.d 


# Each subdirectory must supply rules for building sources it contributes
Core/CAN/%.o Core/CAN/%.su: ../Core/CAN/%.c Core/CAN/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -IC:/Users/Kunal/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc -IC:/Users/Kunal/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -IC:/Users/Kunal/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Device/ST/STM32F1xx/Include -IC:/Users/Kunal/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Include -I"C:/Users/Kunal/STM32CubeIDE/STM32F103_Workspace/STM32F103_CAN_Project/Core/CAN" -I"C:/Users/Kunal/STM32CubeIDE/STM32F103_Workspace/STM32F103_CAN_Project/Core/Console" -I"C:/Users/Kunal/STM32CubeIDE/STM32F103_Workspace/STM32F103_CAN_Project/Core/GPIO" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-CAN

clean-Core-2f-CAN:
	-$(RM) ./Core/CAN/CAN.d ./Core/CAN/CAN.o ./Core/CAN/CAN.su

.PHONY: clean-Core-2f-CAN

