################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Classes/VocabularyEntity.cpp \
../Classes/VocabularyList.cpp \
../Classes/VocabularyTrainer.cpp 

OBJS += \
./Classes/VocabularyEntity.o \
./Classes/VocabularyList.o \
./Classes/VocabularyTrainer.o 

CPP_DEPS += \
./Classes/VocabularyEntity.d \
./Classes/VocabularyList.d \
./Classes/VocabularyTrainer.d 


# Each subdirectory must supply rules for building sources it contributes
Classes/%.o: ../Classes/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


