################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Buzzer/Buzzer_Prog.c 

OBJS += \
./HAL/Buzzer/Buzzer_Prog.o 

C_DEPS += \
./HAL/Buzzer/Buzzer_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Buzzer/%.o: ../HAL/Buzzer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"G:\Embedded System\Workspace\Timer_project\HAL\Buzzer" -I"G:\Embedded System\Workspace\Timer_project\HAL\L298N" -I"G:\Embedded System\Workspace\Timer_project\MCAL\WDT" -I"G:\Embedded System\Workspace\Timer_project\MCAL\DIO" -I"G:\Embedded System\Workspace\Timer_project\HAL\KeyPad" -I"G:\Embedded System\Workspace\Timer_project\MCAL\TIMER1" -I"G:\Embedded System\Workspace\Timer_project\MCAL\TIMER0" -I"G:\Embedded System\Workspace\Timer_project\HAL\KeyPad" -I"G:\Embedded System\Workspace\Timer_project\HAL\LCD" -I"G:\Embedded System\Workspace\Timer_project\HAL\LED" -I"G:\Embedded System\Workspace\Timer_project\HAL\LM35" -I"G:\Embedded System\Workspace\Timer_project\HAL\PB" -I"G:\Embedded System\Workspace\Timer_project\HAL\SSD" -I"G:\Embedded System\Workspace\Timer_project\LIB" -I"G:\Embedded System\Workspace\Timer_project\MCAL\ADC" -I"G:\Embedded System\Workspace\Timer_project\MCAL\DIO" -I"G:\Embedded System\Workspace\Timer_project\MCAL\EXTINT" -I"G:\Embedded System\Workspace\Timer_project\MCAL\GIE" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


