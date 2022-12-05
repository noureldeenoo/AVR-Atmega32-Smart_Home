/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/
#include "STD.h"
#include "BitMath.h"
#include "TIMER1_priv.h"
#include "TIMER1_config.h"
#include "TIMER1_int.h"
#include <avr/interrupt.h>
static void (*TIMER1_ICU_ptrCallBack)(void) = NULL;
void M_TIMER1_void_Init(void)
{
  // step 1 : set mode as Normal
	CLR_BIT(TCCR1A_REG,WGM10_BIT);
	CLR_BIT(TCCR1A_REG,WGM11_BIT);

	CLR_BIT(TCCR1B_REG,WGM12_BIT);
	CLR_BIT(TCCR1B_REG,WGM13_BIT);
  // step 2 : set prescaler => 256
	CLR_BIT(TCCR1B_REG,CS10_BIT);
	CLR_BIT(TCCR1B_REG,CS11_BIT);
	SET_BIT(TCCR1B_REG,CS12_BIT);
}
void M_TIMER1_ICU_void_Init(void)
{
   SET_BIT(TCCR1B_REG,ICES1_BIT);
}
void M_TIMER1_ICU_void_EnableInt(void)
{
  SET_BIT(TIMSK_REG,TICIE1_BIT);
}
void M_TIMER1_ICU_void_DisableInt(void)
{
	CLR_BIT(TIMSK_REG,TICIE1_BIT);
}
void M_TIMER1_ICU_void_setCallBack(void (*ptrCallBack)(void))
{
	TIMER1_ICU_ptrCallBack = ptrCallBack ;
}
u16  M_TIMER1_ICU_u16_readInput(void)
{
    return ICR1_REG;
}
void M_TIMER1_ICU_voidsetTrigger(u8 copy_u8Trigger)
{
   switch (copy_u8Trigger)
   {
     case TIMER1_ICU_RISING_EDGE_TRIGGER:
    	 SET_BIT(TCCR1B_REG,ICES1_BIT);
    	 break;
     case TIMER1_ICU_FALLING_EDGE_TRIGGER :
	     CLR_BIT(TCCR1B_REG,ICES1_BIT);
    	 break;
   }
}
ISR(TIMER1_CAPT_vect)
{
   if(TIMER1_ICU_ptrCallBack != NULL)
   {
	   TIMER1_ICU_ptrCallBack();
   }
}
