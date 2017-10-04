
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#include "uart.h"
#include "uart_test.h"

void uart_test(void)
{
	char d[10];
	scanf("%s",d);
	printf("String = %s", d);
}
