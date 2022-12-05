/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/



#include "LED_Interface.h"

void H_LED_Void_LedInit(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case BLU_LED: M_DIO_Void_SetPinDirection(LED_BLU_PORT,LED_BLU_PIN,OUTPUT); break;
	case GRN_LED: M_DIO_Void_SetPinDirection(LED_GRN_PORT,LED_GRN_PIN,OUTPUT); break;
	case RED_LED: M_DIO_Void_SetPinDirection(LED_RED_PORT,LED_RED_PIN,OUTPUT); break;
	default:                                                                   break;
	}
}
void H_LED_Void_LedOn(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case BLU_LED: M_DIO_Void_SetPinValue(LED_BLU_PORT,LED_BLU_PIN,HIGH); break;
	case GRN_LED: M_DIO_Void_SetPinValue(LED_GRN_PORT,LED_GRN_PIN,HIGH); break;
	case RED_LED: M_DIO_Void_SetPinValue(LED_RED_PORT,LED_RED_PIN,HIGH); break;
	default:                                                             break;
	}
}
void H_LED_Void_LedOff(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case BLU_LED: M_DIO_Void_SetPinValue(LED_BLU_PORT,LED_BLU_PIN,LOW); break;
	case GRN_LED: M_DIO_Void_SetPinValue(LED_GRN_PORT,LED_GRN_PIN,LOW); break;
	case RED_LED: M_DIO_Void_SetPinValue(LED_RED_PORT,LED_RED_PIN,LOW); break;
	default:                                                            break;
	}
}
/*
void H_LED_Void_LedBlink(void)
{
	M_DIO_Void_SetPinValue(LED_PORT,LED_PIN,HIGH);
	_delay_ms(LED_TIME_ON);
	M_DIO_Void_SetPinValue(LED_PORT,LED_PIN,LOW);
}
*/
void H_LED_Void_LedTog(u8 Copy_U8_Led)
{
	switch(Copy_U8_Led)
	{
	case BLU_LED: M_DIO_Void_TogPin(LED_BLU_PORT,LED_BLU_PIN); break;
	case GRN_LED: M_DIO_Void_TogPin(LED_GRN_PORT,LED_GRN_PIN); break;
	case RED_LED: M_DIO_Void_TogPin(LED_RED_PORT,LED_RED_PIN); break;
	default:                                                   break;
	}
}
