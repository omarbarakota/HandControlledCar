################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/USART/source/USART.c 

OBJS += \
./MCAL/USART/source/USART.o 

C_DEPS += \
./MCAL/USART/source/USART.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/USART/source/%.o: ../MCAL/USART/source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Glove_Final\HAL\BLUETOOTH\includes" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Glove_Final\COMMON" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Glove_Final\MCAL\ADC\includes" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Glove_Final\MCAL\GPIO\includes" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Glove_Final\MCAL\USART\includes" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Glove_Final\HAL\FLEX\includes" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Glove_Final\APP" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


