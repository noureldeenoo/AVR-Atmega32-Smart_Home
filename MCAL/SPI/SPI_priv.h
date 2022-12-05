/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef SPI_SPI_PRIV_H_
#define SPI_SPI_PRIV_H_


#define SPCR_REG  (*((volatile u8 *)0x2D))  // control
#define SPSR_REG  (*((volatile u8 *)0x2E))  // status
#define SPDR_REG  (*((volatile u8 *)0x2F))  // data

//SPCR

#define SPIE_BIT  7   // Interrupt Enable
#define SPE_BIT   6   // SPI Enable
#define DORD_BIT  5   // data order LSB =  , MSB =
#define MSTR_BIT  4   // master or slave
#define CPOL_BIT  3   // clock polarity
#define CPHA_BIT  2   // clock phase
#define SPR1_BIT  1   // prescaler
#define SPR0_BIT  0   // prescaler

//SPSR
#define SPIF_BIT   7  // Interrupt flag
#define WCOL_BIT   6  // write colession
#define SPI2X_BIT  0   // double speed mode

// polarity
#define  SPI_CLK_POL_IDLE_HIGH   1
#define  SPI_CLK_POL_IDLE_LOW    0

//phase

#define SPI_CLK_PHASE_SAMPLE_FIRST   0
#define SPI_CLK_PHASE_SAMPLE_LAST    1

//data order
#define  SPI_DATA_ORDER_MSB_FIRST    0
#define  SPI_DATA_ORDER_LSB_FIRST    1

// prescaler
#define  SPI_PRESCALER_DOUBLE_2       0
#define  SPI_PRESCALER_DOUBLE_8       1
#define  SPI_PRESCALER_DOUBLE_32      2
#define  SPI_PRESCALER_DOUBLE_64      3

#define  SPI_PRESCALER_NORMAL_4       0
#define  SPI_PRESCALER_NORMAL_16      1
#define  SPI_PRESCALER_NORMAL_64      2
#define  SPI_PRESCALER_NORMAL_128     3

// speed mode
#define  SPI_SPEED_MODE_NORMAL       0
#define  SPI_SPEED_MODE_DOUBLE       1


//prescaler mask

#define SPI_PRESCALER_MASK  0b11111100

#endif /* SPI_SPI_PRIV_H_ */
