/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						20 DEC,2021 				- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: RELAY SWITCH Driver                                                        							              *
* ! File Name	: RELAY_SWITCH_program.c                                                       							              *
* ! Description : This file has the implementation of Basic of RELAY SWITCH functions        							                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                   						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
/************************************************** Lower Layer Inclusions ***********************************************************/
#include"../../MCAL/01-DIO/DIO_intrface.h"
/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
/*Must be with that order maybe change Private with config only*/
#include"RELAY_SWITCH_intrface.h"  
#include"RELAY_SWITCH_private.h"
#include"RELAY_SWITCH_config.h"


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: H_RELAY_SWITCH_VoidInit																	                      *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to initialize the pin of the switch to output									                      *
**************************************************************************************************************************************/
void H_RELAY_SWITCH_VoidInit()
{
	/*Setting the RELAY Switch Pin output*/
	MDIO_voidSetPinDirection(RELAY_SWITCH_PORT, RELAY_SWITCH_PIN,OUTPUT);
}

/**************************************************************************************************************************************
* Function Name		: H_RELAY_SWITCH_VoidSetSwitch_ON															                      *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Switch ON									                        					      *
**************************************************************************************************************************************/
void H_RELAY_SWITCH_VoidSetSwitch_ON()
{
	
	/*Setting the RELAY Switch NPN ON*/
	MDIO_voidSetPinValue(RELAY_SWITCH_PORT, RELAY_SWITCH_PIN,HIGH);
}

/**************************************************************************************************************************************
* Function Name		: H_RELAY_SWITCH_VoidSetSwitch_OFF															                      *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Switch OFF									                        					  *
**************************************************************************************************************************************/
void H_RELAY_SWITCH_VoidSetSwitch_OFF()
{

	/*Setting the RELAY Switch NPN OFF*/
	MDIO_voidSetPinValue(RELAY_SWITCH_PORT, RELAY_SWITCH_PIN,LOW);
	
}