#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#include "UART_driver.h"
#define F_CPU 4915200 // Clock frequency 4.9 MHz.
#define baud_rate 9600 // Setting baud rate to 9600 bits per second
#define MYUBRR F_CPU/16/baud_rate-1

void UART_init()
{
	// Set baud rate
	UBRR0H = (MYUBRR>>8);
	UBRR0L = (MYUBRR);
	
	// Enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	// Set frame format: 8 data, 2 stop bit
	UCSR0C = (1<<URSEL0)|(1<<USBS0)|(3<<UCSZ00);
	
	// Printf function
	fdevopen(&UART_transmit, &UART_receive);
}

void UART_transmit(unsigned char data)
{
	// Wait for transmit buffer to be empty
	while ( ! (UCSR0A & (1<<UDRE0)) );
	
	// Put data into buffer. Send data.
	UDR0 = data;
}

unsigned char UART_receive(void)
{
	// Wait for data to be received
	while ( ! (UCSR0A & (1<<RXC0)) );
	
	// Return data from buffer
	return UDR0;
}
