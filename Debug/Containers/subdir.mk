################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Containers/MatrixAndVectorTest.cpp \
../Containers/NeighborVectorTest.cpp 

OBJS += \
./Containers/MatrixAndVectorTest.o \
./Containers/NeighborVectorTest.o 

CPP_DEPS += \
./Containers/MatrixAndVectorTest.d \
./Containers/NeighborVectorTest.d 


# Each subdirectory must supply rules for building sources it contributes
Containers/%.o: ../Containers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


