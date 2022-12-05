/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/


#include "LCD_Interface.h"
#include "LCD_Private.h"

void H_LCD_Void_LCDInit(void)
{
#if   LCD_MODE   ==   LCD_8_BIT_MODE
	M_DIO_Void_SetPinDirection(LCD_D0_PORT,LCD_D0_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D1_PORT,LCD_D1_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D2_PORT,LCD_D2_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D3_PORT,LCD_D3_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D4_PORT,LCD_D4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5_PORT,LCD_D5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6_PORT,LCD_D6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7_PORT,LCD_D7_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
	H_LCD_Void_LCDWriteCommand(LCD_8_BIT_MODE_COMMAND);
	H_LCD_Void_LCDWriteCommand(LCD_DISPLAY_ON_COMMAND);
#elif LCD_MODE   ==   LCD_4_BIT_MODE
	M_DIO_Void_SetPinDirection(LCD_D4_PORT,LCD_D4_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D5_PORT,LCD_D5_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D6_PORT,LCD_D6_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_D7_PORT,LCD_D7_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_1);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_2);
	H_LCD_Void_LCDWriteCommand(LCD_4_BIT_MODE_COMMAND_3);
	H_LCD_Void_LCDWriteCommand(LCD_DISPLAY_ON_COMMAND);
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR_COMMAND);
	H_LCD_Void_LCDWriteCommand(LCD_RETURN_HOME_COMMAND);
#endif
}
void H_LCD_Void_LCDWriteCharacter(u8 Copy_U8_Character)
{
#if LCD_MODE   ==   LCD_8_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,HIGH);
	M_DIO_Void_SetPinValue(LCD_D0_PORT,LCD_D0_PIN,GET_BIT(Copy_U8_Character,0));
	M_DIO_Void_SetPinValue(LCD_D1_PORT,LCD_D1_PIN,GET_BIT(Copy_U8_Character,1));
	M_DIO_Void_SetPinValue(LCD_D2_PORT,LCD_D2_PIN,GET_BIT(Copy_U8_Character,2));
	M_DIO_Void_SetPinValue(LCD_D3_PORT,LCD_D3_PIN,GET_BIT(Copy_U8_Character,3));
	M_DIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Character,4));
	M_DIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Character,5));
	M_DIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Character,6));
	M_DIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Character,7));
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);
#elif LCD_MODE   ==   LCD_4_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,HIGH);

	M_DIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Character,4));
	M_DIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Character,5));
	M_DIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Character,6));
	M_DIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Character,7));

	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);

	M_DIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Character,0));
	M_DIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Character,1));
	M_DIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Character,2));
	M_DIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Character,3));

	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);
#endif
}
void H_LCD_Void_LCDWriteCommand(u8 Copy_U8_Command)
{
#if LCD_MODE   ==   LCD_8_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);
	M_DIO_Void_SetPinValue(LCD_D0_PORT,LCD_D0_PIN,GET_BIT(Copy_U8_Command,0));
	M_DIO_Void_SetPinValue(LCD_D1_PORT,LCD_D1_PIN,GET_BIT(Copy_U8_Command,1));
	M_DIO_Void_SetPinValue(LCD_D2_PORT,LCD_D2_PIN,GET_BIT(Copy_U8_Command,2));
	M_DIO_Void_SetPinValue(LCD_D3_PORT,LCD_D3_PIN,GET_BIT(Copy_U8_Command,3));
	M_DIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Command,4));
	M_DIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Command,5));
	M_DIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Command,6));
	M_DIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Command,7));
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);
#elif LCD_MODE   ==   LCD_4_BIT_MODE
	M_DIO_Void_SetPinValue(LCD_RS_PORT,LCD_RS_PIN,LOW);

	M_DIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Command,4));
	M_DIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Command,5));
	M_DIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Command,6));
	M_DIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Command,7));

	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);

	M_DIO_Void_SetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Copy_U8_Command,0));
	M_DIO_Void_SetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Copy_U8_Command,1));
	M_DIO_Void_SetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Copy_U8_Command,2));
	M_DIO_Void_SetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Copy_U8_Command,3));

	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_DIO_Void_SetPinValue(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(5);
#endif
}
void H_LCD_Void_LCDWriteString(u8*Copy_U8_Ptr)
{
	u8 Local_U8_Counter = 0;
	while(Copy_U8_Ptr[Local_U8_Counter] != '\0')
	{
		H_LCD_Void_LCDWriteCharacter(Copy_U8_Ptr[Local_U8_Counter]);
		Local_U8_Counter++;
	}
}
void H_LCD_Void_LCDWriteNumber(s32 Copy_S32_Num)
{
	if(Copy_S32_Num < 0)
	{
		Copy_S32_Num = Copy_S32_Num * -1;
		H_LCD_Void_LCDWriteCharacter('-');
	}
	u8 Local_U8_Arr[10] = {0};
	s8 Local_S8_Counter = -1;
	while(Copy_S32_Num != 0)
	{
		Local_S8_Counter++;
		Local_U8_Arr[Local_S8_Counter] = Copy_S32_Num % 10;
		Copy_S32_Num = Copy_S32_Num / 10;
	}
	while(Local_S8_Counter >= 0)
	{
		H_LCD_Void_LCDWriteCharacter( Local_U8_Arr[Local_S8_Counter] + LCD_ASCII_OF_0);
		Local_S8_Counter--;
	}
}
void H_LCD_Void_LCDGoTo(u8 Copy_U8_Row,u8 Copy_U8_Col)
{
	u8 Local_U8_Arr[2] = {LCD_GOTO_R0_COMMAND , LCD_GOTO_R1_COMMAND};
	H_LCD_Void_LCDWriteCommand(Local_U8_Arr[Copy_U8_Row] + Copy_U8_Col);

}
void H_LCD_Void_LCDClear(void)
{
	H_LCD_Void_LCDWriteCommand(LCD_CLEAR_COMMAND);
}


