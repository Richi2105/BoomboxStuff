################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../backupSourceHeader/DisplayCommunication.cpp \
../backupSourceHeader/DisplayPosition.cpp \
../backupSourceHeader/DisplayString.cpp 

OBJS += \
./backupSourceHeader/DisplayCommunication.o \
./backupSourceHeader/DisplayPosition.o \
./backupSourceHeader/DisplayString.o 

CPP_DEPS += \
./backupSourceHeader/DisplayCommunication.d \
./backupSourceHeader/DisplayPosition.d \
./backupSourceHeader/DisplayString.d 


# Each subdirectory must supply rules for building sources it contributes
backupSourceHeader/%.o: ../backupSourceHeader/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-rpi-linux-gnueabihf-g++ -std=c++1y -DRASPBERRY -I/home/richard/workspace/EventSystemLib/include -I"/home/richard/workspace/DotMatrixDisplayLib/include" -I/home/richard/workspace/Architecture_Defines/ARM_PI -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


