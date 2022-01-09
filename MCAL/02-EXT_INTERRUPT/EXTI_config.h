/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						22 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: INTERRUPT Driver                                     						                                          *
* ! File Name	: EXTI_config.h                                                      							                      *
* ! Description : This file has the Configrations needed		     		        	 						                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/**************************************************************************************************************************************
* MACRO		: 	To Eneable and Disable the External Interupts													                      *
* options	:	ENABLE	 	/		DISABLE						                      												  *
**************************************************************************************************************************************/
#define EXTI_INT0_ENABLE ENABLE
#define EXTI_INT1_ENABLE DISABLE
#define EXTI_INT2_ENABLE DISABLE

/**************************************************************************************************************************************
* MACRO		: 	To Choose the Interrupt Sense Control															                      *
* options	:	FALLING_EDGE	 /		RISING_EDGE		/		ON_CHANGE		/		LOW_LEVEL             						  *
**************************************************************************************************************************************/
#define EXTI_INT0_SENSE_SIGNAL FALLING_EDGE
#define EXTI_INT1_SENSE_SIGNAL ON_CHANGE
#define EXTI_INT2_SENSE_SIGNAL RISING_EDGE









#endif /*EXTI_CONFIG_H*/  