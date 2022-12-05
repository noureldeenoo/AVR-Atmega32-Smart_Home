/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef HAL_LM35_LM35_INTERFACE_H_
#define HAL_LM35_LM35_INTERFACE_H_

#include "LM35_Config.h"
#include "ADC_Interface.h"


void H_LM35_Void_LM35Init(void);
void H_LM35_Void_LM35Read(u16*);

#endif /* HAL_LM35_LM35_INTERFACE_H_ */
