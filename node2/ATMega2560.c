/*
 * ATMega2560.c
 *
 * Created: 22.10.2017 14:11:57
 *  Author: Jonas Tønnessen, Stian Østerhus
 */ 


#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

//#include "setup_ATMega2560.h"
#include "uart.h"
#include "spi.h"
#include "mcp2515.h"
#include "can.h"
#include "can_test.h"
#include "pwm.h"
#include "adc.h"
#include "twi.h"
#include "dac.h"
#include "motor_control.h"

#define IR_THRESHOLD 100
//#include <stdbool.h>

//volatile bool timer_flag = false;

int main(void)
{
	uart_init();
	SPI_init();
	MCP_init();
	CAN_init();
	PWM_init();
	ADC_init();
	DAC_init();
	MOTOR_init();
	
	sei();
	

    while(1)
    {	
		//DAC_write(0x64);
		
		CAN_message joystick_x = CAN_message_receive();
		unsigned int joystick_data = joystick_x.data[0];
		
		MOTOR_ol_ctrl(joystick_data);
		
		//CAN_test();
		
		/*
		
		CAN_message receive_message = CAN_message_receive();
		unsigned int servopos = 4200 - receive_message.data[0]*24;
		PWM_ctrl(servopos);
		//printf("Servo position: %d \n", servopos);	
		
		*/
			
    }
}

/*
		if(timer_flag)
		{
			// Timer code
			
			
			//timer_flag = false;
		}

ISR(TIMER0_OVF_vect)
{
	timer_flag = true;
}
*/
