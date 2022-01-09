/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						04 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: TWI Driver                                                        							                      *
* ! File Name	: TWI_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/**************************************************** TWI Data Registers *************************************************************/

#define TWDR							*((volatile uint8 *)(0x23))			//TWI Data Register
#define	TWDR_TWD0						0									//TWI Read/Write Request
	
/**************************************************** TWI Address Registers **********************************************************/
	
#define TWAR							*((volatile uint8 *)(0x22))			//TWI Address Register
#define	TWAR_TWGCE						0									//TWI Global Call Enable

/**************************************************** TWI Status Registers ***********************************************************/
	
#define TWSR							*((volatile uint8 *)(0x21))			//TWI Status Register
#define TWSR_TWPS0						0									//TWI Prescaler bit0
#define TWSR_TWPS1						1                                   //TWI Prescaler bit1
	
/**************************************************** TWI Control Registers **********************************************************/
	
#define TWCR							*((volatile uint8 *)(0x56))			//TWI Control Register
#define	TWCR_TWIE						0									//TWI Interrupt Enable
#define	TWCR_TWEN						2									//TWI Enable
#define	TWCR_TWWC						3									//TWI Write Collision Flag
#define	TWCR_TWSTO						4									//TWI Stop Condition
#define	TWCR_TWSTA						5									//TWI Start Condition
#define	TWCR_TWEA						6									//TWI Enable Acknowledge
#define	TWCR_TWINT						7									//TWI Interrupt Flag

/**************************************************** TWI Bit Rate Registers *********************************************************/
	
#define TWBR							*((volatile uint8 *)(0x20))			//  TWI Bit Rate Register

/******************************************************** Acknowledges ***************************************************************/

#define START_ACK                		0x08 								//start has been sent 
#define REP_START_ACK            		0x10 								//repeated start 
#define SLAVE_ADD_AND_WR_ACK     		0x18 								//Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_RD_ACK     		0x40 								//Master transmit ( slave address + Read request ) ACK 
#define MSTR_WR_BYTE_ACK         		0x28 								//Master transmit data ACK 
#define MSTR_RD_BYTE_WITH_ACK    		0x50 								//Master received data with ACK 
#define MSTR_RD_BYTE_WITH_NACK   		0x58 								//Master received data with not ACK 
#define SLAVE_ADD_RCVD_RD_REQ    		0xA8 								//means that slave address is received with read request 
#define SLAVE_ADD_RCVD_WR_REQ    		0x60 								//means that slave address is received with write request 
#define SLAVE_DATA_RECEIVED      		0x80 								//means that a byte is received 
#define SLAVE_BYTE_TRANSMITTED   		0xB8 								//means that the written byte is transmitted 

/************************************************************ Masks ******************************************************************/

#define STATUS_CODE_MASK				0b11111000
#define ACK_ENABLE_MASK					0b10111111
#define PRESCALLER_MASK					0b11111100

/******************************************************* Prescallers Values **********************************************************/

#define PRESCALLER_1					0b00000000
#define PRESCALLER_4                    0b00000001
#define PRESCALLER_16                   0b00000010
#define PRESCALLER_64                   0b00000011

#define EQU_CONSTANT16					16.0
#define EQU_CONSTANT2					2.0
#define EQU_CONSTANT4					4.0
#define KILO							1000

/***************************************************** Acknowledges Values ***********************************************************/

#define ACK_ENABLE						0b01000000
#define ACK_DISABLE						0b00000000


#endif /* TWI_PRIVATE_H_ */
