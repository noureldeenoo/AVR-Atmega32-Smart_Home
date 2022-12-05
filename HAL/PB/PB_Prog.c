/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#include "PB_Interface.h"
#include "DIO_Private.h"

void H_PB_Void_PBInit(u8 Copy_U8_PB)
{
	switch(Copy_U8_PB)
	{
	case PB1 : M_DIO_Void_SetPinDirection(PB1_PORT,PB1_PIN,INPUT); break;
	case PB2 : M_DIO_Void_SetPinDirection(PB2_PORT,PB2_PIN,INPUT); break;
	case PB3 : M_DIO_Void_SetPinDirection(PB3_PORT,PB3_PIN,INPUT); break;
	case PB4 : M_DIO_Void_SetPinDirection(PB4_PORT,PB4_PIN,INPUT); break;
	default:                                                       break;
	}
}
u8   H_PB_U8_PBRead(u8 Copy_U8_PB)
{
	u8 Local_U8_Reading = PB_RELEASED;
	switch(Copy_U8_PB)
	{
	case PB1 :
		if(M_DIO_U8_GetPinValue(PB1_PORT,PB1_PIN) == PB_PRESSED)
		{
			_delay_ms(100);
			if(M_DIO_U8_GetPinValue(PB1_PORT,PB1_PIN) == PB_PRESSED)
			{
				while(M_DIO_U8_GetPinValue(PB1_PORT,PB1_PIN) == PB_PRESSED);
				Local_U8_Reading = PB_PRESSED;
			}
		}
			 break;

	default:                                                                break;
	}
	return Local_U8_Reading;
}






