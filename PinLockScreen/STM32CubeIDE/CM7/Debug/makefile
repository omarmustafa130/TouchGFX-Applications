################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Utilities/subdir.mk
-include Middlewares/LibJPEG/subdir.mk
-include Middlewares/FreeRTOS/subdir.mk
-include Middlewares/FatFs/subdir.mk
-include Drivers/STM32H7xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Application/User/gui/subdir.mk
-include Application/User/generated/subdir.mk
-include Application/User/TouchGFX/target/generated/subdir.mk
-include Application/User/TouchGFX/target/subdir.mk
-include Application/User/TouchGFX/App/subdir.mk
-include Application/User/Startup/subdir.mk
-include Application/User/LIBJPEG/App/subdir.mk
-include Application/User/FATFS/Target/subdir.mk
-include Application/User/FATFS/App/subdir.mk
-include Application/User/Core/Inc/subdir.mk
-include Application/User/Core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Riverdi_70STM32H7_CM7
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Riverdi_70STM32H7_CM7.elf \

MAP_FILES += \
Riverdi_70STM32H7_CM7.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Riverdi_70STM32H7_CM7.list \

OBJCOPY_HEX += \
Riverdi_70STM32H7_CM7.hex \

OBJCOPY_BIN += \
Riverdi_70STM32H7_CM7.bin \


# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: Riverdi_70STM32H7_CM7.elf secondary-outputs

# Tool invocations
Riverdi_70STM32H7_CM7.elf Riverdi_70STM32H7_CM7.map: $(OBJS) $(USER_OBJS) C:\TouchGFXProjects\MyApplication_1\STM32CubeIDE\CM7\STM32H747XIHX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "Riverdi_70STM32H7_CM7.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\TouchGFXProjects\MyApplication_1\STM32CubeIDE\CM7\STM32H747XIHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Riverdi_70STM32H7_CM7.map" -Wl,--gc-sections -static -LC:/TouchGFXProjects/Riverdi_70STM32H7/CM7/Middlewares/ST/touchgfx/lib/core/cortex_m7/gcc -LC:/TouchGFXProjects/Riverdi_70STM32H7_V2/CM7/Middlewares/ST/touchgfx/lib/core/cortex_m7/gcc -LC:/TouchGFXProjects/MyApplication_95/CM7/Middlewares/ST/touchgfx/lib/core/cortex_m7/gcc -LC:/TouchGFXProjects/MyApplication_1/CM7/Middlewares/ST/touchgfx/lib/core/cortex_m7/gcc --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Riverdi_70STM32H7_CM7.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Riverdi_70STM32H7_CM7.list"
	@echo 'Finished building: $@'
	@echo ' '

Riverdi_70STM32H7_CM7.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Riverdi_70STM32H7_CM7.hex"
	@echo 'Finished building: $@'
	@echo ' '

Riverdi_70STM32H7_CM7.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Riverdi_70STM32H7_CM7.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Riverdi_70STM32H7_CM7.bin Riverdi_70STM32H7_CM7.elf Riverdi_70STM32H7_CM7.hex Riverdi_70STM32H7_CM7.list Riverdi_70STM32H7_CM7.map default.size.stdout
	-@echo ' '

post-build:
	arm-none-eabi-objcopy -O binary  --only-section=ExtFlashSection Riverdi_70STM32H7_CM7.elf qspi.bin
	arm-none-eabi-objcopy -O binary  --remove-section=BufferSection --remove-section=TouchGFX_Framebuffer  --remove-section=ExtFlashSection Riverdi_70STM32H7_CM7.elf flash.bin
	arm-none-eabi-objcopy  Riverdi_70STM32H7_CM7.elf Riverdi_70STM32H7_CM7_NOQSPI.elf  --remove-section=BufferSection --remove-section=TouchGFX_Framebuffer  --remove-section=ExtFlashSection
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified post-build

-include ../makefile.targets
