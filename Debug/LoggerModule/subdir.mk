################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LoggerModule/Logger.cpp \
../LoggerModule/LoggerUnitTest.cpp \
../LoggerModule/LoggerUnitTestMain.cpp 

OBJS += \
./LoggerModule/Logger.o \
./LoggerModule/LoggerUnitTest.o \
./LoggerModule/LoggerUnitTestMain.o 

CPP_DEPS += \
./LoggerModule/Logger.d \
./LoggerModule/LoggerUnitTest.d \
./LoggerModule/LoggerUnitTestMain.d 


# Each subdirectory must supply rules for building sources it contributes
LoggerModule/%.o: ../LoggerModule/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


