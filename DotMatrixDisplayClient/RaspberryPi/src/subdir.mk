################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DisplayBoundary.cpp \
../src/DisplayCommunication.cpp \
../src/DisplayPosition.cpp \
../src/DisplayString.cpp \
../src/Displayable.cpp \
../src/fonts.cpp 

OBJS += \
./src/DisplayBoundary.o \
./src/DisplayCommunication.o \
./src/DisplayPosition.o \
./src/DisplayString.o \
./src/Displayable.o \
./src/fonts.o 

CPP_DEPS += \
./src/DisplayBoundary.d \
./src/DisplayCommunication.d \
./src/DisplayPosition.d \
./src/DisplayString.d \
./src/Displayable.d \
./src/fonts.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-rpi-linux-gnueabihf-g++ -std=c++0x -DRASPBERRY -I/home/richard/workspace/Architecture_Defines/ARM_PI -I/usr/lib/raspberry/wiringPi/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


