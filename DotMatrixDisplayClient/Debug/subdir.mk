################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DotMatrixClient.cpp \
../List.cpp 

OBJS += \
./DotMatrixClient.o \
./List.o 

CPP_DEPS += \
./DotMatrixClient.d \
./List.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/home/richard/workspace/Architecture_Defines/x86_64 -I"/home/richard/workspace/DotMatrixDisplayLib" -I"/home/richard/workspace/EventSystemLib/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


