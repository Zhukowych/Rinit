################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../UtilsModules/SetMolude/Set.cpp \
../UtilsModules/SetMolude/SetUnitTest.cpp \
../UtilsModules/SetMolude/SetUnitTestMain.cpp 

OBJS += \
./UtilsModules/SetMolude/Set.o \
./UtilsModules/SetMolude/SetUnitTest.o \
./UtilsModules/SetMolude/SetUnitTestMain.o 

CPP_DEPS += \
./UtilsModules/SetMolude/Set.d \
./UtilsModules/SetMolude/SetUnitTest.d \
./UtilsModules/SetMolude/SetUnitTestMain.d 


# Each subdirectory must supply rules for building sources it contributes
UtilsModules/SetMolude/%.o: ../UtilsModules/SetMolude/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


