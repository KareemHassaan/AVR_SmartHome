/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						22 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: INTERRUPT Driver                                                     							                      *
* ! File Name	: EXTI_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/******************************************************** EXTI Registers *************************************************************/

/***************************************************** MCU Control Register **********************************************************/

#define MCUCR  			*((volatile uint8 *)0x55)  					

#define MCUCR_ISC00 	0             												//Interupt0 signal control Bit0
#define MCUCR_ISC01 	1															//Interupt0 signal control Bit1
#define MCUCR_ISC10 	2             												//Interupt1 signal control Bit0
#define MCUCR_ISC11 	3															//Interupt1 signal control Bit1

/************************************************ MCU Control and status Register ****************************************************/

#define MCUCSR  		*((volatile uint8 *)0x54)  					
	
#define MCUCR_ISC2		6															//Interupt2 signal control Bit

/********************************************** Global Interrupt Control Register ****************************************************/

#define GICR  			*((volatile uint8 *)0x5B)  					

#define GICR_INT2 		5             												//Interupt2 Enable
#define GICR_INT0 		6															//Interupt0 Enable
#define GICR_INT1 		7             												//Interupt1 Enable

/********************************************** Global Interrupt Flag Register *******************************************************/

#define GIFR  			*((volatile uint8 *)0x5A) 					

#define GIFR_INTF2 		5             												//Interupt2 Flag
#define GIFR_INTF0 		6															//Interupt0 Flag
#define GIFR_INTF1 		7             												//Interupt1 Flag
	
#define ISR_NUM 		3

#endif /*EXTI_PRIVATE_H*/