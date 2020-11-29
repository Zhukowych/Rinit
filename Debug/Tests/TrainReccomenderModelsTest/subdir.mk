################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Tests/TrainReccomenderModelsTest/TrainReccomenderModlsTest.cpp 

OBJS += \
./Tests/TrainReccomenderModelsTest/TrainReccomenderModlsTest.o 

CPP_DEPS += \
./Tests/TrainReccomenderModelsTest/TrainReccomenderModlsTest.d 


# Each subdirectory must supply rules for building sources it contributes
Tests/TrainReccomenderModelsTest/%.o: ../Tests/TrainReccomenderModelsTest/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


