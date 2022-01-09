/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						26 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: ADC Driver                                     							                                          *
* ! File Name	: ADC_config.h                                                      							                      *
* ! Description : This file has the Configrations needed		     		        	 						                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/**************************************************************************************************************************************
* MACRO		: 	To Eneable and Disable the ADC               													                      *
* options	:	ENABLE	 	/		DISABLE						                      												  *
**************************************************************************************************************************************/
#define ADC_ENABLE 				ENABLE

/**************************************************************************************************************************************
* MACRO		: 	To Choose the Refrence Voltage Source															                      *
* options	:	AREF	   /		    AVCC		     /		INTERNAL_2_56_VOLT                                           		  *
**************************************************************************************************************************************/
#define ADC_REF_SELECTION 		AVCC

/**************************************************************************************************************************************
* MACRO		: 	To Choose the Prescaller Division Factor															                  *
* options	:	DIVIDE_BY_2	 /		 DIVIDE_BY_4		  /		DIVIDE_BY_8		/		DIVIDE_BY_16 		/     DIVIDE_BY_32	  /   *
				DIVIDE_BY_64 /		DIVIDE_BY_128													                                  *
**************************************************************************************************************************************/
#define ADC_PRESCALER_VALUE		DIVIDE_BY_128

/**************************************************************************************************************************************
* MACRO		: 	To Choose the Trigger Source															                              *
* options	:	FREE_RUNNING_MODE	 		  /		ANALOG_COMPARATOR		  	/		EXTERNAL_INTERRUPT_REQUEST0			/	      *
				TIMER_COUNTER0_COMPARE_MATCH  /		TIMER_COUNTER0_OVERFLOW		/		TIMER_COUNTER_COMPARE_MATCH_B 		/	      *
				TIMER_COUNTER1_OVERFLOW		  /		TIMER_COUNTER1_CAPTURE_EVENT													  *
**************************************************************************************************************************************/
#define ADC_TRIGGER_SOURCE 		FREE_RUNNING_MODE

#endif /*ADC_CONFIG_H*/  