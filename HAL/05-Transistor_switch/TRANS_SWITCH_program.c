/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						20 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Transistor Switch Driver                                                        							          *
* ! File Name	: TRANS_SWITCH_program.c                                                       							              *
* ! Description : This file has the implementation of Basic of Transistor Switch functions        							          *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                  						                                         							      *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
/************************************************** Lower Layer Inclusions ***********************************************************/
#include"../../MCAL/01-DIO/DIO_intrface.h"

/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
/*Must be with that order maybe change Private with config only*/
#include"TRANS_SWITCH_intrface.h"  
#include"TRANS_SWITCH_private.h"
#include"TRANS_SWITCH_config.h"


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: H_TRANS_SWITCH_VoidInit																	                      *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to initialize the pin of the switch to output									                      *
**************************************************************************************************************************************/
void H_TRANS_SWITCH_VoidInit()
{
	/*Setting the Transistor Switch Pin output*/
	MDIO_voidSetPinDirection(TRANS_SWITCH_PORT, TRANS_SWITCH_PIN,OUTPUT);
}

/**************************************************************************************************************************************
* Function Name		: H_TRANS_SWITCH_VoidSetSwitch_ON															                      *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Switch ON									                        					      *
**************************************************************************************************************************************/
void H_TRANS_SWITCH_VoidSetSwitch_ON()
{
	
#if(TRANSISTOR_TYPE == TRANS_SWITCH_NPN)
	
	/*Setting the Transistor Switch NPN ON*/
	MDIO_voidSetPinValue(TRANS_SWITCH_PORT, TRANS_SWITCH_PIN,HIGH);
	
#elif(TRANSISTOR_TYPE == TRANS_SWITCH_PNP)
	
/*Setting the Transistor Switch PNP ON*/
	MDIO_voidSetPinValue(TRANS_SWITCH_PORT, TRANS_SWITCH_PIN,LOW);

#endif
}

/**************************************************************************************************************************************
* Function Name		: H_TRANS_SWITCH_VoidSetSwitch_OFF															                      *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Switch OFF									                        					  *
**************************************************************************************************************************************/
void H_TRANS_SWITCH_VoidSetSwitch_OFF()
{
	
#if(TRANSISTOR_TYPE == TRANS_SWITCH_NPN)
	
	/*Setting the Transistor Switch NPN OFF*/
	MDIO_voidSetPinValue(TRANS_SWITCH_PORT, TRANS_SWITCH_PIN,LOW);
	
#elif(TRANSISTOR_TYPE == TRANS_SWITCH_PNP)
	
	/*Setting the Transistor Switch PNP OFF*/
	MDIO_voidSetPinValue(TRANS_SWITCH_PORT, TRANS_SWITCH_PIN,HIGH);

#endif
}








