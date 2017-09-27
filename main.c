
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#define F_CPU 4915200 // Clock frequency 4.9 MHz.
#define baud_rate 9600 // Setting baud rate to 9600 bits per second
#include <util/delay.h>

#include "UART_driver.h"
#include "memory.h"
#include "SRAM_test.h"


int main(void)
{
	
	
	UART_init();
	memory_init();
	
	while(1){
		char d[10];
		scanf("%s",d);
		printf("String = %s", d);
	}
	
	while(1)
	{
		SRAM_test();
		//*sram = 1;
		//*adc = 1;
		//*oled_cmd = 1;
		//*oled_data = 1;
		//_delay_us(1);
	}
	
	
	return 0;
	
}

