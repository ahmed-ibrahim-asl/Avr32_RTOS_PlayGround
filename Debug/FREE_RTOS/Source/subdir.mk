################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FREE_RTOS/Source/croutine.c \
../FREE_RTOS/Source/event_groups.c \
../FREE_RTOS/Source/heap_4.c \
../FREE_RTOS/Source/list.c \
../FREE_RTOS/Source/port.c \
../FREE_RTOS/Source/queue.c \
../FREE_RTOS/Source/stream_buffer.c \
../FREE_RTOS/Source/tasks.c \
../FREE_RTOS/Source/timers.c 

OBJS += \
./FREE_RTOS/Source/croutine.o \
./FREE_RTOS/Source/event_groups.o \
./FREE_RTOS/Source/heap_4.o \
./FREE_RTOS/Source/list.o \
./FREE_RTOS/Source/port.o \
./FREE_RTOS/Source/queue.o \
./FREE_RTOS/Source/stream_buffer.o \
./FREE_RTOS/Source/tasks.o \
./FREE_RTOS/Source/timers.o 

C_DEPS += \
./FREE_RTOS/Source/croutine.d \
./FREE_RTOS/Source/event_groups.d \
./FREE_RTOS/Source/heap_4.d \
./FREE_RTOS/Source/list.d \
./FREE_RTOS/Source/port.d \
./FREE_RTOS/Source/queue.d \
./FREE_RTOS/Source/stream_buffer.d \
./FREE_RTOS/Source/tasks.d \
./FREE_RTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FREE_RTOS/Source/%.o: ../FREE_RTOS/Source/%.c FREE_RTOS/Source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


