
#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

void UART_init();
void UART_transmit(unsigned char data);
unsigned char UART_receive(void);

#endif
