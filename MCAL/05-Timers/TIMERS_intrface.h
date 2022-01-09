/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						28 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: TIMERS Driver                                                        							                      *                     
* ! File Name	: TIMERS_intrface.h                                                     							                  *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

#define TIMER0				0													//Macro to choose Timer 0
#define TIMER1				1													//Macro to choose Timer 1
#define TIMER2				2													//Macro to choose Timer 2

#define OVERFLOW			0													//Macro to choose Timer X mode Overflow
#define CTC					1													//Macro to choose Timer X mode CTC
#define CTC_CH_A			1													//Macro to choose Timer 1 mode CTC channel A
#define CTC_CH_B			2													//Macro to choose Timer 1 mode CTC channel B
#define ICU					3													//Macro to choose Timer 1 mode Input Capture Unit

#define FALLING_EDGE 		0													//Macro to choose ICU To Sense on Falling Edge
#define RISING_EDGE 		1													//Macro to choose ICU To Sense on Rising Edge

#define	ENABLE  			1													//Macro To Enable			
#define	DISABLE  			0													//Macro To Disable

/***********************************************************************************************************************************************/
/***************************************************** Timer0 Functions Prototypes *************************************************************/
/***********************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: MTIMERS_VoidTimer0Init 																	                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialize All Timer0	Configrations.		     								                      *
**************************************************************************************************************************************/
void MTIMERS_VoidTimer0Init();
/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer0SetPreloadValue 																	          *
* Parameters (in)	: Copy_uint8PreloadValue																						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Preload Value to Start Count From it. 					  					              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer0SetPreloadValue(uint8 Copy_uint8PreloadValue);
/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer0SetCompareMatchValue 																	      *
* Parameters (in)	: Copy_u8CompareMatchValue																						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Compare Valve to match with it. 					  					                      *
**************************************************************************************************************************************/
void MTIMERS_voidTimer0SetCompareMatchValue(uint8 Copy_u8CompareMatchValue);
/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidSetBusyWait 																	                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set Busy time as a Delay. 					  					       				              *
**************************************************************************************************************************************/
void MTIMERS_voidSetBusyWait(uint32 Copy_u32MilliSeconds);

/***********************************************************************************************************************************************/
/***************************************************** Timer1 Functions Prototypes *************************************************************/
/***********************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: MTIMERS_VoidTimer1Init 																	                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialize All Timer1	Configrations.		     								                      *
**************************************************************************************************************************************/
void MTIMERS_VoidTimer1Init();
/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer1SetPreloadValue 																	          *
* Parameters (in)	: Copy_uint16PreloadValue																						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Preload Value to Start Count From it. 					  					              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer1SetPreloadValue(uint16 Copy_uint16PreloadValue);
/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer1SetTopValue 																	              *
* Parameters (in)	: Copy_uint8PreloadValue																						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Top Valve of the Timer.		 					  					                      *
**************************************************************************************************************************************/
void MTIMERS_voidTimer1SetTopValue(uint16 Copy_uint8PreloadValue);
/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer1SetChannelACompareMatchValue 																  *
* Parameters (in)	: Copy_uint16CompareMatchValue																					  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Channel A  Compare Valve to match with it.        					  		              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer1SetChannelACompareMatchValue(uint16 Copy_uint16CompareMatchValue);
/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer1SetChannelBCompareMatchValue 																  *
* Parameters (in)	: Copy_uint16CompareMatchValue																					  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Channel B Compare Valve to match with it.       			  					              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer1SetChannelBCompareMatchValue(uint16 Copy_uint16CompareMatchValue);
/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer1ICUSetSenseSignal			 																  *
* Parameters (in)	: Copy_uint16CompareMatchValue																					  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set Sense Signal to ICU.       			  											              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer1ICUSetSenseSignal(uint16 Copy_uint8SignalValue);
/**************************************************************************************************************************************
* Function Name		: MTIMERS_uint16Timer1GetICR1Value				 																  *
* Parameters (in)	: Copy_uint16CompareMatchValue																					  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Get ICR1.											       			  					              *
**************************************************************************************************************************************/
uint16 MTIMERS_uint16Timer1GetICR1Value();
/**************************************************************************************************************************************
* Function Name		: MTIMERS_uint16Timer1GICUInterruptControl				 														  *
* Parameters (in)	: Copy_uint16CompareMatchValue																					  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Get ICR1.											       			  					              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer1GICUInterruptControl(uint8 Copy_uint8InterruptState);

/***********************************************************************************************************************************************/
/***************************************************** Timer2 Functions Prototypes *************************************************************/
/***********************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: MTIMERS_VoidTimer2Init 																	                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialize All Timer2	Configrations.		     								                      *
**************************************************************************************************************************************/
void MTIMERS_VoidTimer2Init();
/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer2SetPreloadValue 																	          *
* Parameters (in)	: Copy_uint8PreloadValue																						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Preload Value to Start Count From it. 					  					              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer2SetPreloadValue(uint8 Copy_uint8PreloadValue);
/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer2SetCompareMatchValue 																	      *
* Parameters (in)	: Copy_u8CompareMatchValue																						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Compare Valve to match with it.       					  					              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer2SetCompareMatchValue(uint8 Copy_u8CompareMatchValue);

/***********************************************************************************************************************************************/
/***************************************************** Set_CBK Function Prototypes *************************************************************/
/***********************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidSetCallBack 																	                      *
* Parameters (in)	: uint8 Copy_uint8TimerNum, uint8 Copy_uint8TimerISRType, void (*Copy_pvCallbackFunction)(void))				  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set Function to the ISR of the Timer          					  					              *
**************************************************************************************************************************************/
void MTIMERS_voidSetCallBack(uint8 Copy_uint8TimerNum, uint8 Copy_uint8TimerISRType, void (*Copy_pvCallbackFunction)(void));

#endif /*TIMERS_INTERFACE_H*/