
#ifndef JOYSTICK_H_
#define JOYSTICK_H_

typedef struct{
	uint8_t x;
	uint8_t y;
	char dir;
	} joy_pos;
	
void joy_init(void);
joy_pos get_joy_pos(void);
joy_pos get_joy_dir(void);

#endif /* JOYSTICK_H_ */
