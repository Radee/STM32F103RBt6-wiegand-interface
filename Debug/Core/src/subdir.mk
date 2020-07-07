################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/src/gpio.c \
../Core/src/main.c \
../Core/src/rcc.c \
../Core/src/tim.c \
../Core/src/wigand.c 

OBJS += \
./Core/src/gpio.o \
./Core/src/main.o \
./Core/src/rcc.o \
./Core/src/tim.o \
./Core/src/wigand.o 

C_DEPS += \
./Core/src/gpio.d \
./Core/src/main.d \
./Core/src/rcc.d \
./Core/src/tim.d \
./Core/src/wigand.d 


# Each subdirectory must supply rules for building sources it contributes
Core/src/gpio.o: ../Core/src/gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103RBTx -DSTM32 -DSTM32F1 -DDEBUG -c -I../Inc -I"C:/IDE Projects/Cube IDE/STM32F103RBt6_CMSIS_Tamplate/CMSIS/inc" -I"C:/IDE Projects/Cube IDE/STM32F103RBt6_CMSIS_Tamplate/Core/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/src/gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/src/main.o: ../Core/src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103RBTx -DSTM32 -DSTM32F1 -DDEBUG -c -I../Inc -I"C:/IDE Projects/Cube IDE/STM32F103RBt6_CMSIS_Tamplate/CMSIS/inc" -I"C:/IDE Projects/Cube IDE/STM32F103RBt6_CMSIS_Tamplate/Core/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/src/rcc.o: ../Core/src/rcc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103RBTx -DSTM32 -DSTM32F1 -DDEBUG -c -I../Inc -I"C:/IDE Projects/Cube IDE/STM32F103RBt6_CMSIS_Tamplate/CMSIS/inc" -I"C:/IDE Projects/Cube IDE/STM32F103RBt6_CMSIS_Tamplate/Core/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/src/rcc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/src/tim.o: ../Core/src/tim.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103RBTx -DSTM32 -DSTM32F1 -DDEBUG -c -I../Inc -I"C:/IDE Projects/Cube IDE/STM32F103RBt6_CMSIS_Tamplate/CMSIS/inc" -I"C:/IDE Projects/Cube IDE/STM32F103RBt6_CMSIS_Tamplate/Core/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/src/tim.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/src/wigand.o: ../Core/src/wigand.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103RBTx -DSTM32 -DSTM32F1 -DDEBUG -c -I../Inc -I"C:/IDE Projects/Cube IDE/STM32F103RBt6_CMSIS_Tamplate/CMSIS/inc" -I"C:/IDE Projects/Cube IDE/STM32F103RBt6_CMSIS_Tamplate/Core/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/src/wigand.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

