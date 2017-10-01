
#ifndef ADC_H_
#define ADC_H_

typedef enum{
	joystick_x		= 0,
	joystick_y		= 1,
	slider_left		= 2,
	slider_right    = 3
	} adc_channel;

void adc_init(void)
uint8_t adc_read(adc_channel channel)

#endif /* ADC_H_ */
