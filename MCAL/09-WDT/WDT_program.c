/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						03 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: WDT Driver                                                        							                      *
* ! File Name	: WDT_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of WDT functions        							                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
/************************************************** Lower Layer Inclusions ***********************************************************/

/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
/*Must be with that order maybe change Private with config only*/
#include"WDT_intrface.h"  
#include"WDT_private.h"
#include"WDT_config.h"

/***************************************************** Global Variables **************************************************************/


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MWDT_VoidWDTEnable																		                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Enable The Watch Dog Timer													  									                      *
**************************************************************************************************************************************/
void MWDT_VoidWDTEnable()
{
	/*Set The WDE Bit to Enable WDT*/
	 SET_BIT(WDTCR,WDTCR_WDE);
}
/**************************************************************************************************************************************
* Function Name		: MWDT_VoidWDTDisable																		                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Disable The Watch Dog Timer													                      *
**************************************************************************************************************************************/
void MWDT_VoidWDTDisable()
{
	/*Write One To WDTOE And WDE The Same Operation*/
	 WDTCR = (TURN_DISABLE_ON << WDTCR_WDTOE)|(DISABLE_WDT << WDTCR_WDE);
	/*Within The Next Four CLK Cycles, Wite 0 To The WDE Bit*/
	 WDTCR = WDTCR_CLEAR;
}
/**************************************************************************************************************************************
* Function Name		: MWDT_VoidWDTSleep																			                      *
* Parameters (in)	: Copy_uint8SleepTime																		                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Sleep The Watch Dog Timer					  									                      *
**************************************************************************************************************************************/
void MWDT_VoidWDTSleep(uint8 Copy_uint8SleepTime)
{
	SET_SPECIFIC_REG_BITS_VALUE(WDTCR,WDT_PRESCALLER_MASK,Copy_uint8SleepTime);
	
}