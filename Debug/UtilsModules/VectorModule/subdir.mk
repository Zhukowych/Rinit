################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../UtilsModules/VectorModule/Vector.cpp \
../UtilsModules/VectorModule/VectorUnitTest.cpp \
../UtilsModules/VectorModule/VectorUnitTestMain.cpp 

OBJS += \
./UtilsModules/VectorModule/Vector.o \
./UtilsModules/VectorModule/VectorUnitTest.o \
./UtilsModules/VectorModule/VectorUnitTestMain.o 

CPP_DEPS += \
./UtilsModules/VectorModule/Vector.d \
./UtilsModules/VectorModule/VectorUnitTest.d \
./UtilsModules/VectorModule/VectorUnitTestMain.d 


# Each subdirectory must supply rules for building sources it contributes
UtilsModules/VectorModule/%.o: ../UtilsModules/VectorModule/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


