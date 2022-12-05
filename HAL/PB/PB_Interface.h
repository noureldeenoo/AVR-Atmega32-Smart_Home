/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef HAL_PB_PB_INTERFACE_H_
#define HAL_PB_PB_INTERFACE_H_

#include "PB_Config.h"
#include "STD.h"
#include "DIO_Interface.h"
#include <util/delay.h>

#define PB_ACTIVE_LOW    2
#define PB_ACTIVE_HIGH   3

#if   PB_MODE   ==   PB_ACTIVE_LOW
#define PB_PRESSED            0
#define PB_RELEASED           1
#elif PB_MODE   ==   PB_ACTIVE_HIGH
#define PB_PRESSED            1
#define PB_RELEASED           0
#endif

#define PB1                1
#define PB2                2
#define PB3                3
#define PB4                4

void H_PB_Void_PBInit(u8);
u8   H_PB_U8_PBRead(u8);

#endif /* HAL_PB_PB_INTERFACE_H_ */
