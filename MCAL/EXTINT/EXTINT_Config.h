/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef MCAL_EXTINT_EXTINT_CONFIG_H_
#define MCAL_EXTINT_EXTINT_CONFIG_H_

/*
 * EXTINT0_SENSE_CONTROL OPTIONS :
 *                                      1 - EXT_INT_FALLING_EDGE
 *                                      2 - EXT_INT_RISING_EDGE
 *                                      3 - EXT_INT_LOW_LEVEL
 *                                      4 - EXT_INT_ANY_LOGICAL_CHANGE
 */
#define EXTINT0_SENSE_CONTROL               EXT_INT_FALLING_EDGE

/*
 * EXTINT1_SENSE_CONTROL OPTIONS :
 *                                      1 - EXT_INT_FALLING_EDGE
 *                                      2 - EXT_INT_RISING_EDGE
 *                                      3 - EXT_INT_LOW_LEVEL
 *                                      4 - EXT_INT_ANY_LOGICAL_CHANGE
 */
#define EXTINT1_SENSE_CONTROL               EXT_INT_RISING_EDGE

/*
 * EXTINT2_SENSE_CONTROL OPTIONS :
 *                                      1 - EXT_INT_FALLING_EDGE
 *                                      2 - EXT_INT_RISING_EDGE
 */
#define EXTINT2_SENSE_CONTROL               EXT_INT_RISING_EDGE

#endif /* MCAL_EXTINT_EXTINT_CONFIG_H_ */
