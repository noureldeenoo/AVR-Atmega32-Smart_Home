/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#define KEYPAD_R0_PORT    DIO_PORTB
#define KEYPAD_R1_PORT    DIO_PORTB
#define KEYPAD_R2_PORT    DIO_PORTB
#define KEYPAD_R3_PORT    DIO_PORTB

#define KEYPAD_C0_PORT    DIO_PORTD
#define KEYPAD_C1_PORT    DIO_PORTD
#define KEYPAD_C2_PORT    DIO_PORTD
#define KEYPAD_C3_PORT    DIO_PORTD

#define  KEYPAD_R0_PIN       DIO_PIN4
#define  KEYPAD_R1_PIN       DIO_PIN5
#define  KEYPAD_R2_PIN       DIO_PIN6
#define  KEYPAD_R3_PIN       DIO_PIN7

#define  KEYPAD_C0_PIN       DIO_PIN2
#define  KEYPAD_C1_PIN       DIO_PIN3
#define  KEYPAD_C2_PIN       DIO_PIN4
#define  KEYPAD_C3_PIN       DIO_PIN5

#define KEYPAD_DEBOUNCING_TIME    120

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */

