/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef HAL_BUZZER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_BUZZER_INTERFACE_H_

#include "Buzzer_Config.h"
#include "DIO_Interface.h"
#include <util/delay.h>

void H_Buzzer_Void_BuzzerInit(void);
void H_Buzzer_Void_BuzzerOn(void);
void H_Buzzer_Void_BuzzerOff(void);
void H_Buzzer_Void_BuzzerTog(void);
void H_Buzzer_Void_BuzzerOnce(void);
void H_Buzzer_Void_BuzzerTwice(void);

#endif /* HAL_BUZZER_BUZZER_INTERFACE_H_ */
