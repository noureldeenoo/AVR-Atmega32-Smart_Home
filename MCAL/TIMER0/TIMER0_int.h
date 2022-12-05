/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef TIMER0_TIMER0_INT_H_
#define TIMER0_TIMER0_INT_H_

#define TIMER0_OVF_INT_ID 0
#define TIMER0_OCM_INT_ID 1

void M_TIMER0_void_Init(void);
void M_TIMER0_void_setTime(u32 copy_u32Delay);
void M_TIMER0_void_TimerStart(void);
void M_TIMER0_void_TimerStop(void);
void M_TIMER0_void_EnableInt(u8 copy_u8IntID);
void M_TIMER0_void_DisableInt(u8 copy_u8IntID);
void M_TIMER0_void_setCallBack(void(*ptrCallBack)(void), u8 copy_u8IntID);
void M_TIMER0_void_setFastPWM(u8 copy_u8DutyCycle);
void M_TIMER0_void_setphaseCorrectPWM(u8 copy_u8DutyCycle);
#endif /* TIMER0_TIMER0_INT_H_ */
