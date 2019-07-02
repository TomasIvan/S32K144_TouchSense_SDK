################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../TS Project/ets.c" \
"../TS Project/filter.c" \
"../TS Project/main.c" \
"../TS Project/power_mode.c" \
"../TS Project/slider.c" \

C_SRCS += \
../TS\ Project/ets.c \
../TS\ Project/filter.c \
../TS\ Project/main.c \
../TS\ Project/power_mode.c \
../TS\ Project/slider.c \

OBJS_OS_FORMAT += \
./TS\ Project/ets.o \
./TS\ Project/filter.o \
./TS\ Project/main.o \
./TS\ Project/power_mode.o \
./TS\ Project/slider.o \

C_DEPS_QUOTED += \
"./TS Project/ets.d" \
"./TS Project/filter.d" \
"./TS Project/main.d" \
"./TS Project/power_mode.d" \
"./TS Project/slider.d" \

OBJS += \
./TS\ Project/ets.o \
./TS\ Project/filter.o \
./TS\ Project/main.o \
./TS\ Project/power_mode.o \
./TS\ Project/slider.o \

OBJS_QUOTED += \
"./TS Project/ets.o" \
"./TS Project/filter.o" \
"./TS Project/main.o" \
"./TS Project/power_mode.o" \
"./TS Project/slider.o" \

C_DEPS += \
./TS\ Project/ets.d \
./TS\ Project/filter.d \
./TS\ Project/main.d \
./TS\ Project/power_mode.d \
./TS\ Project/slider.d \


# Each subdirectory must supply rules for building sources it contributes
TS\ Project/ets.o: ../TS\ Project/ets.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@TS Project/ets.args" -MMD -MP -MF"TS Project/ets.d" -MT"TS\ Project/ets.d" -o "TS Project/ets.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TS\ Project/filter.o: ../TS\ Project/filter.c
	@echo 'Building file: $<'
	@echo 'Executing target #24 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@TS Project/filter.args" -MMD -MP -MF"TS Project/filter.d" -MT"TS\ Project/filter.d" -o "TS Project/filter.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TS\ Project/main.o: ../TS\ Project/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@TS Project/main.args" -MMD -MP -MF"TS Project/main.d" -MT"TS\ Project/main.d" -o "TS Project/main.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TS\ Project/power_mode.o: ../TS\ Project/power_mode.c
	@echo 'Building file: $<'
	@echo 'Executing target #26 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@TS Project/power_mode.args" -MMD -MP -MF"TS Project/power_mode.d" -MT"TS\ Project/power_mode.d" -o "TS Project/power_mode.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TS\ Project/slider.o: ../TS\ Project/slider.c
	@echo 'Building file: $<'
	@echo 'Executing target #27 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@TS Project/slider.args" -MMD -MP -MF"TS Project/slider.d" -MT"TS\ Project/slider.d" -o "TS Project/slider.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


