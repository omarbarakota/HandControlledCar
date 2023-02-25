################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO/DIO_Program.c 

OBJS += \
./MCAL/DIO/DIO_Program.o 

C_DEPS += \
./MCAL/DIO/DIO_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/DIO/%.o: ../MCAL/DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Car_Final\APP" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Car_Final\HAL\LCD" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Car_Final\MCAL\DIO" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Car_Final\HAL\L298N\includes" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Car_Final" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Car_Final\HAL\BLUETOOTH\includes" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Car_Final\MCAL\GPIO\includes" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Car_Final\MCAL\USART\includes" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Car_Final\MCAL\TIMS\includes" -I"D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\Car_Final\COMMON" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


