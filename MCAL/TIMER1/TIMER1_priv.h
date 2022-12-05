/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef TIMER1_TIMER1_PRIV_H_
#define TIMER1_TIMER1_PRIV_H_

#define TCCR1A_REG (*((volatile u8 *)0x4F))  // Control register A
#define TCCR1B_REG (*((volatile u8 *)0x4E))  // Control register B
#define ICR1_REG  (*((volatile u16 *)0x46))  // Input Capture register
#define TIMSK_REG (*((volatile u8* )0x59)) // Interrupt Enable
#define TIFR_REG  (*((volatile u8* )0x58)) // Event flags

//Control register A
#define WGM10_BIT  0 //mode
#define WGM11_BIT  1 //mode

//Control register B
#define CS10_BIT   0 // prescaler
#define CS11_BIT   1 // prescaler
#define CS12_BIT   2 // presclaer
#define WGM12_BIT  3 // mode
#define WGM13_BIT  4 // mode
#define ICES1_BIT  6 // trigger select

//TIMSK_Reg
#define TICIE1_BIT 5 // Input Capture Interrupt Enable

//
#endif /* TIMER1_TIMER1_PRIV_H_ */
