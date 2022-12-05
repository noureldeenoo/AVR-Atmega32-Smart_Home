/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef UART_UART_CONFIG_H_
#define UART_UART_CONFIG_H_

/*
 *   choose from :
 *   UART_CHARACTER_SIZE_5
 *   UART_CHARACTER_SIZE_6
 *   UART_CHARACTER_SIZE_7
 *   UART_CHARACTER_SIZE_8
 *
 */
#define UART_CHARACTER_SIZE    UART_CHARACTER_SIZE_8
/*
 *  choose from :
 *  UART_PARITY_BIT_NO_PARITY
 *  UART_PARITY_BIT_EVEN
 *  UART_PARITY_BIT_ODD
 */
#define UART_PARITY_BIT   UART_PARITY_BIT_NO_PARITY


/*
 *  choose stop bits :
 *  UART_STOP_BIT_1   0
 *  UART_STOP_BIT_2   1
 */
#define UART_STOP_BIT   UART_STOP_BIT_1

/*
 * choose BR from :
 * UART_BAUD_RATE_16MHZ_2400
 * UART_BAUD_RATE_16MHZ_9600
 * UART_BAUD_RATE_16MHZ_115200
 *
 * UART_BAUD_RATE_8MHZ_2400
 * UART_BAUD_RATE_8MHZ_9600
 * UART_BAUD_RATE_8MHZ_115200
 */
#define UART_BAUD_RATE    UART_BAUD_RATE_16MHZ_9600
#endif /* UART_UART_CONFIG_H_ */
