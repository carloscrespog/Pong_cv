################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Ball.cpp \
../src/Main.cpp \
../src/Record.cpp \
../src/Runtime_keys.cpp 

OBJS += \
./src/Ball.o \
./src/Main.o \
./src/Record.o \
./src/Runtime_keys.o 

CPP_DEPS += \
./src/Ball.d \
./src/Main.d \
./src/Record.d \
./src/Runtime_keys.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/opencv2 -I/usr/local/include/opencv -O0 -g3 -Wall -c -fmessage-length=0  -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


