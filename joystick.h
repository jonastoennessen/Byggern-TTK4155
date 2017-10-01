
#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#define direction_threshold 50

typedef struct{
	uint8_t x;
	uint8_t y;
	char dir;
	} joy_pos;

#endif /* JOYSTICK_H_ */
