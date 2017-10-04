
#ifndef SLIDER_H_
#define SLIDER_H_

typedef struct{
	uint8_t l;
	uint8_t r;
	} slider_pos;

void slider_init(void);
slider_pos get_slider_pos(void);

#endif /* SLIDER_H_ */
