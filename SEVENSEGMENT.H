//----------------------------------------------------------------------------//
//-----------------------RPM INDICATOR 2021-----------------------------------//
//----------------------------------------------------------------------------//
//-------------------SEVEN SEGMENT DISPLAY DRIVER-----------------------------//
//----------------------------------------------------------------------------//
#include "delay.h"
unsigned int i;

//-----------------------------------------------------------------------------
//                     	MACROS DEFINITION
//-----------------------------------------------------------------------------
#define SEGDISP P1
#define DIGDISP P2

#define	DIG6 ~0x20
#define	DIG5 ~0x10
#define	DIG4 ~0x08
#define	DIG3 ~0x04
#define	DIG2 ~0x02
#define	DIG1 ~0x01

#define VAL0        0XC0
#define VAL1        0xF9
#define VAL2        0xA4
#define VAL3        0xB0
#define VAL4        0x99
#define VAL5        0x92
#define VAL6        0x82
#define VAL7        0xF8
#define VAL8        0x80
#define VAL9        0x90

#define DOT         0x7F
#define M						0xAA

code unsigned char SEG_7[10] = {0xC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90};

//-----------------------------------------------------------------------------
//											DISPLAY ROUTINE                      	
//-----------------------------------------------------------------------------

void DisplaySegment(unsigned char Add, unsigned char Dat)
{
	DIGDISP = Add;
	SEGDISP = Dat;
}

void DisplayStartup()
{
		DisplaySegment(DIG1,SEG_7[8]);	Delay_1ms(100);
		DisplaySegment(DIG2,SEG_7[8]);	Delay_1ms(100);
		DisplaySegment(DIG3,SEG_7[8]);	Delay_1ms(100);
		DisplaySegment(DIG4,SEG_7[8]);	Delay_1ms(100);
		DisplaySegment(DIG5,SEG_7[8]);	Delay_1ms(100);
		DisplaySegment(DIG6,SEG_7[8]);	Delay_1ms(100);
}

void DisplayVAL(unsigned long TempVAL)
{	
		DisplaySegment(DIG6,SEG_7[TempVAL%10]);	 	for(i=0;i<10;i++);	TempVAL/=10;		
		DisplaySegment(DIG5,SEG_7[TempVAL%10]);		for(i=0;i<10;i++);	TempVAL/=10;		
		DisplaySegment(DIG4,SEG_7[TempVAL%10]);		for(i=0;i<10;i++);	TempVAL/=10;		
		DisplaySegment(DIG3,SEG_7[TempVAL%10]);		for(i=0;i<10;i++);	TempVAL/=10;		
		DisplaySegment(DIG2,SEG_7[TempVAL%10]);		for(i=0;i<10;i++);	TempVAL/=10;		
		DisplaySegment(DIG1,M);										for(i=0;i<10;i++);
}

//-----------------------------------------------------------------------------
//                            END OF PROGRAM
//-----------------------------------------------------------------------------