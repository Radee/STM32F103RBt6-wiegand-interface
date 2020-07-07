################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/src/system_stm32f1xx.c 

OBJS += \
./CMSIS/src/system_stm32f1xx.o 

C_DEPS += \
./CMSIS/src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/src/system_stm32f1xx.o: ../CMSIS/src/system_stm32f1xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103RBTx -DSTM32 -DSTM32F1 -DDEBUG -c -I../Inc -I"C:/IDE Projects/Cube IDE/STM32F103RBt6_CMSIS_Tamplate/CMSIS/inc" -I"C:/IDE Projects/Cube IDE/STM32F103RBt6_CMSIS_Tamplate/Core/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"CMSIS/src/system_stm32f1xx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

