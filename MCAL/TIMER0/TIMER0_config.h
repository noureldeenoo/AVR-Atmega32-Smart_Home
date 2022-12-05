/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef TIMER0_TIMER0_CONFIG_H_
#define TIMER0_TIMER0_CONFIG_H_

/*
 *  choose from :
 *  TIMER0_MODE_NORMAL
 *  TIMER0_MODE_CTC
 *  TIMER0_MODE_FAST_PWM
 *  TIMER0_MODE_PHASECORRECT_PWM
 */
#define TIMER0_MODE  TIMER0_MODE_FAST_PWM

/*
 *  choose from :
 *  TIMER0_PRESCALER_1
 *  TIMER0_PRESCALER_8
 *  TIMER0_PRESCALER_64
 *  TIMER0_PRESCALER_256
 *  TIMER0_PRESCALER_1024
 *  TIMER0_PRESCALER_EXT_RISING_EDGE
 *  TIMER0_PRESCALER_EXT_FALLING_EDGE
 */
#define TIMER0_PRESCALER  TIMER0_PRESCALER_64

/*
 *  choose from :
 *  Non PWM :
 *  TIMER0_OC0_MODE_DISCONNECTED
 *  TIMER0_OC0_MODE_TOG
 *  TIMER0_OC0_MODE_CLR
 *  TIMER0_OC0_MODE_SET
 *
 *
 *  PWM :
 *  TIMER0_OC0_MODE_PWM_INVERTED
 *  TIMER0_OC0_MODE_PWM_NONINVERTED
 */
#define TIMER0_OC0_MODE  TIMER0_OC0_MODE_PWM_NONINVERTED

#define FCPU  16UL

#endif /* TIMER0_TIMER0_CONFIG_H_ */
