/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						20 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: H-Bridge By Transistor Driver                                     							                      *
* ! File Name	: H_BRIDGE_TRANS_config.h                                                      							              *
* ! Description : This file has the Configrations needed		     		        	 						                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                   						                                         							  *
**************************************************************************************************************************************/
#ifndef H_BRIDGE_TRANS_CONFIG_H
#define H_BRIDGE_TRANS_CONFIG_H

#define TRANSISTOR_PIN1_TYPE 		TRANS_SWITCH_NPN
#define TRANSISTOR_PIN2_TYPE 		TRANS_SWITCH_NPN

#define  TRANS_SWITCH_NPN			0x00
#define  TRANS_SWITCH_PNP			0x01

#define TRANS_H_BRIDGE_PIN1_PORT	PORTA
#define TRANS_H_BRIDGE_PIN2_PORT	PORTA

#define TRANS_H_BRIDGE_PIN1			PIN0
#define	TRANS_H_BRIDGE_PIN2			PIN1

#endif /*H_BRIDGE_TRANS_CONFIG_H*/  