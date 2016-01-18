################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Connection.cpp \
../Playback.cpp \
../Playlist.cpp 

OBJS += \
./Connection.o \
./Playback.o \
./Playlist.o 

CPP_DEPS += \
./Connection.d \
./Playback.d \
./Playlist.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-rpi-linux-gnueabihf-g++ -std=c++0x -DRASPBERRY -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


