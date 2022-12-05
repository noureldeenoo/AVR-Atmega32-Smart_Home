/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef LED_LED_CONGIG_H_
#define LED_LED_CONGIG_H_

/*
 * SELECT LED PORT , PIN
 */
#define LED_BLU_PORT         DIO_PORTC
#define LED_BLU_PIN          DIO_PIN2
#define LED_GRN_PORT         DIO_PORTC
#define LED_GRN_PIN          DIO_PIN1
#define LED_RED_PORT         DIO_PORTC
#define LED_RED_PIN          DIO_PIN0
/*
 * SELECT LED BLINKING TIME IN MILLI SECON
 */
#define LED_TIME_ON     250

#endif /* LED_LED_CONGIG_H_ */
