/*
 * Ex_interrupt.h
 *
 * Created: 7/9/2023 8:40:48 PM
 *  Author: mohamed hatem
 */ 


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_

typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
}ExInterruptSource_type;
typedef enum
{
	low_level,
	Any_logic,
	falling_edge,
	rising_edge,
	
}TriggerEdge_type;
void EXI_Enable(ExInterruptSource_type Interrupt);
void EXI_disable(ExInterruptSource_type Interrupt);
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge);
void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void));
#endif /* EX_INTERRUPT_H_ */