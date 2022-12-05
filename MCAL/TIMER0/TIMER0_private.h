/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef TIMER0_TIMER0_PRIVATE_H_
#define TIMER0_TIMER0_PRIVATE_H_

#define TCCR0_REG (*((volatile u8* )0x53)) // control
#define TCNT0_REG (*((volatile u8* )0x52)) // counter
#define OCR0_REG  (*((volatile u8* )0x5C)) // compare match
#define TIMSK_REG (*((volatile u8* )0x59)) // Interrupt Enable
#define TIFR_REG  (*((volatile u8* )0x58)) // Event flags

//TCCR0_REG
#define CS00_BIT  0  // prescaler
#define CS01_BIT  1  // prescaler
#define CS02_BIT  2  // prescaler
#define WGM01_BIT 3  // timer mode
#define COM00_BIT 4  // OC0 pin mode
#define COM01_BIT 5  // OC0 pin mode
#define WGM00_BIT 6  // timer mode
#define FOC0_BIT  7


//TIMSK_REG
#define TOIE0_BIT  0  // OVF Interrupt Enable
#define OCIE0_BIT  1  // OCM  Interrupt Enable

#define TIMER0_MODE_NORMAL            0
#define TIMER0_MODE_CTC               1
#define TIMER0_MODE_FAST_PWM          2
#define TIMER0_MODE_PHASECORRECT_PWM  3

#define TIMER0_TIMER_STOP                 0
#define TIMER0_PRESCALER_1                1
#define TIMER0_PRESCALER_8                2
#define TIMER0_PRESCALER_64               3
#define TIMER0_PRESCALER_256              4
#define TIMER0_PRESCALER_1024             5
#define TIMER0_PRESCALER_EXT_RISING_EDGE  6
#define TIMER0_PRESCALER_EXT_FALLING_EDGE 7


#define TIMER0_PRESCALER_MASK   0b11111000

// OC0 pin Mode
#define TIMER0_OC0_MODE_DISCONNECTED  0
#define TIMER0_OC0_MODE_TOG           1
#define TIMER0_OC0_MODE_CLR           2
#define TIMER0_OC0_MODE_SET           3

#define   TIMER0_OC0_MODE_PWM_INVERTED     0b00110000
#define   TIMER0_OC0_MODE_PWM_NONINVERTED  0b00100000

#define TIMER0_OC0_MASK  0b11001111

#define TIMER0_OC0_SH    4


#endif /* TIMER0_TIMER0_PRIVATE_H_ */
