//----------------------------------------------------------------------------//
//-----------------------RPM INDICATOR 2021-----------------------------------//
//----------------------------------------------------------------------------//
//-----------------------DAC COUNTER DRIVER-----------------------------------//
//----------------------------------------------------------------------------//
sbit CLOCK = P0^1;
sbit DATA  = P0^2;
sbit LATCH = P0^3;

unsigned int i;

#define 	HIGH 		1
#define 	LOW 		0

void writeValue(unsigned long DACval);
void DACdelay(unsigned int d);

//----------------------------------------------------------------------------//
//----------------------------DAC ROUTINE-------------------------------------//
//----------------------------------------------------------------------------//
void writeValue(unsigned long DACval)
{	
	DACval *= 6;
	CLOCK = 0;
	for(i=0;i<16;i++)
	{
		DATA  = (DACval&0X8000);						
		CLOCK = HIGH;					  				
		CLOCK = LOW;					
		DACval<<=1;
	}
	DATA 	= LOW;	
	CLOCK = LOW;									
	LATCH = HIGH;											
	LATCH = LOW;											
}

//-----------------------------------------------------------------------------
//                            END OF PROGRAM
//-----------------------------------------------------------------------------
