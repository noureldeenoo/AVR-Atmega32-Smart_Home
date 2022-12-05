/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef SPI_SPI_CONFIG_H_
#define SPI_SPI_CONFIG_H_

/*
 *  choose from :
 *  SPI_SPEED_MODE_NORMAL
 *  SPI_SPEED_MODE_DOUBLE
 */
#define SPI_SPEED_MODE   SPI_SPEED_MODE_NORMAL
/*
 *  choose prescaler :
 *  NORMAL speed :
 *  SPI_PRESCALER_NORMAL_4
 *  SPI_PRESCALER_NORMAL_16
 *  SPI_PRESCALER_NORMAL_64
 *  SPI_PRESCALER_NORMAL_128
 *
 *  double speed :
 *  SPI_PRESCALER_DOUBLE_2
 *  SPI_PRESCALER_DOUBLE_8
 *  SPI_PRESCALER_DOUBLE_32
 *  SPI_PRESCALER_DOUBLE_64
 *
 */
#define SPI_PRESCALER   SPI_PRESCALER_NORMAL_16
/*
 * choose from :
 *  SPI_CLK_POL_IDLE_HIGH
 *  SPI_CLK_POL_IDLE_LOW
 */
#define SPI_CLK_POL    SPI_CLK_POL_IDLE_LOW
/*
 *  choose from :
 *  SPI_CLK_PHASE_SAMPLE_FIRST
 *  SPI_CLK_PHASE_SAMPLE_LAST
 */
#define SPI_CLK_PHASE   SPI_CLK_PHASE_SAMPLE_FIRST
/*
 *  choose from :
 *  SPI_DATA_ORDER_MSB_FIRST
 *  SPI_DATA_ORDER_LSB_FIRST
 */
#define SPI_DATA_ORDER   SPI_DATA_ORDER_LSB_FIRST


#endif /* SPI_SPI_CONFIG_H_ */
