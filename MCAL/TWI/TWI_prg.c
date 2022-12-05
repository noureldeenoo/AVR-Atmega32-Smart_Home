/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#include "STD.h"
#include "BitMath.h"
#include "TWI_priv.h"
#include "TWI_config.h"
#include "TWI_int.h"

void M_TWI_void_Init(void)
{
	// prescaler  =  1
	CLR_BIT(TWSR_REG,TWPS1_BIT);
	CLR_BIT(TWSR_REG,TWPS0_BIT);

	// Bit Rate  fCPU = 8 MHz, prescaler = 1 , SCL = 400 kHz
	TWBR_REG = 0x02;
    // Enable TWI
	SET_BIT(TWCR_REG,TWEN_BIT);
}

void M_TWI_void_sendStart(void)
{
	// send start + clear flag + Enable TWI
	TWCR_REG = (1<<TWINT_BIT)|(1<<TWSTA_BIT)|(1<<TWEN_BIT);
	// wait until job is done
	while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);

}
void M_TWI_void_sendStop(void)
{
	// send stop + clear flag + Enable TWI
	TWCR_REG = (1<<TWINT_BIT)|(1<<TWEN_BIT)| (1<<TWSTO_BIT);

}
void M_TWI_void_sendByte(u8 copy_u8data)
{
	//load data to be sent to  data register (SLA+R/W or msg)
	TWDR_REG = copy_u8data;
	// clear flag + Enable TWI
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT);
	// wait until job is done
	while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);
}
void M_TWI_void_receiveByte_ACK(u8 * ptr)
{
	// clear flag , enable TWI , Enable ACK
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT) | (1<< TWEA_BIT);
	// wait until job is done
	while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);

	// return data
	*ptr =  TWDR_REG;


}
void M_TWI_void_receiveByte_NoACK(u8 * ptr)
{
	// clear ACK enable
	CLR_BIT(TWCR_REG,TWEA_BIT);
	// clear flag , enable TWI
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT);

	// wait until job is done
		while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);
	// return data
	*ptr =  TWDR_REG;
}
u8 M_TWI_u8_getStatus(void)
{

   return (TWSR_REG & TWI_STATUS_MASK);
}
