/******************************************************************************************************************
* LOG:                                               														      *
* VERSION				AUTHOR           				DATE 				DESCRIPTION        				  	  *
* 1.0.0 				Kareem Hassaan					8 Dec,2021			- Initial Creation				  	  *
* 1.1.0 				  ~      ~						14 Dec,2021			- Changing Specific Port functions    *
******************************************************************************************************************/
/******************************************************************************************************************
* ! Title      	: DIO Driver                                                        							  *
* ! File Name	: DIO_private.h                                                     							  *
* ! Description : This file has the Private definitions needed				       							      *
* ! Compiler  	: GNU AVR cross Compiler                                            							  *
* ! Target 	  	: Atmega32 Micro-Controller                                         							  *
* ! Layer 	  	: MCAL						                                         							  *
******************************************************************************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

//****************************************************************************************************************/
/******************************************* Registers Memory Map ************************************************/
/*****************************************************************************************************************/

/********************************************** DIO Registers ****************************************************/

#define DIO_DDRA  *((volatile uint8 *)0x3A)
#define DIO_PORTA *((volatile uint8 *)0x3B)
#define DIO_PINA  *((volatile uint8 *)0x39)

#define DIO_DDRB  *((volatile uint8 *)0x37)
#define DIO_PORTB *((volatile uint8 *)0x38)
#define DIO_PINB  *((volatile uint8 *)0x36)

#define DIO_DDRC  *((volatile uint8 *)0x34)
#define DIO_PORTC *((volatile uint8 *)0x35)
#define DIO_PINC  *((volatile uint8 *)0x33)

#define DIO_DDRD  *((volatile uint8 *)0x31)
#define DIO_PORTD *((volatile uint8 *)0x32)
#define DIO_PIND  *((volatile uint8 *)0x30)

#endif /*DIO_PRIVATE_H*/