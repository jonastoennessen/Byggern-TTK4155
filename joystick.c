
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>

#include "adc.h"
#include "joystick.h"

#define direction_threshold 50

uint8_t x_offset, y_offset;

void joy_init(void)
{
	adc_init();
	
	// Calibrate joystick x and y direction
	x_offset = adc_read(0);
	y_offset = adc_read(1);
}

joy_pos get_joy_pos(void)
{
	joy_pos joystick_position;
	
	uint8_t x_t, y_t;
	
	x_t = adc_read(0);
	y_t = adc_read(1);
	
	// Calculating the time-varying x position of the joystick
	if(x_t > x_offset){
		joystick_position.x = 100 * (x_t - x_offset)/(0xFF - x_offset);
	}
	else if(x_t < x_offset){
		joystick_position.x = 100 * (x_t - x_offset)/(0xFF - x_offset);
	}
	else{
		joystick_position.x = 0;
	}
	
	// Calculating the time-varying y position of the joystick
	if(y_t > y_offset){
		joystick_position.y = 100 * (y_t - y_offset)/(0xFF - y_offset);
	}
	else if(y_t < y_offset){
		joystick_position.y = 100 * (y_t - y_offset)/(0xFF - y_offset);
	}
	else{
		joystick_position.y = 0;
	}
	
	return joystick_position;	
}

joy_pos get_joy_dir(void)
{
	// Get x and y position of the joystick
	joy_pos pos = get_joy_pos();
	
	if(pos.x > direction_threshold){
		pos.dir = "right";
	}
	else if(pos.x < -direction_threshold){
		pos.dir = "left";
	}
	else{
		pos.dir = "neutral";
	}
	
	if(pos.y > direction_threshold){
		pos.dir = "up";
	}
	else if(pos.y < -direction_threshold){
		pos.dir = "down";
	}
	else{
		pos.dir = "neutral";
	}
	
	return pos;	
	
}
