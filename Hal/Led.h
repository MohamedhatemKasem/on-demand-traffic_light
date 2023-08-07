/*
 * Led.h
 *
 * Created: 8/3/2023 9:37:10 AM
 *  Author: mohamed hatem
 */ 


#ifndef LED_H_
#define LED_H_
typedef enum
{
	led_yellow=PINC1,
	led_green=PINC2,
	led_red=PINC0
}E_led;

void  led_on (E_led led);
void  led_off (E_led led);

#endif /* LED_H_ */