/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						28 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: TIMERS Driver                                     							                                      *
* ! File Name	: TIMERS_config.h                                                      							                      *
* ! Description : This file has the Configrations needed		     		        	 						                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H
/*************************************************************************************************************************************/
/**************************************************** TIMER0 CONFIGRATIONS ***********************************************************/
/*************************************************************************************************************************************/

/**************************************************************************************************************************************
* MACRO		: 	To Turn Timer0 on or off 																                              *
* options	:	ENABLE		/		DISABLE						  																	  *
**************************************************************************************************************************************/
#define TIMER0_ENABLE 									DISABLE
/**************************************************************************************************************************************
* MACRO		: 	To Turn Timer0 Interrupt on or off 																                      *
* options	:	ENABLE		/		DISABLE						  																	  *
**************************************************************************************************************************************/
#define TIMER0_INT_ENABLE 								DISABLE
/**************************************************************************************************************************************
* MACRO		: 	To choose Timer0 Mode																                              	  *
* options	:	NORMAL_MODE		/		PWM_PHASE_CORRECT_MODE		/		CTC_MODE		/		FAST_PWM_MODE					  *
**************************************************************************************************************************************/
#define TIMER0_MODE 									CTC_MODE
/**************************************************************************************************************************************
* MACRO						: 	To choose Timer0 PWM And CTC Modes 																      *
*																																	  *
* options in CTC			:	NORMAL_MODE_OC0_DISCONNECTED		/		TOGGLE_OC0_ON_COMPARE_MATCH						/		  * 						  	
*								CLEAR_OC0_ON_COMPARE_MATCH			/		SET_OC0_ON_COMPARE_MATCH							      *
*																																	  * 
* options in Fast PWM		:	NORMAL_MODE_OC0_DISCONNECTED		/		CLEAR_OC0_ON_COMPARE_MATCH_SET_OC0_AT_TOP		/		  *				
*		  						SET_OC0_ON_COMPARE_MATCH_CLEAR_OC0_AT_TOP															  *
*																																	  *
* options in Phase correct	:	NORMAL_MODE_OC0_DISCONNECTED		/		CLEAR_OC0_UP_COUNTING_SET_OC0_DOWNCOUNTING		/		  *
*						  		SET_OC0_UP_COUNTING_CLEAR_OC0_DOWNCOUNTING															  *
**************************************************************************************************************************************/
#define TIMER0_CTC_PWM_MODES_VALUE 						NORMAL_MODE_OC0_DISCONNECTED
/**************************************************************************************************************************************
* MACRO		: 	To choose Timer0 Prescaller 																                          *
* options	:	T0_NO_CLOCK_SOURCE	   /	T0_NO_PRESCALING		/	      T0_DIVIDE_BY_8		 /		T0_DIVIDE_BY_64			/ *
*				T0_DIVIDE_BY_256	   /	T0_DIVIDE_BY_1024		/	  T0_EXT_CLK_FALLING_EDGE_T0 /	T0_EXT_CLK_RISING_EDGE_T0	  *
**************************************************************************************************************************************/
#define TIMER0_PRESCALLER_VALUE							T0_DIVIDE_BY_8


/*************************************************************************************************************************************/
/**************************************************** TIMER1 CONFIGRATIONS ***********************************************************/
/*************************************************************************************************************************************/

/**************************************************************************************************************************************
* MACRO		: 	To Turn Timer1 on or off 																                              *
* options	:	ENABLE		/		DISABLE						  																	  *
**************************************************************************************************************************************/
#define TIMER1_ENABLE 									ENABLE
/**************************************************************************************************************************************
* MACRO		: 	To Turn Timer1 channel A on or off 																                      *
* options	:	ENABLE		/		DISABLE						  																	  *
**************************************************************************************************************************************/
#define TIMER1_Channel_A_ENABLE 						ENABLE
/**************************************************************************************************************************************
* MACRO		: 	To Turn Timer1 channel B on or off 																                      *
* options	:	ENABLE		/		DISABLE						  																	  *
**************************************************************************************************************************************/
#define TIMER1_Channel_B_ENABLE 						DISABLE
/**************************************************************************************************************************************
* MACRO		: 	To Turn Timer1 ICU on or off 																                          *
* options	:	ENABLE		/		DISABLE						  																	  *
**************************************************************************************************************************************/
#define TIMER1_ICU_ENABLE 								DISABLE
/**************************************************************************************************************************************
* MACRO		: 	To Turn Timer1 channel A Interrupt on or off 																          *
* options	:	ENABLE		/		DISABLE						  																	  *
**************************************************************************************************************************************/
#define TIMER1_Channel_A_INT_ENABLE 					DISABLE
/**************************************************************************************************************************************
* MACRO		: 	To Turn Timer1 channel B Interrupt on or off 																          *
* options	:	ENABLE		/		DISABLE						  																	  *
**************************************************************************************************************************************/
#define TIMER1_Channel_B_INT_ENABLE 					DISABLE
/**************************************************************************************************************************************
* MACRO		: 	To Turn Timer1 ICU Interrupt on or off 																         		  *
* options	:	ENABLE		/		DISABLE						  																	  *
**************************************************************************************************************************************/
#define TIMER1_ICU_INT_ENABLE 							DISABLE
/**************************************************************************************************************************************
* MACRO		: To choose Timer1 Mode																                              	  	  *
* options	: TCCR1B_NORMAL_0XFFFF_IMMEDIATE_MAX					/		TCCR1B_PWM_PHASE_CORRECT_8_BIT_0X00FF_TOP_BOTTOM	 /	  *	
*			  TCCR1B_PWM_PHASE_CORRECT_9_BIT_0X01FF_TOP_BOTTOM		/		TCCR1B_PWM_PHASE_CORRECT_10_BIT_0X03FF_TOP_BOTTOM	 /	  *
*			  TCCR1B_CTC_OCR1A_IMMEDIATE_MAX						/		TCCR1B_FAST_PWM_8_BIT_0X00FF_TOP_TOP				 /	  *
*			  TCCR1B_FAST_PWM_9_BIT_0X01FF_TOP_TOP					/		TCCR1B_FAST_PWM_10_BIT_0X03FF_TOP_TOP					  *
*			  TCCR1B_PWM_PHASE_AND_FREQUENCY_CORRECT_ICR1_BOTTOM_BOTTOM	/ TCCR1B_PWM_PHASE_AND_FREQUENCY_CORRECT_OCR1A_BOTTOM_BOTTOM /*					  *
*			  TCCR1B_PWM_PHASE_CORRECT_ICR1_TOP_BOTTOM				/		TCCR1B_PWM_PHASE_CORRECT_OCR1A_TOP_BOTTOM			 /	  *
*			  TCCR1B_CTC_ICR1_IMMEDIATE_MAX							/		TCCR1B_RESERVED					  					 /    *
*			  TCCR1B_FAST_PWM_ICR1_TOP_TOP							/		TCCR1B_FAST_PWM_OCR1A_TOP_TOP					     /    *
**************************************************************************************************************************************/
#define TIMER1_TCCR1A_MODE  							TCCR1A_FAST_PWM_ICR1_TOP_TOP
#define TIMER1_TCCR1B_MODE 								TCCR1B_FAST_PWM_ICR1_TOP_TOP
/**************************************************************************************************************************************
* MACRO						: To choose Timer1 Channel A PWM And CTC Modes 														      *
*																																	  *
* options in CTC			: NORMAL_OC1A_DISCONNECTED			/			TOGGLE_OC1A_ON_COMPARE_MATCH						   /  * 						  	
*							  CLEAR_OC1A_ON_COMPARE_MATCH		/			SET_OC1A_ON_COMPARE_MATCH							      *
*																																      * 
* options in Fast PWM		: NORMAL_OC1A_DISCONNECTED			/	  WITH_MODE_15_TOGGLE_OC1A_ON_COMPARE_MATCH_OC1B_DISCONNECTED  /  *				
*		  					  CLEAR_OC1A_ON_COMPARE_MATCH_SET_OC1A_AT_TOP     / 	SET_OC1A_ON_COMPARE_MATCH_CLEAR_OC1A_AT_TOP		  *
*																																      *
* options in Phase correct	: NORMAL_OC1A_DISCONNECTED		   /	WITH_MODE_15_TOGGLE_OC1A_ON_COMPARE_MATCH_OC1B_DISCONNECTED	   /  *
*						  	  CLEAR_OC1A_ON_UP_COUNTING_SET_OC1A_ON_DOWNCOUNTING / SET_OC1A_ON_UP_COUNTING_CLEAR_OC1A_ON_DOWNCOUNTING *														  *
**************************************************************************************************************************************/
#define TIMER1_Channel_A_CTC_PWM_MODES_VALUE 			CLEAR_OC1A_ON_COMPARE_MATCH_SET_OC1A_AT_TOP	
/**************************************************************************************************************************************
* MACRO						: To choose Timer1 Channel B PWM And CTC Modes 													          *
*																																	  *
* options in CTC			: NORMAL_OC1B_DISCONNECTED			/			TOGGLE_OC1B_ON_COMPARE_MATCH						    / * 						  	
*							  CLEAR_OC1B_ON_COMPARE_MATCH		/			SET_OC1B_ON_COMPARE_MATCH							      *
*																																	  * 
* options in Fast PWM		: NORMAL_OC1B_DISCONNECTED			/	FC_WITH_MODE_15_TOGGLE_OC1A_ON_COMPARE_MATCH_OC1B_DISCONNECTED	/ *				
*		  					  CLEAR_OC1B_ON_COMPARE_MATCH_SET_OC1B_AT_TOP		/  SET_OC1B_ON_COMPARE_MATCH_CLEAR_OC1B_AT_TOP		  *
*																																	  *
* options in Phase correct	: NORMAL_OC1B_DISCONNECTED			/	FC_WITH_MODE_15_TOGGLE_OC1A_ON_COMPARE_MATCH_OC1B_DISCONNECTED	/ *
*						  	  CLEAR_OC1B_ON_UP_COUNTING_SET_OC1B_ON_DOWNCOUNTING / SET_OC1B_ON_UP_COUNTING_CLEAR_OC1B_ON_DOWNCOUNTING *
**************************************************************************************************************************************/			
#define TIMER1_Channel_B_CTC_PWM_MODES_VALUE 			NORMAL_OC1B_DISCONNECTED	
	
/**************************************************************************************************************************************
* MACRO		: 	To choose Timer1 Prescaller 																                          *
* options	:	T1_No_clock_source	   /	T1_DIVIDE_BY_1			/	      T1_DIVIDE_BY_8		 /		T1_DIVIDE_BY_64			/ *
*				T1_DIVIDE_BY_256	   /	T1_DIVIDE_BY_1024		/	  T1_EXT_CLK_FALLING_EDGE_T1 /	T1_EXT_CLK_RISING_EDGE_T1	  *
**************************************************************************************************************************************/
#define TIMER1_PRESCALLER_VALUE							T1_DIVIDE_BY_8


/*************************************************************************************************************************************/
/**************************************************** TIMER2 CONFIGRATIONS ***********************************************************/
/*************************************************************************************************************************************/

/**************************************************************************************************************************************
* MACRO		: 	To Turn Timer2 on or off 																                              *
* options	:	ENABLE		/		DISABLE						  																	  *
**************************************************************************************************************************************/
#define TIMER2_ENABLE 									ENABLE
/**************************************************************************************************************************************
* MACRO		: 	To Turn Timer2 Interrupt on or off 																                      *
* options	:	ENABLE		/		DISABLE						  																	  *
**************************************************************************************************************************************/
#define TIMER2_INT_ENABLE 								ENABLE
/**************************************************************************************************************************************
* MACRO		: 	To choose Timer2 Mode																                              	  *
* options	:	NORMAL_MODE		/		PWM_PHASE_CORRECT_MODE		/		CTC_MODE		/		FAST_PWM_MODE					  *
**************************************************************************************************************************************/
#define TIMER2_MODE 									CTC_MODE
/**************************************************************************************************************************************
* MACRO						: 	To choose Timer2 PWM And CTC Modes 																      *
*																																	  *
* options in CTC			:	NORMAL_MODE_OC2_DISCONNECTED		/		TOGGLE_OC2_ON_COMPARE_MATCH						/		  * 						  	
*								CLEAR_OC2_ON_COMPARE_MATCH			/		SET_OC2_ON_COMPARE_MATCH							      *
*																																	  * 
* options in Fast PWM		:	NORMAL_MODE_OC2_DISCONNECTED		/		CLEAR_OC2_ON_COMPARE_MATCH_SET_OC2_AT_TOP		/		  *				
*		  						SET_OC2_ON_COMPARE_MATCH_CLEAR_OC2_AT_TOP															  *
*																																	  *
* options in Phase correct	:	NORMAL_MODE_OC2_DISCONNECTED		/		CLEAR_OC2_UP_COUNTING_SET_OC2_DOWNCOUNTING		/		  *
						  		SET_OC2_UP_COUNTING_CLEAR_OC2_DOWNCOUNTING															  *
**************************************************************************************************************************************/
#define TIMER2_CTC_PWM_MODES_VALUE 						NORMAL_MODE_OC0_DISCONNECTED
/**************************************************************************************************************************************
* MACRO		: 	To choose Timer2 Prescaller 																                          *
* options	:	T2_NO_CLOCK_SOURCE	   /	T2_NO_PRESCALING		/	      T2_DIVIDE_BY_8		 /		T2_DIVIDE_BY_32		 /    *
*				T2_DIVIDE_BY_64	  	   /	T2_DIVIDE_BY_128		/	 	 T2_DIVIDE_BY_256 		 /		T2_DIVIDE_BY_1024	      *
**************************************************************************************************************************************/
#define TIMER2_PRESCALLER_VALUE							T2_DIVIDE_BY_8
 
#endif /*TIMERS_CONFIG_H*/  