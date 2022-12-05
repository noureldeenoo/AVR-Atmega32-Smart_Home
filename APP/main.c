/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#include "STD.h"
#include "DIO_Interface.h"
#include "LED_Interface.h"
#include "GIE_Interface.h"
#include "TIMER0_int.h"
#include "TIMER1_int.h"
#include "KeyPad_Interface.h"
#include "Buzzer_Interface.h"
#include "LCD_Interface.h"
#include "LM35_Interface.h"
#include "L289N_Intraface.h"
#include "util/delay.h"

static u16 Local_U16_Temp = 0 ;
void APP_MAIN_CheckTemp();

int main()
{
	u8 Local_U8_PassCorr [4] = {'4','4','4','4'};
	u8 Local_U8_PassChar [4] ={0} ;
	u8 Local_U8_Counter = 0 ;
	u8 Local_U8_LEDStatus = 0 ;
    u8 Local_U8_ArrCounter ;

	H_LCD_Void_LCDInit();
    H_KeyPad_Void_KeyPadInit();
    H_LED_Void_LedInit(RED_LED);
    H_LM35_Void_LM35Init();
    H_Buzzer_Void_BuzzerInit();
    H_L298N_Void_L298NInit();
    //step2:Init Timer
    M_TIMER0_void_Init();


    H_L298N_Void_Right();
    /* ENd PWM CONFIG */
    APP_MAIN_CheckTemp();
	while(1)
	{
		//M_WDT_void_Enable();
		//M_WDT_void_sleep()
		APP_MAIN_CheckTemp();
		if(Local_U8_PassCorr [0] != Local_U8_PassChar [0]  && Local_U8_PassCorr [1] != Local_U8_PassChar [1]  && Local_U8_PassCorr [2] != Local_U8_PassChar [2]  && Local_U8_PassCorr [3] != Local_U8_PassChar [3])
		{
		if(Local_U8_Counter == 0 )
		{
		H_LCD_Void_LCDWriteString((u8*)"EnterPassword") ;
			Local_U8_Counter ++ ;
		}
		else if (Local_U8_Counter < 3)
		{

			H_LCD_Void_LCDClear();
			H_LCD_Void_LCDWriteString((u8*)"wrong password");
			_delay_ms(1500);
			H_LCD_Void_LCDClear();
			H_LCD_Void_LCDWriteString((u8*)"EnterPassword") ;
			H_LCD_Void_LCDGoTo(1,0);
			Local_U8_Counter++;
		}
		else
		{
			H_LCD_Void_LCDClear();
			H_LCD_Void_LCDWriteString((u8*)"wait 2 minitus");
			Local_U8_Counter  = 1;
            _delay_ms(18000000);
            H_Buzzer_Void_BuzzerOff();
		}
		H_LCD_Void_LCDGoTo(1,0);
		for(Local_U8_ArrCounter =0 ;Local_U8_ArrCounter<4;Local_U8_ArrCounter++)
		{
			Local_U8_PassChar [Local_U8_ArrCounter] = 0 ;
			while(Local_U8_PassChar [Local_U8_ArrCounter] == 0)
			 {
			 APP_MAIN_CheckTemp();
			Local_U8_PassChar [Local_U8_ArrCounter] = H_KeyPad_U8_KeyPadRead();
			 }
			 H_Buzzer_Void_BuzzerOnce();
			 H_LCD_Void_LCDGoTo(1,Local_U8_ArrCounter);
			 H_LCD_Void_LCDWriteCharacter(Local_U8_PassChar [Local_U8_ArrCounter]);
		}

	     _delay_ms(500);
	     	}
		else
		{
        H_LCD_Void_LCDClear();
        H_LCD_Void_LCDWriteString((u8*)"1- Leds ON");
        H_LCD_Void_LCDGoTo(1,0);
        H_LCD_Void_LCDWriteString((u8*)"2- Leds OFF");

        while(Local_U8_LEDStatus == 0)
        	      {
        	 APP_MAIN_CheckTemp();
        	Local_U8_LEDStatus = H_KeyPad_U8_KeyPadRead();
        	      }
        if(Local_U8_LEDStatus == '1')
        {
        	H_LED_Void_LedOn(RED_LED);
        	 H_Buzzer_Void_BuzzerOnce();
        }
        else if (Local_U8_LEDStatus == '2')
        {
        	H_LED_Void_LedOff(RED_LED);
        	 H_Buzzer_Void_BuzzerOnce();
        }
        else
        {	}
        Local_U8_LEDStatus = 0 ;
	}
}
	return 0;
}


void APP_MAIN_CheckTemp()
{
	H_LM35_Void_LM35Read(&Local_U16_Temp);
			if(Local_U16_Temp <= 25)
			{
				//step3:start time
			    M_TIMER0_void_TimerStart();
			    //step 4 : set fast PWM
			     M_TIMER0_void_setFastPWM(0);
			}
			else if(Local_U16_Temp > 25 && Local_U16_Temp < 30)
			{
				//step3:start time
				M_TIMER0_void_TimerStart();
			    //step 4 : set fast PWM
			    M_TIMER0_void_setFastPWM(50);

			}
			else
			{
				//step3:start time
				M_TIMER0_void_TimerStart();
				//step 4 : set fast PWM
		        M_TIMER0_void_setFastPWM(90);
			}
}
