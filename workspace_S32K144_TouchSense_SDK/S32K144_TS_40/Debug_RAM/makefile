################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 27
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include TS\ Project/FreeMASTER/S32xx/subdir.mk
-include TS\ Project/FreeMASTER/subdir.mk
-include TS\ Project/Peripherals/subdir.mk
-include TS\ Project/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
S32K144_TS_40.elf \

EXECUTABLES_QUOTED += \
"S32K144_TS_40.elf" \

EXECUTABLES_OS_FORMAT += \
S32K144_TS_40.elf \

SECONDARY_SIZE += \
S32K144_TS_40.siz \

SECONDARY_SIZE_QUOTED += \
"S32K144_TS_40.siz" \

SECONDARY_SIZE_OS_FORMAT += \
S32K144_TS_40.siz \


# All Target
all: warning-messages explicit-dependencies S32K144_TS_40.elf secondary-outputs

# Tool invocations
S32K144_TS_40.elf: $(OBJS) C:/Users/nxf47069/OneDrive\ -\ NXP/S32K144_TouchSense_SDK/workspace_S32K144_TouchSense_SDK/S32K144_TS_40/Project_Settings/Linker_Files/S32K144_64_ram.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #28 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "S32K144_TS_40.elf" "@S32K144_TS_40.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

S32K144_TS_40.siz: $(EXECUTABLES)
	@echo 'Executing target #29 $@'
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*/*.d ./*/*/*.d ./*/*/*/*.d  ./*/*.o ./*/*/*.o ./*/*/*/*.o  $(SECONDARY_SIZE_QUOTED) $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

