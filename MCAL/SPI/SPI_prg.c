/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/
#include "STD.h"
#include "BitMath.h"
#include "SPI_priv.h"
#include "SPI_config.h"
#include "SPI_int.h"

void M_SPI_void_masterInit(void)
{
	// step 1 : enable SPI and enable MSTr mode
	SPCR_REG = (1<<SPE_BIT)|(1<<MSTR_BIT);
	// step 2 : data order
#if( SPI_DATA_ORDER  == SPI_DATA_ORDER_LSB_FIRST)
	SET_BIT(SPCR_REG, DORD_BIT);
#else
	CLR_BIT(SPCR_REG, DORD_BIT);
#endif
	// step 3 : clk polarity
#if(SPI_CLK_POL  ==  SPI_CLK_POL_IDLE_LOW)
	CLR_BIT(SPCR_REG,CPOL_BIT);
#else
	SET_BIT(SPCR_REG,CPOL_BIT);
#endif
	// step 4 : clk phase
#if(SPI_CLK_PHASE  ==  SPI_CLK_PHASE_SAMPLE_FIRST)
	CLR_BIT(SPCR_REG, CPHA_BIT);
#else
	SET_BIT(SPCR_REG, CPHA_BIT);
#endif
	// step 5 : speed mode
#if(SPI_SPEED_MODE   == SPI_SPEED_MODE_NORMAL)
	CLR_BIT(SPSR_REG , SPI2X_BIT);
#else
	SET_BIT(SPSR_REG , SPI2X_BIT);
#endif
	// step 6 : prescaler
	SPCR_REG &= SPI_PRESCALER_MASK;
	SPCR_REG |= SPI_PRESCALER ;


}
void M_SPI_void_slaveInit(void)
{
	//step 1 : enable SPI and enable slave mode
	SPCR_REG = (1<<SPE_BIT);
	CLR_BIT(SPCR_REG , MSTR_BIT);
	// step 2 : data order
	#if( SPI_DATA_ORDER  == SPI_DATA_ORDER_LSB_FIRST)
		SET_BIT(SPCR_REG, DORD_BIT);
	#else
		CLR_BIT(SPCR_REG, DORD_BIT);
	#endif
		// step 3 : clk polarity
	#if(SPI_CLK_POL  ==  SPI_CLK_POL_IDLE_LOW)
		CLR_BIT(SPCR_REG,CPOL_BIT);
	#else
		SET_BIT(SPCR_REG,CPOL_BIT);
	#endif
		// step 4 : clk phase
	#if(SPI_CLK_PHASE  ==  SPI_CLK_PHASE_SAMPLE_FIRST)
		CLR_BIT(SPCR_REG, CPHA_BIT);
	#else
		SET_BIT(SPCR_REG, CPHA_BIT);
	#endif
}
u8 M_SPI_u8_transfereByte(u8 copy_u8data)
{
    SPDR_REG = copy_u8data;  // write data to be transfered
    while(GET_BIT(SPSR_REG,SPIF_BIT) == 0); // wait until data is transfered
    return SPDR_REG ; // return data received
}
