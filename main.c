
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#define F_CPU 4915200 // Clock frequency 4.9 MHz.
#define baud_rate 9600 // Setting baud rate to 9600 bits per second
#include <util/delay.h>

#include "uart.h"
#include "memory.h"
#include "adc.h"
#include "joystick.h"
#include "slider.h"

#include "uart_test.h"
#include "sram_test.h"
#include "multiboard_test.h"

int main(void)
{
	
	uart_init();
	memory_init();
	adc_init();
	joy_init();
	slider_init();
	oled_init();
	
	
	while (1)
	{
		
	}
	
	return 0;
	
}

