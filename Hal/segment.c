/*
 * segment.c
 *
 * Created: 7/23/2023 11:13:24 AM
 *  Author: mohamed hatem
 */ 
#include "stdtypes.h"
#include "MemMap.h"
#include "segment.h"
#include "utils.h"
void segment_display(char i)
{
	char SegmentArr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	if(i<=9)
	{
		SEGMENT_PORT1=SegmentArr[i];
	}

}
void segment_display_KIT(char i)
{
	char SegmentArr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	if(i<=9)
	{
		SEGMENT_PORT1=(SegmentArr[i]);
	}

}
void segment_display_2(char i)
{
	char x=i%10;
	i=i/10;
	char SegmentArr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	if(i<=99)
	{
		SEGMENT_PORT1=SegmentArr[x];
		SEGMENT_PORT2=SegmentArr[i];
	}

}
void segment_display_kit_2(char i)
{
	char x=i%10;
	i=i/10;
	char SegmentArr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	if(i<=99)
	{
		set_bit(PORTB,0);
		SEGMENT_PORT1=((SegmentArr[x]));
		clear_bit(PORTB,1);
		_delay_ms(1);
		set_bit(PORTB,1);
		SEGMENT_PORT1=((SegmentArr[i]));
		clear_bit(PORTB,0);
	}

}
void display_BCD(char i)
{
	SEGMENT_PORT1=i;
}
void display_BCD2(char i)
{
	char x;
	x=i%10;
	i=i/10;
	SEGMENT_PORT1=(i<<4)|x;
}
void display_BCD_hex2(char i)
{
	char x;
	x=i%16;
	i=i/16;
	SEGMENT_PORT1=(i<<4)|x;
}