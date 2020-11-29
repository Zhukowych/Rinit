################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ServerModule/Server.cpp \
../ServerModule/ServerMain.cpp \
../ServerModule/ServerUnitTest.cpp \
../ServerModule/ServerUnitTestMain.cpp 

OBJS += \
./ServerModule/Server.o \
./ServerModule/ServerMain.o \
./ServerModule/ServerUnitTest.o \
./ServerModule/ServerUnitTestMain.o 

CPP_DEPS += \
./ServerModule/Server.d \
./ServerModule/ServerMain.d \
./ServerModule/ServerUnitTest.d \
./ServerModule/ServerUnitTestMain.d 


# Each subdirectory must supply rules for building sources it contributes
ServerModule/%.o: ../ServerModule/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


