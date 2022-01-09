/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						20 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Transistor Switch Driver                                     							                              *
* ! File Name	: TRANS_SWITCH_config.h                                                      							              *
* ! Description : This file has the Configrations needed		     		        	 						                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                    						                                         							  *
**************************************************************************************************************************************/
#ifndef TRANS_SWITCH_CONFIG_H
#define TRANS_SWITCH_CONFIG_H

#define TRANSISTOR_TYPE 	TRANS_SWITCH_NPN

#define  TRANS_SWITCH_NPN	0x00
#define  TRANS_SWITCH_PNP	0x01


#define TRANS_SWITCH_PORT 	PORTA
#define TRANS_SWITCH_PIN 	PIN0

#endif /*TRANS_SWITCH_CONFIG_H*/  