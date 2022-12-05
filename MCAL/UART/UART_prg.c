/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#include "STD.h"
#include "BitMath.h"
#include "UART_priv.h"
#include "UART_config.h"
#include "UART_int.h"

void M_UART_void_Init(void)
{
     //step 1 : set mode as Asynch
	 // select register C
	SET_BIT(UCSRC_REG,URSEL_BIT);
	CLR_BIT(UCSRC_REG, UMSEL_BIT);
	// step 2 : set character size
	UCSRC_REG &= UART_CHARACTER_SIZE_MASK;
	UCSRC_REG |= UART_CHARACTER_SIZE << 1;
	// step 3 : set parity
	UCSRC_REG &= UART_PARITY_MASK ;
	UCSRC_REG |= UART_PARITY_BIT << 4;
	// step 4 : stop bits
	UCSRC_REG &= UART_STOP_BIT_MASK;
	UCSRC_REG |= UART_STOP_BIT_1 << USBS_BIT ;
	// step 5 : set Baude Rate
	 // select register High
	CLR_BIT(UCSRC_REG,URSEL_BIT);
	UBRRH_REG = (u8)(UART_BAUD_RATE>> 8);

	UBRRL_REG  =(u8)UART_BAUD_RATE ;
	// step 6 : Enable Tx and Rx
	SET_BIT(UCSRB_REG,TXEN_BIT);
	SET_BIT(UCSRB_REG,RXEN_BIT);

}
void M_UART_void_sendByte(u8 copy_u8Data)
{
   //polling
	while(GET_BIT(UCSRA_REG,UDRE_BIT) == 0);
	UDR_REG = copy_u8Data;
}
void M_UART_void_receiveByte(u8 * ptr_data)
{
    //polling
    while(GET_BIT(UCSRA_REG,RXC_BIT) == 0);
    *ptr_data =  UDR_REG;
}
void M_UART_void_sendString(u8* str)
{
	u32 i = 0;
   while(str[i] != '\0')
   {
	   M_UART_void_sendByte(str[i]);
	   i++;
   }
}
