################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../src \
../src/drivers


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../src/ATmega2560.c \
../src/controller.c \
../src/drivers/adc.c \
../src/drivers/can.c \
../src/drivers/dac.c \
../src/drivers/ir.c \
../src/drivers/MCP2515.c \
../src/drivers/motor.c \
../src/drivers/pwm.c \
../src/drivers/servo.c \
../src/drivers/solenoid.c \
../src/drivers/spi.c \
../src/drivers/TWI_Master.c \
../src/drivers/uart.c \
../src/drivers/ultrasound.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
src/ATmega2560.o \
src/controller.o \
src/drivers/adc.o \
src/drivers/can.o \
src/drivers/dac.o \
src/drivers/ir.o \
src/drivers/MCP2515.o \
src/drivers/motor.o \
src/drivers/pwm.o \
src/drivers/servo.o \
src/drivers/solenoid.o \
src/drivers/spi.o \
src/drivers/TWI_Master.o \
src/drivers/uart.o \
src/drivers/ultrasound.o

OBJS_AS_ARGS +=  \
src/ATmega2560.o \
src/controller.o \
src/drivers/adc.o \
src/drivers/can.o \
src/drivers/dac.o \
src/drivers/ir.o \
src/drivers/MCP2515.o \
src/drivers/motor.o \
src/drivers/pwm.o \
src/drivers/servo.o \
src/drivers/solenoid.o \
src/drivers/spi.o \
src/drivers/TWI_Master.o \
src/drivers/uart.o \
src/drivers/ultrasound.o

C_DEPS +=  \
src/ATmega2560.d \
src/controller.d \
src/drivers/adc.d \
src/drivers/can.d \
src/drivers/dac.d \
src/drivers/ir.d \
src/drivers/MCP2515.d \
src/drivers/motor.d \
src/drivers/pwm.d \
src/drivers/servo.d \
src/drivers/solenoid.d \
src/drivers/spi.d \
src/drivers/TWI_Master.d \
src/drivers/uart.d \
src/drivers/ultrasound.d

C_DEPS_AS_ARGS +=  \
src/ATmega2560.d \
src/controller.d \
src/drivers/adc.d \
src/drivers/can.d \
src/drivers/dac.d \
src/drivers/ir.d \
src/drivers/MCP2515.d \
src/drivers/motor.d \
src/drivers/pwm.d \
src/drivers/servo.d \
src/drivers/solenoid.d \
src/drivers/spi.d \
src/drivers/TWI_Master.d \
src/drivers/uart.d \
src/drivers/ultrasound.d

OUTPUT_FILE_PATH +=ATmega2560.elf

OUTPUT_FILE_PATH_AS_ARGS +=ATmega2560.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler































src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega2560 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/drivers/%.o: ../src/drivers/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega2560 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="ATmega2560.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mrelax -mmcu=atmega2560  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "ATmega2560.elf" "ATmega2560.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "ATmega2560.elf" "ATmega2560.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "ATmega2560.elf" > "ATmega2560.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "ATmega2560.elf" "ATmega2560.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-size.exe" "ATmega2560.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "ATmega2560.elf" "ATmega2560.a" "ATmega2560.hex" "ATmega2560.lss" "ATmega2560.eep" "ATmega2560.map" "ATmega2560.srec" "ATmega2560.usersignatures"
	