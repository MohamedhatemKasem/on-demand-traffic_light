/*
 * segment.h
 *
 * Created: 7/23/2023 11:13:10 AM
 *  Author: mohamed hatem
 */ 


#ifndef SEGMENT_H_
#define SEGMENT_H_
#define SEGMENT_PORT1  PORTB
#define SEGMENT_PORT2  PORTB
void segment_display(char i);
void segment_display_KIT(char i);
void segment_display_2(char i);
void segment_display_kit_2(char i);
void display_BCD(char i);
void display_BCD2(char i);
void display_BCD_hex2(char i);




#endif /* SEGMENT_H_ */