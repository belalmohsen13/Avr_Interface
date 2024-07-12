################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Snack_Effect.lss \

FLASH_IMAGE += \
Snack_Effect.hex \

EEPROM_IMAGE += \
Snack_Effect.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Snack_Effect.elf secondary-outputs

# Tool invocations
Snack_Effect.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Snack_Effect.map -mmcu=atmega32 -o "Snack_Effect.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Snack_Effect.lss: Snack_Effect.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Snack_Effect.elf  >"Snack_Effect.lss"
	@echo 'Finished building: $@'
	@echo ' '

Snack_Effect.hex: Snack_Effect.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Snack_Effect.elf  "Snack_Effect.hex"
	@echo 'Finished building: $@'
	@echo ' '

Snack_Effect.eep: Snack_Effect.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Snack_Effect.elf  "Snack_Effect.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Snack_Effect.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Snack_Effect.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Snack_Effect.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
