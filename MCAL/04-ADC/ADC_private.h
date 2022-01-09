/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						26 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: ADC Driver                                                        							                      *
* ! File Name	: ADC_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

//************************************************************************************************************************************/
/***************************************************** Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/******************************************************* ADC Mux Register ************************************************************/

#define ADCMUX         						*((volatile uint8 *)0x27)						// ADC Mux Register

#define ADCMUX_MUX0    						0												// MUX Bit 0
#define ADCMUX_MUX1    						1                                               // MUX Bit 1
#define ADCMUX_MUX2    						2                                               // MUX Bit 2
#define ADCMUX_MUX3    						3                                               // MUX Bit 3
#define ADCMUX_MUX4    						4                                               // MUX Bit 4
#define ADCMUX_ADLAR   						5                                               // ADC Left Adjust Bit
#define ADCMUX_REFS0   						6                                               // ADC Reference Selection Bit 0
#define ADCMUX_REFS1   						7                                               // ADC Reference Selection Bit 1

#define AREF           						0												//AREF, Internal Vref turned off															
#define AVCC           						1												//AVCC with external capacitor at AREF pin
#define INTERNAL_2_56_VOLT    				2												/*Internal 2.56V Voltage Reference 
																							  with external capacitor at AREF pin*/
#define CHANNEL_MASK    					0b11100000										//Channel mask Register
					
/*********************************************** ADC Control and Status Register ****************************************************/

#define ADCSRA  							*((volatile uint8 *)0x26)						// ADC Control and Status Register
	
#define ADCSRA_ADPS0						0                                               // ADC Prescaler Selection Bit 0
#define ADCSRA_ADPS1						1                                               // ADC Prescaler Selection Bit 1
#define ADCSRA_ADPS2						2                                               // ADC Prescaler Selection Bit 2
#define ADCSRA_ADIE     					3                                               // ADC Interrupt Enable
#define ADCSRA_ADIF     					4                                               // ADC Interrupt Flag
#define ADCSRA_ADATE    					5                                               // ADC Auto Trigger Enable
#define ADCSRA_ADSC     					6                                               // ADC Start Conversion
#define ADCSRA_ADEN     					7                                               // ADC Enable Bit

#define PRESCALER_MASK     					0b11111000										//Prescaler Register mask
#define FLAG_NOT_FIRED						0

#define DIVIDE_BY_2        					0b001											//Division Factor = 2   
#define DIVIDE_BY_4        					0b010											//Division Factor = 4   
#define DIVIDE_BY_8        					0b011											//Division Factor = 8   
#define DIVIDE_BY_16       					0b100											//Division Factor = 16  
#define DIVIDE_BY_32       					0b101											//Division Factor = 32  
#define DIVIDE_BY_64       					0b110											//Division Factor = 64  
#define DIVIDE_BY_128      					0b111											//Division Factor = 128 

/***************************************************** ADC Data Registers **********************************************************/

#define ADCH    							*((volatile uint8 *)0x25)						// ADC Low Data Byte
#define ADCL    							*((volatile uint8 *)0x24)                       // ADC High Data Byte
#define ADC_L_H    							*((volatile uint16 *)0x24)                      // ADC Data Low adn High

/********************************************** ADC Special FunctionIO Register ****************************************************/

#define SFIOR    							*((volatile uint8 *)0x50)						//Special FunctionIO Register

#define SFIOR_ADTS0     					5											    //ADC Auto Trigger Source Bit 0
#define SFIOR_ADTS1     					6											    //ADC Auto Trigger Source Bit 1
#define SFIOR_ADTS2     					7											    //ADC Auto Trigger Source Bit 2

#define TRIGGER_SOURCE_MASK					0b00011111										//Trigger source Register mask

#define FREE_RUNNING_MODE					0b000											//Free running mode			
#define ANALOG_COMPARATOR                   0b001											//Analog comparator            
#define EXTERNAL_INTERRUPT_REQUEST0         0b010											//External interrupt request0  
#define TIMER_COUNTER0_COMPARE_MATCH        0b011											//Timer counter0 compare match 
#define TIMER_COUNTER0_OVERFLOW             0b100											//Timer counter0 overflow      
#define TIMER_COUNTER_COMPARE_MATCH_B       0b101											//Timer counter  compare match b
#define TIMER_COUNTER1_OVERFLOW             0b110											//Timer counter1 overflow      
#define TIMER_COUNTER1_CAPTURE_EVENT        0b111											//Timer counter1 capture event 


#endif /*ADC_PRIVATE_H*/