################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DataBase/DataBase.cpp \
../DataBase/DataBaseUnitTest.cpp \
../DataBase/DataBaseUnitTestMain.cpp 

OBJS += \
./DataBase/DataBase.o \
./DataBase/DataBaseUnitTest.o \
./DataBase/DataBaseUnitTestMain.o 

CPP_DEPS += \
./DataBase/DataBase.d \
./DataBase/DataBaseUnitTest.d \
./DataBase/DataBaseUnitTestMain.d 


# Each subdirectory must supply rules for building sources it contributes
DataBase/%.o: ../DataBase/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


