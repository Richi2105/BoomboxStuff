################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../EventSystemJavaC++Tools_SocketSlave.cpp 

OBJS += \
./EventSystemJavaC++Tools_SocketSlave.o 

CPP_DEPS += \
./EventSystemJavaC++Tools_SocketSlave.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/richard/jdk/jdk1.8.0_65/include/ -I/home/richard/workspace/Architecture_Defines/x86_64 -I"/home/richard/workspace/EventSystemLib/include" -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


