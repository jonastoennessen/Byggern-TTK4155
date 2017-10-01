
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>

#include "adc.h"
#include "memory.h"

void adc_init(void)
{
	memory_init();
}

uint8_t adc_read(adc_channel channel)
{
	*adc = channel;
	
	// Wait for transmitting data from adc to memory
	
	return *adc;
}
