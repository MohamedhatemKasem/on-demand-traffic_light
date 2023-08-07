/*
 * EX_interrupt.c
 *
 * Created: 7/9/2023 8:40:22 PM
 *  Author: mohamed hatem
 */ 
#include "Ex_interrupt.h"
#include "stdtypes.h"
#include "MemMap.h"
#include "utils.h"
static void (*INT0_Fptr) (void)=NULLPTR;
static void (*INT1_Fptr) (void)=NULLPTR;
static void (*INT2_Fptr) (void)=NULLPTR;
void EXI_Enable(ExInterruptSource_type interrupt)
{
	switch(interrupt)
	{
		case EX_INT0:
		set_bit(GICR,INT0);
		break;
		case EX_INT1:
		set_bit(GICR,INT1);
		break;
		case EX_INT2:
		set_bit(GICR,INT2);
		break;
	}
}
void EXI_disable(ExInterruptSource_type interrupt)
{
	switch(interrupt)
	{
		case EX_INT0:
		clear_bit(GICR,INT0);
		break;
		case EX_INT1:
		clear_bit(GICR,INT1);
		break;
		case EX_INT2:
		clear_bit(GICR,INT2);
		break;
	}
}
void EXI_TriggerEdge(ExInterruptSource_type interrupt,TriggerEdge_type Edge)
{
	switch (interrupt)
	{
		case EX_INT0:
		switch(Edge)
		{
			case low_level:
			clear_bit(MCUCR,ISC00);
			clear_bit(MCUCR,ISC01);
			break;
			case Any_logic:
			set_bit(MCUCR,ISC00);
			clear_bit(MCUCR,ISC01);
			break;
			case falling_edge:
			clear_bit(MCUCR,ISC00);
			set_bit(MCUCR,ISC01);
			break;
			case rising_edge:
			set_bit(MCUCR,ISC00);
			set_bit(MCUCR,ISC01);
			break;
		
		}
		break;
		case EX_INT1:
		switch(Edge)
		{
			case low_level:
			clear_bit(MCUCR,ISC10);
			clear_bit(MCUCR,ISC11);
			break;
			case Any_logic:
			set_bit(MCUCR,ISC10);
			clear_bit(MCUCR,ISC11);
			break;
			case falling_edge:
			clear_bit(MCUCR,ISC10);
			set_bit(MCUCR,ISC11);
			break;
			case rising_edge:
			set_bit(MCUCR,ISC10);
			set_bit(MCUCR,ISC11);
			break;
			
		}
		break;
		case EX_INT2:
		switch(Edge)
		{
			case falling_edge:
			clear_bit(MCUCR,ISC2);
			break;
			case rising_edge:
			set_bit(MCUCR,ISC2);
			break;
			default:
			clear_bit(MCUCR,ISC2);
		}
		break;
	}
}
void EXI_SetCallBack(ExInterruptSource_type interrupt,void(*LocalPtr)(void))
{
	switch(interrupt)
	{
		case EX_INT0:
		INT0_Fptr=LocalPtr;
		break;
		case EX_INT1:
		INT1_Fptr=LocalPtr;
		break;
		case EX_INT2:
		INT2_Fptr=LocalPtr;
		break;
	}

}
ISR(INT0_vect)
{
	if(INT0_Fptr!=NULLPTR)
	{
		INT0_Fptr();
	}
}
ISR(INT1_vect)
{
	if(INT1_Fptr!=NULLPTR)
	{
		INT1_Fptr();
	}
}
ISR(INT2_vect)
{
	if(INT2_Fptr!=NULLPTR)
	{
		INT2_Fptr();
	}
}
