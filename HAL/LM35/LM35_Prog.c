/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#include "LM35_Interface.h"

// global variable shared between this module and ADC
extern u16 gADC_value;

void H_LM35_Void_LM35Init(void)
{
	M_ADC_Void_ADCInit();
}
void H_LM35_Void_LM35Read(u16* Copy_U16_Ptr)
{
	// for Interrupt
	static u16 prev = 0;
	if(prev !=  gADC_value)
	{
		prev = gADC_value;
		*Copy_U16_Ptr = ((u32)gADC_value * 500 ) / 1023;
	}
     // for polling
	/*
	u16 Local_U16_ADCReading = 0;
	Local_U16_ADCReading     = M_ADC_U16_ADCRead(LM35_CHANNEL);
	*Copy_U16_Ptr            = ((u32)Local_U16_ADCReading * 500 ) / 1023;
	*Copy_U16_Ptr           */
}
