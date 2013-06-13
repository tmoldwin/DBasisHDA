################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Implication.cpp \
../src/Main.cpp \
../src/SetOperations.cpp \
../src/Table.cpp 

OBJS += \
./src/Implication.o \
./src/Main.o \
./src/SetOperations.o \
./src/Table.o 

CPP_DEPS += \
./src/Implication.d \
./src/Main.d \
./src/SetOperations.d \
./src/Table.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/ulno/Desktop/work/eclipse/misc/DBasisHDA/shd31" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


