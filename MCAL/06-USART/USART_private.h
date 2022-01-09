/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						30 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: USART Driver                                                        							                      *
* ! File Name	: USART_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/************************************************** USART I/O Data Register **********************************************************/

#define UDR  									*((volatile uint8 *)0x2C)						//USART I/O Data Register

/******************************************** USART Control and Status Register A ****************************************************/

#define UCSRA  									*((volatile uint8 *)0x2B)						//USART Control and Status Register A
	
#define UCSRA_MPCM								0												//Multi-processor Communication Mode
#define UCSRA_U2X								1												//Double the USART Transmission Speed
#define UCSRA_PE								2												//Parity Error
#define UCSRA_DOR								3												//Data OverRun
#define UCSRA_FE								4												//Frame Error
#define UCSRA_UDRE								5												//USART Data Register Empty
#define UCSRA_TXC								6												//USART Transmit Complete
#define UCSRA_RXC								7												//USART Receive Complete 

/******************************************** USART Control and Status Register B ****************************************************/
	
#define UCSRB  									*((volatile uint8 *)0x2A)						//USART Control and Status Register B
	
#define UCSRB_TXB8								0												//Transmit Data Bit 8
#define UCSRB_RXB8								1												//Receive Data Bit 8
#define UCSRB_UCSZ2								2												//Character Size Bit 2
#define UCSRB_TXEN								3												//Transmitter Enable
#define UCSRB_RXEN								4												//Receiver Enable
#define UCSRB_UDRIE								5												//USART Data Register Empty Interrupt Enable
#define UCSRB_TXCIE								6												//TX Complete Interrupt Enable
#define UCSRB_RXCIE								7												//RX Complete Interrupt Enable

/******************************************** USART Control and Status Register C ****************************************************/

#define UCSRC  									*((volatile uint8 *)0x40)						//USART Control and Status Register C

#define UCSRC_UCPOL								0												//Clock Polarity
#define UCSRC_UCSZ0								1												//Character Size Bit 0
#define UCSRC_UCSZ1								2												//Character Size Bit 1
#define UCSRC_USBS								3												//Stop Bit Select
#define UCSRC_UPM0								4												//Parity Mode Bit 0
#define UCSRC_UPM1								5												//Parity Mode Bit 1
#define UCSRC_UMSEL								6												//USART Mode Select(Sync-Async)
#define UCSRC_URSEL								7												//Register Select

#define UCSRC_SELECT							1												//To Select UCSRC

/************************************************* USART Baud Rate Registers ********************************************************/
	
#define UBRR  									*((volatile uint16 *)0x29)						//USART Baud Rate Registers
#define UBRRL  									*((volatile uint8 *)0x29)						//USART Baud Rate Registers Low
#define UBRRH  									*((volatile uint8 *)0x40)						//USART Baud Rate Registers High
#define UBRRH_URSEL  							7												//Register Select

/******************************************************* USART Modes ****************************************************************/

#define NORMAL_SPEED							0												//USART Normal speed Mode
#define DOUBLE_SPEED							1												//USART Double speed Mode

#define ASYNCHRONOUS_OPERATION					0												//USART Asynchronous Operation Mode
#define SYNCHRONOUS_OPERATION					1												//USART Synchronous Operation Mode

#define PARITY_DISABLED							0b00											//USART Parity Error Check Disabled
#define EVEN_PARITY    							0b10											//USART Even Parity Error Check
#define ODD_PARITY     							0b11											//USART Odd Parity Error Check

#define SINGLE_STOP_BIT							0												//USART Single Stop Bit
#define DOUBLE_STOP_BIT							1												//USART Double Stop Bit

#define UCSRC_DATA_SIZE_5_BIT					0b00											//USART Data Size 5 Bit Mode
#define UCSRC_DATA_SIZE_6_BIT         			0b01											//USART Data Size 6 Bit Mode
#define UCSRC_DATA_SIZE_7_BIT         			0b10											//USART Data Size 7 Bit Mode
#define UCSRC_DATA_SIZE_8_BIT         			0b11											//USART Data Size 8 Bit Mode
#define UCSRC_DATA_SIZE_9_BIT           		0b11											//USART Data Size 9 Bit Mode


#define TX_RISING_EDGE_RX_FALLING_EDGE			0												//Clock Ploarity Adjustment
#define TX_FALLING_EDGE_RX_RISING_EDGE			1												//Clock Ploarity Adjustment

#define NINTH_BIT 								8												//Macro to Bit 8 in 9-Bit Mode

#define USART_ISR_NUM							3												//Number of USART ISR

#endif /*USART_PRIVATE_H*/