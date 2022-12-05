/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/


#include "GIE_Interface.h"
#include "GIE_Private.h"

void M_GIE_Void_GlobalIntEnable(void)
{
	SET_BIT(SREG_REG,I_BIT);
}
void M_GIE_Void_GlobalIntDisable(void)
{
	CLR_BIT(SREG_REG,I_BIT);
}
