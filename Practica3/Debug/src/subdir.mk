################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Agenda.cpp \
../src/Contacto.cpp \
../src/GestorDBFichero.cpp \
../src/GestorDBInterfaz.cpp \
../src/MenuTerminal.cpp \
../src/Practica3.cpp 

OBJS += \
./src/Agenda.o \
./src/Contacto.o \
./src/GestorDBFichero.o \
./src/GestorDBInterfaz.o \
./src/MenuTerminal.o \
./src/Practica3.o 

CPP_DEPS += \
./src/Agenda.d \
./src/Contacto.d \
./src/GestorDBFichero.d \
./src/GestorDBInterfaz.d \
./src/MenuTerminal.d \
./src/Practica3.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


