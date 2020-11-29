################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../HNSW/HNSW.cpp \
../HNSW/HNSWUnitTest.cpp \
../HNSW/HNSWUnitTestMain.cpp \
../HNSW/Layer.cpp \
../HNSW/Node.cpp \
../HNSW/Utils.cpp 

OBJS += \
./HNSW/HNSW.o \
./HNSW/HNSWUnitTest.o \
./HNSW/HNSWUnitTestMain.o \
./HNSW/Layer.o \
./HNSW/Node.o \
./HNSW/Utils.o 

CPP_DEPS += \
./HNSW/HNSW.d \
./HNSW/HNSWUnitTest.d \
./HNSW/HNSWUnitTestMain.d \
./HNSW/Layer.d \
./HNSW/Node.d \
./HNSW/Utils.d 


# Each subdirectory must supply rules for building sources it contributes
HNSW/%.o: ../HNSW/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


