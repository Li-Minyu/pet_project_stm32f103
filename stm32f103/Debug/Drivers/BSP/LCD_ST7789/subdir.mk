################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/LCD_ST7789/lcd.c \
../Drivers/BSP/LCD_ST7789/lcd_init.c 

OBJS += \
./Drivers/BSP/LCD_ST7789/lcd.o \
./Drivers/BSP/LCD_ST7789/lcd_init.o 

C_DEPS += \
./Drivers/BSP/LCD_ST7789/lcd.d \
./Drivers/BSP/LCD_ST7789/lcd_init.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/LCD_ST7789/%.o Drivers/BSP/LCD_ST7789/%.su Drivers/BSP/LCD_ST7789/%.cyclo: ../Drivers/BSP/LCD_ST7789/%.c Drivers/BSP/LCD_ST7789/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-LCD_ST7789

clean-Drivers-2f-BSP-2f-LCD_ST7789:
	-$(RM) ./Drivers/BSP/LCD_ST7789/lcd.cyclo ./Drivers/BSP/LCD_ST7789/lcd.d ./Drivers/BSP/LCD_ST7789/lcd.o ./Drivers/BSP/LCD_ST7789/lcd.su ./Drivers/BSP/LCD_ST7789/lcd_init.cyclo ./Drivers/BSP/LCD_ST7789/lcd_init.d ./Drivers/BSP/LCD_ST7789/lcd_init.o ./Drivers/BSP/LCD_ST7789/lcd_init.su

.PHONY: clean-Drivers-2f-BSP-2f-LCD_ST7789

