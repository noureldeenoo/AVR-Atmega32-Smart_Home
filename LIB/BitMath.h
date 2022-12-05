/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef BITMATH_H_
#define BITMATH_H_

#define SET_BIT(REG,BIT)          REG |=  (1 << BIT)
#define CLR_BIT(REG,BIT)          REG &= ~(1 << BIT)
#define TOG_BIT(REG,BIT)          REG ^=  (1 << BIT)
#define GET_BIT(REG,BIT)         (1 &   (REG >> BIT))

#endif /* BITMATH_H_ */
