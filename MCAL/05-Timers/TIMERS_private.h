/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						28 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: TIMERS Driver                                                        							                      *
* ! File Name	: TIMERS_private.h                                                     							                      *
* ! Description : This file has the Private definitions needed				       							                          *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

/*************************************************************************************************************************************/
/****************************************************  Registers Memory Map **********************************************************/
/*************************************************************************************************************************************/

/*************************************************************************************************************************************/
/****************************************************** Common Registers *************************************************************/
/*************************************************************************************************************************************/

/******************************************* Timer/Counter Interrupt Mask Register ***************************************************/

#define TIMSK							*((volatile uint8 *)0x59)						// Timer/Counter Interrupt Mask Register
#define	TIMSK_TOIE0						0												// Timer 0 Overflow Interrupt Enable
#define	TIMSK_OCIE0						1												// Timer 0 Output Compare Interrupt Enable
#define	TIMSK_TOIE1						2												// Timer 1 Overflow Interrupt Enable
#define	TIMSK_OCIE1B					3												// Timer 1 Channel B Output Compare Interrupt Enable
#define	TIMSK_OCIE1A					4												// Timer 1 Channel A Output Compare Interrupt Enable
#define	TIMSK_TICIE1					5												// Timer 1 Input Capture Interrupt Enable
#define	TIMSK_TOIE2						6												// Timer 2 Overflow Interrupt Enable
#define	TIMSK_OCIE2						7												// Timer 2 Output Compare Interrupt Enable

/******************************************* Timer/Counter Interrupt Flags Register **************************************************/
	
#define TIFR							*((volatile uint8 *)0x58)						// Timer/Counter Interrupt Interrupt Flags
#define	TIFR_TOV0						0												// Timer 0 Overflow Flag
#define	TIFR_OCF0						1												// Timer 0 Output Compare Flag
#define	TIFR_TOV1						2												// Timer 1 Overflow Flag
#define	TIFR_OCF1B						3												// Timer 1 Channel B Output Compare Flag
#define	TIFR_OCF1A						4												// Timer 1 Channel A Output Compare Flag
#define TIFR_ICF1						5												// Timer 1 Input Capture Flag
#define	TIFR_TOV2						6												// Timer 2 Overflow Flag
#define	TIFR_OCF2						7												// Timer 2 Output Compare Flag

#define	ENABLE  						1												//Macro for Enable	
#define	DISABLE  						0												//Macro For Disable
	
#define	TIMER0_ISR_NUM  				2												//Number of Timer0 ISR
#define	TIMER1_ISR_NUM  				4												//Number of Timer1 ISR	
#define	TIMER2_ISR_NUM  				2												//Number of Timer2 ISR	

/*************************************************************************************************************************************/
/****************************************************** TIMER0 Registers *************************************************************/
/*************************************************************************************************************************************/

/********************************************* Timer/Counter 0 Control Register ******************************************************/

#define TCCR0  							*((volatile uint8 *)0x53)						// Timer/Counter 0 Control Register					
	
#define TCCR0_CS00	  					0												// Timer 0 Clock Selection bit 0			
#define TCCR0_CS01    					1                                               // Timer 0 Clock Selection bit 1
#define TCCR0_CS02    					2                                               // Timer 0 Clock Selection bit 2
#define TCCR0_WGM01   					3                                               // Timer 0 Wave Generation Mode bit 0
#define TCCR0_COM00   					4                                               // Timer 0 Compare Output Mode bit 0
#define TCCR0_COM01   					5                                               // Timer 0 Compare Output Mode bit 1
#define TCCR0_WGM00   					6                                               // Timer 0 Wave Generation Mode bit 1
#define TCCR0_FOC0    					7                                               // Timer 0 Force Output Compar

/************************************************* Timer/Counter 0 Register **********************************************************/	
	
#define TCNT0  							*((volatile uint8 *)0x52)						// Timer/Counter 0 Register

/***************************************** Timer/Counter 0 Output Compare Register ***************************************************/	

#define OCR0   							*((volatile uint8 *)0x5C)						// Timer/Counter 0 Output Compare Register

/************************************************* Timer/Counter 0 Modes *************************************************************/	

#define	NORMAL_MODE  										1							//Normal Mode		
#define	PWM_PHASE_CORRECT_MODE  							2							//PWM Phase Correct	
#define	CTC_MODE  											3							//Clear on compare Match mode
#define	FAST_PWM_MODE  										4							//Fast PWM Mode

/************************************************ Timer/Counter 0 CTC Modes **********************************************************/
	
#define	NORMAL_MODE_OC0_DISCONNECTED 						0b00000000					//NORMAL MODE OC0 DISCONNECTED	
#define	TOGGLE_OC0_ON_COMPARE_MATCH  						0b00010000					//TOGGLE OC0 ON COMPARE MATCH 		
#define	CLEAR_OC0_ON_COMPARE_MATCH  						0b00100000					//CLEAR C0_ON_COMPARE MATCH  		
#define	SET_OC0_ON_COMPARE_MATCH  	    					0b00110000					//SET OC0 ON COMPARE MATCH  	

/********************************************* Timer/Counter 0 Fast PWM Modes ********************************************************/

#define	NORMAL_MODE_OC0_DISCONNECTED						0b00000000					//NORMAL MODE OC0 DISCONNECTED						
#define	CLEAR_OC0_ON_COMPARE_MATCH_SET_OC0_AT_TOP  	    	0b00100000					//CLEAR OC0 ON COMPARE MATCH SET OC0 AT TOP	
#define	SET_OC0_ON_COMPARE_MATCH_CLEAR_OC0_AT_TOP  			0b00110000					//SET OC0 ON COMPARE MATCH CLEAR OC0 AT TOP

/****************************************** Timer/Counter 0 PWM Correct Phase Modes **************************************************/

#define	NORMAL_MODE_OC0_DISCONNECTED  						0b00000000					//NORMAL MODE OC0 DISCONNECTED  								
#define	CLEAR_OC0_UP_COUNTING_SET_OC0_DOWNCOUNTING  		0b00100000					//CLEAR OC0 UP COUNTING SET OC0 DOWNCOUNTING		
#define	SET_OC0_UP_COUNTING_CLEAR_OC0_DOWNCOUNTING  		0b00110000					//SET OC0 UP COUNTING CLEAR OC0 DOWNCOUNTING

/******************************************* Timer/Counter 0 Prescaller Values *******************************************************/

#define T0_NO_CLOCK_SOURCE	    							0b00000000					//NO CLOCK SOURCE	    	
#define T0_NO_PRESCALING	    							0b00000001					//NO PRESCALING	    	
#define T0_DIVIDE_BY_8    									0b00000010					//DIVIDE BY 8    			
#define T0_DIVIDE_BY_64    									0b00000011					//DIVIDE BY 64    			
#define T0_DIVIDE_BY_256    								0b00000100					//DIVIDE BY 256    		
#define T0_DIVIDE_BY_1024    								0b00000101					//DIVIDE BY 1024    		
#define T0_EXT_CLK_FALLING_EDGE_T0    						0b00000110					//EXT CLK FALLING EDGE T0
#define T0_EXT_CLK_RISING_EDGE_T0    						0b00000111					//EXT CLK RISING EDGE T0 

#define TIMER0_CTC_PWM_MODES_MASK							0b11001111					//Timer 0 PWM & CTC Modes Mask
#define TIMER0_PRESCALLER_MASK	    						0b11111000					//Timer 0 Prescaller Mask


/*************************************************************************************************************************************/
/******************************************************* TIMER1 Registers ************************************************************/
/*************************************************************************************************************************************/

/******************************************* Timer/Counter1 Control Register A *******************************************************/

#define TCCR1A  						*((volatile uint8 *)0x4F)						//Timer/Counter1 Control Register A

#define TCCR1A_WGM10					0												//Waveform Generation Mode Bit 0
#define TCCR1A_WGM11					1												//Waveform Generation Mode Bit 1
#define TCCR1A_FOC1B					2												//Force Output Compare for Channel B
#define TCCR1A_FOC1A					3												//Force Output Compare for Channel A
#define TCCR1A_COM1B0					4												//Compare Output Mode for Channel B Bit 0
#define TCCR1A_COM1B1					5												//Compare Output Mode for Channel B Bit 1
#define TCCR1A_COM1A0					6												//Compare Output Mode for Channel A Bit 0
#define TCCR1A_COM1A1					7												//Compare Output Mode for Channel A Bit 1

/******************************************* Timer/Counter1 Control Register B *******************************************************/

#define TCCR1B  						*((volatile uint8 *)0x4E)						//Timer/Counter1 Control Register B

#define TCCR1B_CS10	  					0												// Timer 0 Clock Selection bit 0
#define TCCR1B_CS11    					1                                               // Timer 0 Clock Selection bit 1
#define TCCR1B_CS12    					2												//Timer 0 Clock Selection bit 2
#define TCCR1B_WGM12					3												//Waveform Generation Mode Bit 2
#define TCCR1B_WGM13					4												//Waveform Generation Mode Bit 3

#define TCCR1B_ICES1					6												//Input Capture Edge Select
#define TCCR1B_ICNC1					7												//Input Capture Noise Canceler

/**************************************************** Timer/Counter1 *****************************************************************/

#define TCNT1  							*((volatile uint16 *)0x4C)

/************************************************ Output Compare Register 1 A ********************************************************/

#define OCR1A  							*((volatile uint16 *)0x4A)

/************************************************ Output Compare Register 1 B ********************************************************/

#define OCR1B  							*((volatile uint16 *)0x48)

/************************************************ Input Capture Register 1 ***********************************************************/

#define ICR1  							*((volatile uint16 *)0x46)

/*************************************** Timer/Counter 0 Modes Values For TCCR1A *****************************************************/

#define TCCR1A_NORMAL_0XFFFF_IMMEDIATE_MAX										0b00000000
#define TCCR1A_PWM_PHASE_CORRECT_8_BIT_0X00FF_TOP_BOTTOM                        0b00000001
#define TCCR1A_PWM_PHASE_CORRECT_9_BIT_0X01FF_TOP_BOTTOM                        0b00000010
#define TCCR1A_PWM_PHASE_CORRECT_10_BIT_0X03FF_TOP_BOTTOM                       0b00000011
#define TCCR1A_CTC_OCR1A_IMMEDIATE_MAX                                          0b00000000
#define TCCR1A_FAST_PWM_8_BIT_0X00FF_TOP_TOP                                    0b00000001
#define TCCR1A_FAST_PWM_9_BIT_0X01FF_TOP_TOP                                    0b00000010
#define TCCR1A_FAST_PWM_10_BIT_0X03FF_TOP_TOP                                   0b00000011
#define TCCR1A_PWM_PHASE_AND_FREQUENCY_CORRECT_ICR1_BOTTOM_BOTTOM               0b00000000
#define TCCR1A_PWM_PHASE_AND_FREQUENCY_CORRECT_OCR1A_BOTTOM_BOTTOM              0b00000001
#define TCCR1A_PWM_PHASE_CORRECT_ICR1_TOP_BOTTOM                                0b00000010
#define TCCR1A_PWM_PHASE_CORRECT_OCR1A_TOP_BOTTOM                               0b00000011
#define TCCR1A_CTC_ICR1_IMMEDIATE_MAX                                           0b00000000
#define TCCR1A_RESERVED                                                         0b00000001
#define TCCR1A_FAST_PWM_ICR1_TOP_TOP                                            0b00000010
#define TCCR1A_FAST_PWM_OCR1A_TOP_TOP                                           0b00000011

/*************************************** Timer/Counter 0 Modes Values For TCCR1B *****************************************************/

#define TCCR1B_NORMAL_0XFFFF_IMMEDIATE_MAX										0b00000000
#define TCCR1B_PWM_PHASE_CORRECT_8_BIT_0X00FF_TOP_BOTTOM                        0b00000000
#define TCCR1B_PWM_PHASE_CORRECT_9_BIT_0X01FF_TOP_BOTTOM                        0b00000000
#define TCCR1B_PWM_PHASE_CORRECT_10_BIT_0X03FF_TOP_BOTTOM                       0b00000000
#define TCCR1B_CTC_OCR1A_IMMEDIATE_MAX                                          0b00001000
#define TCCR1B_FAST_PWM_8_BIT_0X00FF_TOP_TOP                                    0b00001000
#define TCCR1B_FAST_PWM_9_BIT_0X01FF_TOP_TOP                                    0b00001000
#define TCCR1B_FAST_PWM_10_BIT_0X03FF_TOP_TOP                                   0b00001000
#define TCCR1B_PWM_PHASE_AND_FREQUENCY_CORRECT_ICR1_BOTTOM_BOTTOM               0b00010000
#define TCCR1B_PWM_PHASE_AND_FREQUENCY_CORRECT_OCR1A_BOTTOM_BOTTOM              0b00010000
#define TCCR1B_PWM_PHASE_CORRECT_ICR1_TOP_BOTTOM                                0b00010000
#define TCCR1B_PWM_PHASE_CORRECT_OCR1A_TOP_BOTTOM                               0b00010000
#define TCCR1B_CTC_ICR1_IMMEDIATE_MAX                                           0b00011000
#define TCCR1B_RESERVED                                                         0b00011000
#define TCCR1B_FAST_PWM_ICR1_TOP_TOP                                            0b00011000
#define TCCR1B_FAST_PWM_OCR1A_TOP_TOP                                           0b00011000

/******************************************* Timer/Counter 1 Channel A CTC Modes *****************************************************/

#define NORMAL_OC1A_DISCONNECTED												0b00000000
#define TOGGLE_OC1A_ON_COMPARE_MATCH                                            0b01000000
#define CLEAR_OC1A_ON_COMPARE_MATCH                                             0b10000000
#define SET_OC1A_ON_COMPARE_MATCH                                               0b11000000

/*************************************** Timer/Counter 1 Channel A  Fast PWM Modes ****************************************************/

#define NORMAL_OC1A_DISCONNECTED                                                0b00000000
#define WITH_MODE_15_TOGGLE_OC1A_ON_COMPARE_MATCH_OC1B_DISCONNECTED             0b01000000
#define CLEAR_OC1A_ON_COMPARE_MATCH_SET_OC1A_AT_TOP                             0b10000000
#define SET_OC1A_ON_COMPARE_MATCH_CLEAR_OC1A_AT_TOP                             0b11000000

/************************************ Timer/Counter 1 Channel A  PWM Correct Phase Modes **********************************************/

#define NORMAL_OC1A_DISCONNECTED                                                0b00000000
#define WITH_MODE_15_TOGGLE_OC1A_ON_COMPARE_MATCH_OC1B_DISCONNECTED         	0b01000000
#define CLEAR_OC1A_ON_UP_COUNTING_SET_OC1A_ON_DOWNCOUNTING                      0b10000000
#define SET_OC1A_ON_UP_COUNTING_CLEAR_OC1A_ON_DOWNCOUNTING                      0b11000000

/******************************************* Timer/Counter 1 Channel B CTC Modes *****************************************************/

#define NORMAL_OC1B_DISCONNECTED												0b00000000
#define TOGGLE_OC1B_ON_COMPARE_MATCH                                            0b00010000
#define CLEAR_OC1B_ON_COMPARE_MATCH                                             0b00100000
#define SET_OC1B_ON_COMPARE_MATCH                                               0b00110000

/*************************************** Timer/Counter 1 Channel B  Fast PWM Modes ****************************************************/

#define NORMAL_OC1B_DISCONNECTED                                                0b00000000
#define FC_WITH_MODE_15_TOGGLE_OC1A_ON_COMPARE_MATCH_OC1B_DISCONNECTED          0b00010000
#define CLEAR_OC1B_ON_COMPARE_MATCH_SET_OC1B_AT_TOP                             0b00100000
#define SET_OC1B_ON_COMPARE_MATCH_CLEAR_OC1B_AT_TOP                             0b00110000

/************************************ Timer/Counter 1 Channel B  PWM Correct Phase Modes **********************************************/

#define NORMAL_OC1B_DISCONNECTED                                                0b00000000
#define FC_WITH_MODE_15_TOGGLE_OC1A_ON_COMPARE_MATCH_OC1B_DISCONNECTED          0b00010000
#define CLEAR_OC1B_ON_UP_COUNTING_SET_OC1B_ON_DOWNCOUNTING                      0b00100000
#define SET_OC1B_ON_UP_COUNTING_CLEAR_OC1B_ON_DOWNCOUNTING                      0b00110000

/******************************************* Timer/Counter 1 Prescaller Values *******************************************************/

#define T1_No_clock_source 														0b00000000
#define T1_DIVIDE_BY_1                                                          0b00000001
#define T1_DIVIDE_BY_8                                                          0b00000010
#define T1_DIVIDE_BY_64                                                         0b00000011
#define T1_DIVIDE_BY_256                                                        0b00000100
#define T1_DIVIDE_BY_1024                                                       0b00000101
#define T1_EXT_CLK_FALLING_EDGE_T1                                              0b00000110
#define T1_EXT_CLK_RISING_EDGE_T1                                               0b00000111

#define TIMER1_TCCR1A_MODE_MASK													0b11111100			//Timer 1 Mode Mask TCCR1A
#define TIMER1_TCCR1B_MODE_MASK													0b11100111	        //Timer 1 Mode Mask TCCR1B

#define TIMER1_Channel_A_CTC_PWM_MODES_MASK										0b00111111			//Timer 1 Channel A PWM & CTC Modes Mask 
#define TIMER1_Channel_B_CTC_PWM_MODES_MASK										0b11001111			//Timer 1 Channel B PWM & CTC Modes Mask 

#define TIMER1_PRESCALLER_MASK	    											0b11111000			//Timer 1 Prescaller Mask


/*************************************************************************************************************************************/
/******************************************************* TIMER2 Registers ************************************************************/
/*************************************************************************************************************************************/

/*********************************************** Timer/Counter 2 Control Register ****************************************************/

#define TCCR2  											*((volatile uint8 *)0x45)				// Timer/Counter 2 Control Register					

#define TCCR2_CS20	  									0										// Timer 2 Clock Selection bit 0			
#define TCCR2_CS21    									1                                       // Timer 2 Clock Selection bit 1
#define TCCR2_CS22    									2                                       // Timer 2 Clock Selection bit 2
#define TCCR2_WGM21   									3                                       // Timer 2 Wave Generation Mode bit 0
#define TCCR2_COM20   									4                                       // Timer 2 Compare Output Mode bit 0
#define TCCR2_COM21   									5                                       // Timer 2 Compare Output Mode bit 1
#define TCCR2_WGM20   									6                                       // Timer 2 Wave Generation Mode bit 1
#define TCCR2_FOC2    									7                                       // Timer 2 Force Output Compar
	
/************************************************* Timer/Counter 2 Register **********************************************************/	
	
#define TCNT2  											*((volatile uint8 *)0x44)				// Timer/Counter 2 Register

/***************************************** Timer/Counter 2 Output Compare Register ***************************************************/

#define OCR2   											*((volatile uint8 *)0x43)				// Timer/Counter 2 Output Compare Register

/************************************************* Timer/Counter 2 Modes *************************************************************/	
	
#define	NORMAL_MODE  									1			
#define	PWM_PHASE_CORRECT_MODE  						2			
#define	CTC_MODE  										3			
#define	FAST_PWM_MODE  									4

/************************************************ Timer/Counter 2 CTC Modes **********************************************************/
	
#define	NORMAL_MODE_OC2_DISCONNECTED 					0b00000000			
#define	TOGGLE_OC2_ON_COMPARE_MATCH  					0b00010000			
#define	CLEAR_OC2_ON_COMPARE_MATCH  					0b00100000			
#define	SET_OC2_ON_COMPARE_MATCH  	    				0b00110000			

/********************************************* Timer/Counter 2 Fast PWM Modes ********************************************************/

#define	NORMAL_MODE_OC2_DISCONNECTED					0b00000000				
#define	CLEAR_OC2_ON_COMPARE_MATCH_SET_OC2_AT_TOP  	    0b00100000		
#define	SET_OC2_ON_COMPARE_MATCH_CLEAR_OC2_AT_TOP  		0b00110000		

/****************************************** Timer/Counter 2 PWM Correct Phase Modes **************************************************/

#define	NORMAL_MODE_OC2_DISCONNECTED  					0b00000000					
#define	CLEAR_OC2_UP_COUNTING_SET_OC2_DOWNCOUNTING  	0b00100000			
#define	SET_OC2_UP_COUNTING_CLEAR_OC2_DOWNCOUNTING  	0b00110000

/******************************************* Timer/Counter 2 Prescaller Values *******************************************************/

#define T2_NO_CLOCK_SOURCE	    						0b00000000
#define T2_NO_PRESCALING	    						0b00000001
#define T2_DIVIDE_BY_8    								0b00000010
#define T2_DIVIDE_BY_32    								0b00000011
#define T2_DIVIDE_BY_64    								0b00000100
#define T2_DIVIDE_BY_128    							0b00000101
#define T2_DIVIDE_BY_256      							0b00000110
#define T2_DIVIDE_BY_1024      							0b00000111

#define TIMER2_CTC_PWM_MODES_MASK						0b11001111									//Timer 1 PWM & CTC Modes Mask
#define TIMER2_PRESCALLER_MASK	    					0b11111000									//Timer 2 Prescaller Mask

#endif /*TIMERS_PRIVATE_H*/
