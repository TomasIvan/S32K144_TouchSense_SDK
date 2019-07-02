################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../TS Project/Peripherals/adc.c" \
"../TS Project/Peripherals/flextimer.c" \
"../TS Project/Peripherals/gpio.c" \
"../TS Project/Peripherals/lpuart.c" \
"../TS Project/Peripherals/pcc.c" \
"../TS Project/Peripherals/scg.c" \
"../TS Project/Peripherals/timer.c" \

C_SRCS += \
../TS\ Project/Peripherals/adc.c \
../TS\ Project/Peripherals/flextimer.c \
../TS\ Project/Peripherals/gpio.c \
../TS\ Project/Peripherals/lpuart.c \
../TS\ Project/Peripherals/pcc.c \
../TS\ Project/Peripherals/scg.c \
../TS\ Project/Peripherals/timer.c \

OBJS_OS_FORMAT += \
./TS\ Project/Peripherals/adc.o \
./TS\ Project/Peripherals/flextimer.o \
./TS\ Project/Peripherals/gpio.o \
./TS\ Project/Peripherals/lpuart.o \
./TS\ Project/Peripherals/pcc.o \
./TS\ Project/Peripherals/scg.o \
./TS\ Project/Peripherals/timer.o \

C_DEPS_QUOTED += \
"./TS Project/Peripherals/adc.d" \
"./TS Project/Peripherals/flextimer.d" \
"./TS Project/Peripherals/gpio.d" \
"./TS Project/Peripherals/lpuart.d" \
"./TS Project/Peripherals/pcc.d" \
"./TS Project/Peripherals/scg.d" \
"./TS Project/Peripherals/timer.d" \

OBJS += \
./TS\ Project/Peripherals/adc.o \
./TS\ Project/Peripherals/flextimer.o \
./TS\ Project/Peripherals/gpio.o \
./TS\ Project/Peripherals/lpuart.o \
./TS\ Project/Peripherals/pcc.o \
./TS\ Project/Peripherals/scg.o \
./TS\ Project/Peripherals/timer.o \

OBJS_QUOTED += \
"./TS Project/Peripherals/adc.o" \
"./TS Project/Peripherals/flextimer.o" \
"./TS Project/Peripherals/gpio.o" \
"./TS Project/Peripherals/lpuart.o" \
"./TS Project/Peripherals/pcc.o" \
"./TS Project/Peripherals/scg.o" \
"./TS Project/Peripherals/timer.o" \

C_DEPS += \
./TS\ Project/Peripherals/adc.d \
./TS\ Project/Peripherals/flextimer.d \
./TS\ Project/Peripherals/gpio.d \
./TS\ Project/Peripherals/lpuart.d \
./TS\ Project/Peripherals/pcc.d \
./TS\ Project/Peripherals/scg.d \
./TS\ Project/Peripherals/timer.d \


# Each subdirectory must supply rules for building sources it contributes
TS\ Project/Peripherals/adc.o: ../TS\ Project/Peripherals/adc.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@TS Project/Peripherals/adc.args" -MMD -MP -MF"TS Project/Peripherals/adc.d" -MT"TS\ Project/Peripherals/adc.d" -o "TS Project/Peripherals/adc.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TS\ Project/Peripherals/flextimer.o: ../TS\ Project/Peripherals/flextimer.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@TS Project/Peripherals/flextimer.args" -MMD -MP -MF"TS Project/Peripherals/flextimer.d" -MT"TS\ Project/Peripherals/flextimer.d" -o "TS Project/Peripherals/flextimer.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TS\ Project/Peripherals/gpio.o: ../TS\ Project/Peripherals/gpio.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@TS Project/Peripherals/gpio.args" -MMD -MP -MF"TS Project/Peripherals/gpio.d" -MT"TS\ Project/Peripherals/gpio.d" -o "TS Project/Peripherals/gpio.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TS\ Project/Peripherals/lpuart.o: ../TS\ Project/Peripherals/lpuart.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@TS Project/Peripherals/lpuart.args" -MMD -MP -MF"TS Project/Peripherals/lpuart.d" -MT"TS\ Project/Peripherals/lpuart.d" -o "TS Project/Peripherals/lpuart.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TS\ Project/Peripherals/pcc.o: ../TS\ Project/Peripherals/pcc.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@TS Project/Peripherals/pcc.args" -MMD -MP -MF"TS Project/Peripherals/pcc.d" -MT"TS\ Project/Peripherals/pcc.d" -o "TS Project/Peripherals/pcc.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TS\ Project/Peripherals/scg.o: ../TS\ Project/Peripherals/scg.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@TS Project/Peripherals/scg.args" -MMD -MP -MF"TS Project/Peripherals/scg.d" -MT"TS\ Project/Peripherals/scg.d" -o "TS Project/Peripherals/scg.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TS\ Project/Peripherals/timer.o: ../TS\ Project/Peripherals/timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@TS Project/Peripherals/timer.args" -MMD -MP -MF"TS Project/Peripherals/timer.d" -MT"TS\ Project/Peripherals/timer.d" -o "TS Project/Peripherals/timer.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


