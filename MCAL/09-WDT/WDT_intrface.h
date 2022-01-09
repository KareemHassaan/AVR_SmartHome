/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						03 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: WDT Driver                                                        							                      *                     
* ! File Name	: WDT_intrface.h                                                     							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

#define WDT_16K_16_3_ms		 0b000														//Option Sleeping Time 16.3 msec
#define WDT_32K_32_5_ms      0b001														//Option Sleeping Time 32.5 msec
#define WDT_64K_65_ms        0b010														//Option Sleeping Time 65   msec
#define WDT_128K_0_13_s      0b011														//Option Sleeping Time 0.13  sec
#define WDT_256K_0_26_s      0b100														//Option Sleeping Time 0.26  sec
#define WDT_512K_0_52_s      0b101														//Option Sleeping Time 0.52  sec
#define WDT_1024K_1_0_s      0b110														//Option Sleeping Time 1.00  sec
#define WDT_2048K_2_1_s      0b111														//Option Sleeping Time 2.10  sec

/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MWDT_VoidWDTEnable																		                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Enable The Watch Dog Timer													  									                      *
**************************************************************************************************************************************/
void MWDT_VoidWDTEnable();
/**************************************************************************************************************************************
* Function Name		: MWDT_VoidWDTDisable																		                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Disable The Watch Dog Timer													  									                      *
**************************************************************************************************************************************/
void MWDT_VoidWDTDisable();
/**************************************************************************************************************************************
* Function Name		: MWDT_VoidWDTSleep																			                      *
* Parameters (in)	: Copy_uint8SleepTime																		                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Sleep The Watch Dog Timer													  									                      *
**************************************************************************************************************************************/
void MWDT_VoidWDTSleep(uint8 Copy_uint8SleepTime);

#endif /*WDT_INTERFACE_H*/