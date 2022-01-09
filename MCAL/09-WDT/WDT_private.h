/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						03 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: WDT Driver                                                        							                      *
* ! File Name	: WDT_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: XXXX                  						                                         							  *
**************************************************************************************************************************************/
#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/******************************************************** WDT Registers **************************************************************/

#define WDTCR  					*((volatile uint8 *)0x41)							//Watchdog Timer Control Register

#define WDTCR_WDP0				0													//Watchdog Turn-off Enable
#define WDTCR_WDP1				1													//Watchdog Enable
#define WDTCR_WDP2				2													//Watchdog Timer Prescaler Bit 2
#define WDTCR_WDE				3													//Watchdog Timer Prescaler Bit 1
#define WDTCR_WDTOE    			4													//Watchdog Timer Prescaler Bit 0

#define WDT_PRESCALLER_MASK 	0b11111000											//Prescaller Mask Value

#define WDTCR_CLEAR 			0x00												//Value To Clear WDTCR Reg

#define TURN_DISABLE_ON 		1													//Value To Turn ON WDT Disable
#define DISABLE_WDT 			1													//Value To Disable WDT

#endif /*WDT_PRIVATE_H*/