/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						21 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Stepper Motor Driver                                     							                                  *
* ! File Name	: STEPPER_M_config.h                                                      							                  *
* ! Description : This file has the Configrations needed		     		        	 						                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                   						                                         							  *
**************************************************************************************************************************************/
#ifndef STEPPER_M_CONFIG_H
#define STEPPER_M_CONFIG_H

/************************************************* Stepper Motor Port ****************************************************************/
#define STEPPER_M_PORT						PORTA

/************************************************* Stepper Motor Pins ****************************************************************/
#define STEPPER_M_PIN0						PIN0
#define STEPPER_M_PIN1						PIN1
#define STEPPER_M_PIN2						PIN2
#define STEPPER_M_PIN3						PIN3

/********************************************* Stepper Motor Steps Number ************************************************************/
#define STEPS_NUM_FOR_360Deg				0x0800UL






#endif /*STEPPER_M_CONFIG_H*/  