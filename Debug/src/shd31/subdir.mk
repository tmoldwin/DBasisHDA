################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/shd31/aheap.c \
../src/shd31/alist.c \
../src/shd31/barray.c \
../src/shd31/base.c \
../src/shd31/itemset.c \
../src/shd31/problem.c \
../src/shd31/queue.c \
../src/shd31/sample.c \
../src/shd31/shd.c \
../src/shd31/stdlib2.c \
../src/shd31/undo.c \
../src/shd31/vec.c 

OBJS += \
./src/shd31/aheap.o \
./src/shd31/alist.o \
./src/shd31/barray.o \
./src/shd31/base.o \
./src/shd31/itemset.o \
./src/shd31/problem.o \
./src/shd31/queue.o \
./src/shd31/sample.o \
./src/shd31/shd.o \
./src/shd31/stdlib2.o \
./src/shd31/undo.o \
./src/shd31/vec.o 

C_DEPS += \
./src/shd31/aheap.d \
./src/shd31/alist.d \
./src/shd31/barray.d \
./src/shd31/base.d \
./src/shd31/itemset.d \
./src/shd31/problem.d \
./src/shd31/queue.d \
./src/shd31/sample.d \
./src/shd31/shd.d \
./src/shd31/stdlib2.d \
./src/shd31/undo.d \
./src/shd31/vec.d 


# Each subdirectory must supply rules for building sources it contributes
src/shd31/%.o: ../src/shd31/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


