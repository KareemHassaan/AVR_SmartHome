/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						22 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: General Interrupt Enable Driver                                              					                      *
* ! File Name	: GIE_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of GIE functions        							                      *
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
#include"GIE_intrface.h"  
#include"GIE_private.h"
#include"GIE_config.h"

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MGIE_voidGlobalInterruptEnable																	              *
* Parameters (in)	: None					                      																	  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Enable the Global interrupt													                      *
**************************************************************************************************************************************/
void MGIE_voidGlobalInterruptEnable()
{
	/*Enabling the Global interrupt*/
	SET_BIT(SREG, SREG_I);
}

/**************************************************************************************************************************************
* Function Name		: MGIE_voidGlobalInterruptDisable																	              *
* Parameters (in)	: None					                      																	  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Disable the Global interrupt													                      *
**************************************************************************************************************************************/
void MGIE_voidGlobalInterruptDisable()
{
	/*Disabling the Global interrupt*/
	CLR_BIT(SREG, SREG_I);
}