
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#include "memory.h"
#include "adc.h"

void adc_init(void)
{
	memory_init();
}

uint8_t adc_read(uint8_t channel)
{
	volatile char *adc = (char *) 0x1400;
		
	*adc = channel;
	
	_delay_us(300);
	
	// Wait for transmitting data from adc to memory
	while (PINE & (1 << PINE0));
	
	return *adc;
}
