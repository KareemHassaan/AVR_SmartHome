/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						20 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Optocoupler Switch Driver                                                        							          *
* ! File Name	: Optocoupler_Switch_program.c                                                       							      *
* ! Description : This file has the implementation of Basic of Optocoupler Switch functions        				                      *
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
#include"Optocoupler_Switch_intrface.h"  
#include"Optocoupler_Switch_private.h"
#include"Optocoupler_Switch_config.h"


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: Optocoupler_Switch_VoidInit																	                  *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to initialize the pin of the switch to output									                      *
**************************************************************************************************************************************/
void Optocoupler_Switch_VoidInit()
{
	/*Setting the Optocoupler Switch Pin output*/
	MDIO_voidSetPinDirection(OPTOCOUPLER_SWITCH_PORT, OPTOCOUPLER_SWITCH_PIN,OUTPUT);
}

/**************************************************************************************************************************************
* Function Name		: Optocoupler_Switch_VoidSetSwitch_ON															                  *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Switch ON									                        					      *
**************************************************************************************************************************************/
void Optocoupler_Switch_VoidSetSwitch_ON()
{

	/*Setting the Optocoupler Switch NPN ON*/
	MDIO_voidSetPinValue(OPTOCOUPLER_SWITCH_PORT, OPTOCOUPLER_SWITCH_PIN,HIGH);

}

/**************************************************************************************************************************************
* Function Name		: Optocoupler_Switch_VoidSetSwitch_OFF															                  *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Switch OFF									                        					  *
**************************************************************************************************************************************/
void Optocoupler_Switch_VoidSetSwitch_OFF()
{
	
	/*Setting the Optocoupler Switch NPN OFF*/
	MDIO_voidSetPinValue(OPTOCOUPLER_SWITCH_PORT, OPTOCOUPLER_SWITCH_PIN,LOW);

}