/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/
#include "STD.h"
#include "BitMath.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_int.h"
#include "stdlib.h"
#include <avr/interrupt.h>

static u32 TIMER0_u32_NumOfOverflows = 0;
static u8 TIMER0_u8_NumOfRemTick     = 0;
static u32 TIMER0_u32_NumOfCmpMatches = 0;
void (*TIMER0_ptrCallBackArr[2]) (void)={NULL,NULL};

void M_TIMER0_void_Init(void)
{
  // step 1 : config timer mode
#if(TIMER0_MODE   ==   TIMER0_MODE_NORMAL)
	CLR_BIT(TCCR0_REG,WGM00_BIT);
	CLR_BIT(TCCR0_REG,WGM01_BIT);
	// step 2 : config timer OC0 mode
#if( TIMER0_OC0_MODE >= TIMER0_OC0_MODE_DISCONNECTED && TIMER0_OC0_MODE <= TIMER0_OC0_MODE_SET)
	 TCCR0_REG &= TIMER0_OC0_MASK;
	 TCCR0_REG |= TIMER0_OC0_MODE << TIMER0_OC0_SH;
#else
 #error("wrong OC0 mode")
#endif

#elif(TIMER0_MODE == TIMER0_MODE_CTC)
	CLR_BIT(TCCR0_REG,WGM00_BIT);
	SET_BIT(TCCR0_REG,WGM01_BIT);
// step 2 : config timer OC0 mode
#if( TIMER0_OC0_MODE >= TIMER0_OC0_MODE_DISCONNECTED && TIMER0_OC0_MODE <= TIMER0_OC0_MODE_SET)
	 TCCR0_REG &= TIMER0_OC0_MASK;
	 TCCR0_REG |= TIMER0_OC0_MODE << TIMER0_OC0_SH;
#else
 #error("wrong OC0 mode")
#endif
#elif(TIMER0_MODE == TIMER0_MODE_FAST_PWM)
	SET_BIT(TCCR0_REG,WGM00_BIT);
	SET_BIT(TCCR0_REG,WGM01_BIT);
	// step 2 : config timer OC0 mode
#if	(TIMER0_OC0_MODE  == TIMER0_OC0_MODE_PWM_NONINVERTED || TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_INVERTED)
	TCCR0_REG &= TIMER0_OC0_MASK;
	TCCR0_REG |= TIMER0_OC0_MODE ;
#else
 #error ("wrong OC0 Mode")
#endif
#elif(TIMER0_MODE == TIMER0_MODE_PHASECORRECT_PWM)
	SET_BIT(TCCR0_REG,WGM00_BIT);
	CLR_BIT(TCCR0_REG,WGM01_BIT);
// step 2 : config timer OC0 mode
#if	(TIMER0_OC0_MODE  == TIMER0_OC0_MODE_PWM_NONINVERTED || TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_INVERTED)
	TCCR0_REG &= TIMER0_OC0_MASK;
	TCCR0_REG |= TIMER0_OC0_MODE ;
#else
 #error ("wrong OC0 Mode")
#endif
#else
 #error("wrong timer Mode")
#endif

}

void M_TIMER0_void_TimerStart(void)
{
    // config prescaler
#if(TIMER0_PRESCALER >= TIMER0_TIMER_STOP && TIMER0_PRESCALER <= TIMER0_PRESCALER_EXT_FALLING_EDGE )
    TCCR0_REG &= TIMER0_PRESCALER_MASK;
    TCCR0_REG |= TIMER0_PRESCALER;
#else
#error ("wrong Prescaler")
#endif
}
void M_TIMER0_void_setTime(u32 copy_u32Delay) //mseconds
{
  u32 Local_u32arr[5]={1,8,64,256,1024};
  f32 Local_u32TickTime = (f32) Local_u32arr[TIMER0_PRESCALER-1] / FCPU;
  u32 Local_DesiredTicks =  (copy_u32Delay * 1000) / Local_u32TickTime;
#if(TIMER0_MODE ==  TIMER0_MODE_NORMAL)
  TIMER0_u32_NumOfOverflows  =  Local_DesiredTicks / 256;
  TIMER0_u8_NumOfRemTick   = Local_DesiredTicks % 256;
  if(TIMER0_u8_NumOfRemTick != 0)
  {
	  TCNT0_REG  = 256 - TIMER0_u8_NumOfRemTick;
	  TIMER0_u32_NumOfOverflows++;
  }
#elif(TIMER0_MODE ==  TIMER0_MODE_CTC)
  u8 Local_u8Counter = 255;
  while((Local_DesiredTicks % Local_u8Counter)!= 0)
  {
	  Local_u8Counter--;
  }
  TIMER0_u32_NumOfCmpMatches = Local_DesiredTicks / Local_u8Counter;
  OCR0_REG = Local_u8Counter; // preload OCR
#endif
}
void M_TIMER0_void_TimerStop(void)
{
	TCCR0_REG &= TIMER0_PRESCALER_MASK;
}
void M_TIMER0_void_EnableInt(u8 copy_u8IntID)
{
   switch(copy_u8IntID)
   {
   case TIMER0_OVF_INT_ID:
	   SET_BIT(TIMSK_REG,TOIE0_BIT );
   break;

   case TIMER0_OCM_INT_ID:
	   SET_BIT(TIMSK_REG,OCIE0_BIT);
   break;
   default :
	   break;
   }
}
void M_TIMER0_void_DisableInt(u8 copy_u8IntID)
{
	 switch(copy_u8IntID)
	   {
	   case TIMER0_OVF_INT_ID:
		   CLR_BIT(TIMSK_REG,TOIE0_BIT );
	   break;

	   case TIMER0_OCM_INT_ID:
		   CLR_BIT(TIMSK_REG,OCIE0_BIT);
	   break;
	   default :
		   break;
	   }
}
void M_TIMER0_void_setCallBack(void(*ptrCallBack)(void), u8 copy_u8IntID)
{
   /* switch(copy_u8IntID)
    {
    case TIMER0_OVF_INT_ID:
    	TIMER0_ptrCallBackArr[TIMER0_OVF_INT_ID] = ptrCallBack;
   	   break;

   	   case TIMER0_OCM_INT_ID:
   		TIMER0_ptrCallBackArr[TIMER0_OCM_INT_ID] = ptrCallBack;
   	   break;
   	   default :
   		   break;
    }*/
    // Methode 2
	if(copy_u8IntID >= 0 && copy_u8IntID <= 1)
       TIMER0_ptrCallBackArr[copy_u8IntID]=  ptrCallBack;
}
void M_TIMER0_void_setFastPWM(u8 copy_u8DutyCycle)
{
#if(TIMER0_MODE  == TIMER0_MODE_FAST_PWM)
 #if(TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_NONINVERTED)

	OCR0_REG =  abs(((copy_u8DutyCycle * 256 )/100)- 1) ;
 #elif(TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_INVERTED)
	OCR0_REG = abs(255 - ((copy_u8DutyCycle * 256 )/100));
 #else
  #error("wrong OC0 mode ")
 #endif
#endif
}
void M_TIMER0_void_setphaseCorrectPWM(u8 copy_u8DutyCycle)
{
#if(TIMER0_MODE  == TIMER0_MODE_PHASECORRECT_PWM)
 #if(TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_NONINVERTED)

	OCR0_REG =  (copy_u8DutyCycle * 255)/100;
 #elif(TIMER0_OC0_MODE == TIMER0_OC0_MODE_PWM_INVERTED)
	OCR0_REG = 255 - ((copy_u8DutyCycle * 255)/100);
 #else
  #error("wrong OC0 mode ")
 #endif
#endif

}
ISR (TIMER0_OVF_vect)
{
	if(TIMER0_ptrCallBackArr[TIMER0_OVF_INT_ID] != NULL)
	{
		 static u32 OVFcounter = 0;
		   OVFcounter++;
		   if(OVFcounter == TIMER0_u32_NumOfOverflows )
		   {
			   TCNT0_REG = 256 - TIMER0_u8_NumOfRemTick; // prelaod TCNT
			   TIMER0_ptrCallBackArr[TIMER0_OVF_INT_ID]();// call fn in App layer
			   OVFcounter = 0; // clear counter
		   }
	}

}
ISR (TIMER0_COMP_vect)
{
	static u32 Cmpcounter = 0;
	Cmpcounter++;
	if(Cmpcounter == TIMER0_u32_NumOfCmpMatches )
	{
		TIMER0_ptrCallBackArr[TIMER0_OCM_INT_ID]();
		Cmpcounter=0;
	}
}
