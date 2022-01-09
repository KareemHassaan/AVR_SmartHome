/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						21 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Stepper Motor Driver                                                        							              *
* ! File Name	: STEPPER_M_private.h                                                     							                  *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                  						                                         							      *
**************************************************************************************************************************************/
#ifndef STEPPER_M_PRIVATE_H
#define STEPPER_M_PRIVATE_H

/*Macro to convert time from sec to millisec*/
#define STEPPER_M_1K						0x03EBUL
/*Macro for the single rotation 360*/
#define STEPPER_M_Single_ROTATION			0x0168UL

#endif /*STEPPER_M_PRIVATE_H*/