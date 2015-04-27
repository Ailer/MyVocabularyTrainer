################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Classes/VocabularyEntity.cpp \
../Classes/VocabularyTrainer.cpp 

OBJS += \
./Classes/VocabularyEntity.o \
./Classes/VocabularyTrainer.o 

CPP_DEPS += \
./Classes/VocabularyEntity.d \
./Classes/VocabularyTrainer.d 


# Each subdirectory must supply rules for building sources it contributes
Classes/%.o: ../Classes/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


