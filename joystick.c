
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>

#include "adc.h"
#include "joystick.h"

void joy_init(void)
{
	adc_init();
	
	// Calibrate joystick x and y direction
	uint8_t x_offset = adc_read(joystick_x);
	uint8_t y_offset = adc_read(joystick_y);
}

joy_pos get_joy_pos(void)
{
	uint8_t x_t = adc_read(joystick_x);
	uint8_t y_t = adc_read(joystick_y);
	
	// Calculating the time-varying x position of the joystick
	if(x_t > x_offset){
		joy_pos.x = 100 * (x_t - x_offset)/(0xFF - x_offset);
	}
	else if(x_t < x_offset){
		joy_pos.x = 100 * (x_t - x_offset)/(0xFF - x_offset);
	}
	else{
		joy_pos.x = 0;
	}
	
	// Calculating the time-varying y position of the joystick
	if(y_t > y_offset){
		joy_pos.y = 100 * (y_t - y_offset)/(0xFF - y_offset);
	}
	else if(y_t < y_offset){
		joy_pos.y = 100 * (y_t - y_offset)/(0xFF - y_offset);
	}
	else{
		joy_pos.y = 0;
	}
	
	return joy_pos;	
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
