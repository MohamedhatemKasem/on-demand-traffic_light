/*
 * Led.c
 *
 * Created: 8/3/2023 9:36:55 AM
 *  Author: mohamed hatem
 */ 
#include "MemMap.h"
#include "stdtypes.h"
#include "DIO_INTERFACE.h"
#include "Led.h"
void  led_on (E_led led)
{
	DIO_WritePin(led,HIGH);
	
}
void  led_off (E_led led)
{
	DIO_WritePin(led,LOW);
	
}

