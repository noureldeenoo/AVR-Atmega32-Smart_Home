/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

#include "KeyPad_Config.h"
#include "DIO_Interface.h"

#define KEYPAD_PRESSED    0
void H_KeyPad_Void_KeyPadInit(void);
u8 H_KeyPad_U8_KeyPadRead(void);


#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
