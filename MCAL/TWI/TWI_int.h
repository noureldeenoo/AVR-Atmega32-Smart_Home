/************************  All copyrights are reserved  **************************/
/*********************************************************************************/
/* Author    : NourEldeen                                                        */
/* Email     : noureldeen.m.abdalla@gmail.com                                    */                            
/* Version   : V01                                                               */
/* Date      : August 2022                                                       */
/*********************************************************************************/

#ifndef TWI_TWI_INT_H_
#define TWI_TWI_INT_H_

// Master Tx
#define TWI_MT_START_SUCCESS            0x08
#define TWI_MT_REPEATED_START_SUCCESS   0x10
#define TWI_MT_SLA_W_ACK                0x18
#define TWI_MT_SLA_W_NOACK              0x20
#define TWI_MT_DATA_ACK                 0x28   // I received ACK
#define TWI_MT_DATA_NOACK               0x30   // I received NO ACK
#define TWI_MT_ARBITRATION_LOST         0x38

//Master Rx
#define TWI_MR_START_SUCCESS            0x08
#define TWI_MR_REPEATED_START_SUCCESS   0x10
#define TWI_MR_SLA_R_ACK                0x40
#define TWI_MR_SLA_R_NOACK              0x48
#define TWI_MR_DATA_ACK                 0x50   // I will send ACK
#define TWI_MR_DATA_NOACK               0x58   // I will send no ACK
#define TWI_MR_ARBITRATION_LOST         0x38

void M_TWI_void_Init(void);
void M_TWI_void_sendByte(u8 copy_u8data);
void M_TWI_void_sendStart(void);
void M_TWI_void_sendStop(void);
void M_TWI_void_receiveByte_ACK(u8 * ptr);
void M_TWI_void_receiveByte_NoACK(u8 * ptr);
u8 M_TWI_u8_getStatus(void);

#endif /* TWI_TWI_INT_H_ */
