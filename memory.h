
#ifndef MEMORY_H_
#define MEMORY_H_

void memory_init(void);

// Memory mapping

volatile char *oled_cmd = (char *) 0x1000;
volatile char *oled_data = (char *) 0x1200;
volatile char *adc = (char *) 0x1400;
volatile char *sram = (char *) 0x1800;

#endif /* MEMORY_H_ */
