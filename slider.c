
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>

#include "adc.h"
#include "slider.h"

void slider_init(void)
{
	adc_init();
	
	// Setting PB0 and PB1 as button inputs
	DDRB &= ~(1 << PINB0) & ~(1 << PINB1);
	// Enable pull-up resistors on input pins
	PORTB |= (1 << PINB0) | (1 << PINB1);
}

slider_pos get_slider_pos(void)
{
	
	uint8_t l_t = adc_read(2);
	uint8_t r_t = adc_read(3);
	
	return(slider_pos)
	{
		.l = 100 * l_t/0xFF,
		.r = 100 * r_t/0xFF
	};
}
