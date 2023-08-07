/*
 * App.c
 *
 * Created: 8/3/2023 5:48:29 PM
 *  Author: mohamed hatem
 */ 
#include "utils.h"
#include "MemMap.h"
#include "stdtypes.h"
#include "DIO_INTERFACE.h"
#include "lcd_interface.h"
#include "Ex_interrupt.h"
#include "Timer.h"
#include "segment.h"
#include "Led.h"
#define  Globale_enable sei
#define  Globale_disable cli
volatile u8 flag=0,counter=20,flagex=0;
volatile u32 c=0;
#define  time_on_off_of_traffic 20
#define  time_of_yellow_led 5
#define time_of_wait_after_switch_pressed 2
#define sec_value 4000;
void timer_overflow(void)
{
	c++;
	if(c%4000==0)
	{
		counter--;
		LCD_ClearPosition(1,14,3);
		LCD_GoTo(1,14);
		LCD_WriteNumber(counter);
		if(counter==0)
		{
			counter=20;
		}
	}
	if(c==60000&&flag==2)
	{
		flag=1;
	}
	if(c==80000)
	{
		c=0;
		if(flag==0)
		{
			flag=2;
			stop();
		}
		else if(flag==1)
		{
			flag=0;
			flagex=0;
			go_on();
			
		}
		else if(flag==2)
		{
			
		}
	}
	TCNT0=6;
	
	
}
void bottom_pressed_interrupt(void)
{
	if(DIO_readPin(led_red)==0&&flagex==0)
	{
		bottom_pressed();
		c=(72000);
		flagex=1;
		flag=1;
		counter=2;
		TCNT0=6;
		
	}
	
	
}
void app_start(void)
{
	DIO_Init();
	LCD_Init();
	TIMER0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_8);
	TIMER0_OV_InterruptEnable();
	const static u8 person[]={0x04,0x0a,0x04,0x0e,0x15,0x04,0x0a};
	const static u8 arrow[] = {
		0x00,
		0x04,
		0x02,
		0x1F,
		0x02,
		0x04,
		0x00,
		0x00
	};
	const static u8 locked[] = {
		14,17,17,31,27,27,31,0
	};
	const static u8 unlocked[] = {
		14,16,16,31,27,27,31,0
	};
	TIMER0_OV_SetCallBack(timer_overflow);
	EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT0,falling_edge);
	EXI_SetCallBack(EX_INT0,bottom_pressed_interrupt);
	DIO_WritePort(PC,0x01);
	LCD_CustomChar(0,person);
	LCD_CustomChar(1,arrow);
	LCD_CustomChar(2,locked);
	LCD_CustomChar(3,unlocked);
	go_on();
	led_on(led_red);
	Globale_enable();
	while(1)
	{
		display_BCD2(counter);
		if(flag==0)
		{
			led_on(led_red);
			led_off(led_yellow);
			led_off(led_green);
		}
		else if(flag==1)
		{
			led_on(led_yellow);
			led_off(led_red);
			led_off(led_green);
		}
		else if(flag==2)
		{
			led_on(led_green);
			led_off(led_yellow);
			led_off(led_red);
		}
		
	}
}
