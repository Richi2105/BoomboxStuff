################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main.cpp 

OBJS += \
./main.o 

CPP_DEPS += \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-rpi-linux-gnueabihf-g++ -std=c++1y -DRASPBERRY -I/home/richard/workspace/EventSystemLib/include -I"/home/richard/workspace/DotMatrixDisplayMaster/include" -I"/home/richard/workspace/DotMatrixDisplayLib" -I/home/richard/workspace/Architecture_Defines/ARM_PI -O3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


