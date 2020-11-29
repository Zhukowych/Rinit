################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../RequestHandler/Requests/GetReccomendationsRequest.cpp \
../RequestHandler/Requests/GlobalSettings.cpp \
../RequestHandler/Requests/RequestFactory.cpp \
../RequestHandler/Requests/TrainReccomenderModels.cpp 

OBJS += \
./RequestHandler/Requests/GetReccomendationsRequest.o \
./RequestHandler/Requests/GlobalSettings.o \
./RequestHandler/Requests/RequestFactory.o \
./RequestHandler/Requests/TrainReccomenderModels.o 

CPP_DEPS += \
./RequestHandler/Requests/GetReccomendationsRequest.d \
./RequestHandler/Requests/GlobalSettings.d \
./RequestHandler/Requests/RequestFactory.d \
./RequestHandler/Requests/TrainReccomenderModels.d 


# Each subdirectory must supply rules for building sources it contributes
RequestHandler/Requests/%.o: ../RequestHandler/Requests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


