/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/
#include "L289N_Intraface.h"
#include "L289N_Private.h"

void H_L298N_Void_L298NInit(void)
{
	M_DIO_Void_SetPinDirection(IN1_Port,IN1_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(IN2_Port,IN2_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(DIO_PORTB,DIO_PIN3,OUTPUT);

}
void H_L298N_Void_Right()
{
	M_DIO_Void_SetPinValue(IN1_Port,IN1_PIN,LOW);
	M_DIO_Void_SetPinValue(IN2_Port,IN2_PIN,HIGH);
}
void H_L298N_Void_Left()
{
	M_DIO_Void_SetPinValue(IN1_Port,IN1_PIN,HIGH);
	M_DIO_Void_SetPinValue(IN2_Port,IN2_PIN,LOW);
}
void H_L298N_Void_Speed()
{

}
