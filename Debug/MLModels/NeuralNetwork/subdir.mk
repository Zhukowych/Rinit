################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MLModels/NeuralNetwork/NNLayer.cpp \
../MLModels/NeuralNetwork/NNUnitTest.cpp \
../MLModels/NeuralNetwork/NeuralNetwork.cpp 

OBJS += \
./MLModels/NeuralNetwork/NNLayer.o \
./MLModels/NeuralNetwork/NNUnitTest.o \
./MLModels/NeuralNetwork/NeuralNetwork.o 

CPP_DEPS += \
./MLModels/NeuralNetwork/NNLayer.d \
./MLModels/NeuralNetwork/NNUnitTest.d \
./MLModels/NeuralNetwork/NeuralNetwork.d 


# Each subdirectory must supply rules for building sources it contributes
MLModels/NeuralNetwork/%.o: ../MLModels/NeuralNetwork/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


