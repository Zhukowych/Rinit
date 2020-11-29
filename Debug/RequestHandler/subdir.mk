################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../RequestHandler/RequestHandler.cpp \
../RequestHandler/RequestHandlerUnitTest.cpp \
../RequestHandler/RequestHandlerUnitTestMain.cpp 

OBJS += \
./RequestHandler/RequestHandler.o \
./RequestHandler/RequestHandlerUnitTest.o \
./RequestHandler/RequestHandlerUnitTestMain.o 

CPP_DEPS += \
./RequestHandler/RequestHandler.d \
./RequestHandler/RequestHandlerUnitTest.d \
./RequestHandler/RequestHandlerUnitTestMain.d 


# Each subdirectory must supply rules for building sources it contributes
RequestHandler/%.o: ../RequestHandler/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


