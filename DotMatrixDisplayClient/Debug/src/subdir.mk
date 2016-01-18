################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DisplayCommunication.cpp \
../src/DisplayPosition.cpp \
../src/DisplayString.cpp 

OBJS += \
./src/DisplayCommunication.o \
./src/DisplayPosition.o \
./src/DisplayString.o 

CPP_DEPS += \
./src/DisplayCommunication.d \
./src/DisplayPosition.d \
./src/DisplayString.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/home/richard/workspace/Architecture_Defines/x86_64 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


