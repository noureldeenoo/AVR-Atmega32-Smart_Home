/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef UART_UART_INT_H_
#define UART_UART_INT_H_

void M_UART_void_Init(void);
void M_UART_void_sendByte(u8 copy_u8Data);
void M_UART_void_receiveByte(u8 * ptr_data);
void M_UART_void_sendString(u8* str);

#endif /* UART_UART_INT_H_ */
