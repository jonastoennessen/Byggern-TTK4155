
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>

void memory_init(void)
{
	MCUCR |= (1<<SRE);			// Enables external memory interface.
	SFIOR |= (1<<XMM2);			// PC4-PC7 is exploited by the JTAG. These are released from normal port pin function.
}
