
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>

#include "joystick.h"
#include "slider.h"
#include "multiboard_test.h"

void multiboard_test(void)
{
/*	slider_pos sli_pos;
	sli_pos = get_slider_pos();
	printf(" Slider pos left: %3d\n", sli_pos.r); */
	
	joy_pos joypos;
	joypos = get_joy_pos();
	printf("Joystick x pos: %3d\n", joypos.x);
}
