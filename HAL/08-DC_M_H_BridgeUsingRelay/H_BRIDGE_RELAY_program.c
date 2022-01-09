/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						20 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: H_BRIDGE_RELAY Driver                                                        							              *
* ! File Name	: H_BRIDGE_RELAY_program.c                                                       							          *
* ! Description : This file has the implementation of Basic of H_BRIDGE_RELAY functions        							              *
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
#include"H_BRIDGE_RELAY_intrface.h"  
#include"H_BRIDGE_RELAY_private.h"
#include"H_BRIDGE_RELAY_config.h"


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: H_H_BRIDGE_RELAY_VoidInit																	                      *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to initialize the pin of the switch to output									                      *
**************************************************************************************************************************************/
void H_H_BRIDGE_RELAY_VoidInit()
{
	/*Setting the RELAY Switch Pin output*/
	MDIO_voidSetPinDirection(H_BRIDGE_RELAY_PIN1_PORT, H_BRIDGE_RELAY_PIN1,OUTPUT);
	MDIO_voidSetPinDirection(H_BRIDGE_RELAY_PIN2_PORT, H_BRIDGE_RELAY_PIN2,OUTPUT);
}

/**************************************************************************************************************************************
* Function Name		: H_H_BRIDGE_RELAY_VoidSetNC_ON															                          *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Switch ON									                        					      *
**************************************************************************************************************************************/
void H_H_BRIDGE_RELAY_VoidSetClockwise()
{

	/*Setting the RELAY Switch ON*/
	MDIO_voidSetPinValue(H_BRIDGE_RELAY_PIN1_PORT, H_BRIDGE_RELAY_PIN1,LOW);
	MDIO_voidSetPinValue(H_BRIDGE_RELAY_PIN2_PORT, H_BRIDGE_RELAY_PIN2,HIGH);

}

/**************************************************************************************************************************************
* Function Name		: H_H_BRIDGE_RELAY_VoidSetNO_OFF															                      *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Switch OFF									                        					  *
**************************************************************************************************************************************/
void H_H_BRIDGE_RELAY_VoidSetAntiClockwise()
{

	/*Setting the RELAY Switch OFF*/
	MDIO_voidSetPinValue(H_BRIDGE_RELAY_PIN2_PORT, H_BRIDGE_RELAY_PIN2,LOW);
	MDIO_voidSetPinValue(H_BRIDGE_RELAY_PIN1_PORT, H_BRIDGE_RELAY_PIN1,HIGH);
}

/**************************************************************************************************************************************
* Function Name		: H_H_BRIDGE_RELAY_VoidStopMotor															                      *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Stop Motor         									                        					  *
**************************************************************************************************************************************/
void H_H_BRIDGE_RELAY_VoidStopMotor()
{

	/*Setting the RELAY Switch OFF*/
	MDIO_voidSetPinValue(H_BRIDGE_RELAY_PIN2_PORT, H_BRIDGE_RELAY_PIN2,LOW);
	MDIO_voidSetPinValue(H_BRIDGE_RELAY_PIN1_PORT, H_BRIDGE_RELAY_PIN1,LOW);
}

