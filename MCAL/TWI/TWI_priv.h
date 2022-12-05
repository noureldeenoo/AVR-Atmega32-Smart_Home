/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef TWI_TWI_PRIV_H_
#define TWI_TWI_PRIV_H_


#define TWDR_REG   (*((volatile u8*)0x23))   // data register
#define TWAR_REG   (*((volatile u8*)0x22))   // my address as a slave register
#define TWCR_REG   (*((volatile u8*)0x56))   // Control register
#define TWSR_REG   (*((volatile u8*)0x21))   // status register
#define TWBR_REG   (*((volatile u8*)0x20))   // bit rate register

// TWCR

#define TWINT_BIT   7  // interrupt flag
#define TWEA_BIT    6  // enable ACK
#define TWSTA_BIT   5  // send start condition
#define TWSTO_BIT   4  // send stop condition
#define TWWC_BIT    3  // write collession flag
#define TWEN_BIT    2  // TWI enable
#define TWIE_BIT    0  // Interrupt Enable

// TWSR

#define  TWPS1_BIT   1  //prescaler 1
#define  TWPS0_BIT   0  // prescaler 0

// TWAR
#define TWGCE_BIT  0  // broadcast address recognetion

#define TWI_STATUS_MASK  0b11111000
#endif /* TWI_TWI_PRIV_H_ */
