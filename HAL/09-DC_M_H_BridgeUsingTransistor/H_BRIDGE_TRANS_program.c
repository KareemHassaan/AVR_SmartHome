/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						20 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: H-Bridge By Transistor Driver                                                        					              *
* ! File Name	: H_BRIDGE_TRANS_program.c                                                       							          *
* ! Description : This file has the implementation of Basic of H-Bridge By Transistor functions        							      *
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
#include"H_BRIDGE_TRANS_intrface.h"  
#include"H_BRIDGE_TRANS_private.h"
#include"H_BRIDGE_TRANS_config.h"


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: H_TRANS_H_BRIDGE_VoidInit																	                      *
* Parameters (in)	: None                                                           							                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to initialize the pins of the H-Bridge to output									                      *
**************************************************************************************************************************************/
void H_TRANS_H_BRIDGE_VoidInit()
{
	/*Setting the Transistor H_BRIDGE Pins output*/
	MDIO_voidSetPinDirection(TRANS_H_BRIDGE_PIN1_PORT, TRANS_H_BRIDGE_PIN1,OUTPUT);
	MDIO_voidSetPinDirection(TRANS_H_BRIDGE_PIN2_PORT, TRANS_H_BRIDGE_PIN2,OUTPUT);
}

/**************************************************************************************************************************************
* Function Name		: H_TRANS_H_BRIDGE_VoidPIN1_ON																                      *
* Parameters (in)	: None                                                           							                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Make the Pin1 ON (Postive Terminal)									                              *
**************************************************************************************************************************************/
void H_TRANS_H_BRIDGE_VoidPIN1_ON()
{
#if((TRANSISTOR_PIN1_TYPE == TRANS_SWITCH_NPN)&&(TRANSISTOR_PIN2_TYPE == TRANS_SWITCH_NPN))
	
	/*Setting the Half of H_BRIDGE Switch NPN OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN2_PORT, TRANS_H_BRIDGE_PIN2,LOW);
	/*Setting the Other Half of H_BRIDGE Switch NPN ON*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN1_PORT, TRANS_H_BRIDGE_PIN1,HIGH);

#elif((TRANSISTOR_PIN1_TYPE == TRANS_SWITCH_NPN)&&(TRANSISTOR_PIN2_TYPE == TRANS_SWITCH_PNP))
	
	/*Setting the Half of H_BRIDGE Switch PNP OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN2_PORT, TRANS_H_BRIDGE_PIN2,HIGH);
	/*Setting the Other Half of H_BRIDGE Switch NPN ON*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN1_PORT, TRANS_H_BRIDGE_PIN1,HIGH);

#elif((TRANSISTOR_PIN1_TYPE == TRANS_SWITCH_PNP)&&(TRANSISTOR_PIN2_TYPE == TRANS_SWITCH_NPN))
	
	/*Setting the Half of H_BRIDGE Switch NPN OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN2_PORT, TRANS_H_BRIDGE_PIN2,LOW);
	/*Setting the Other Half of H_BRIDGE Switch PNP ON*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN1_PORT, TRANS_H_BRIDGE_PIN1,LOW);
	
#elif((TRANSISTOR_PIN1_TYPE == TRANS_SWITCH_PNP)&&(TRANSISTOR_PIN2_TYPE == TRANS_SWITCH_PNP))
	
	/*Setting the Half of H_BRIDGE Switch PNP OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN2_PORT, TRANS_H_BRIDGE_PIN2,HIGH);
	/*Setting the Other Half of H_BRIDGE Switch PNP ON*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN1_PORT, TRANS_H_BRIDGE_PIN1,LOW);

#endif
}

/**************************************************************************************************************************************
* Function Name		: H_TRANS_H_BRIDGE_VoidPIN2_ON																                      *
* Parameters (in)	: None                                                           							                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Make the Pin2 ON (Postive Terminal)									                              *
**************************************************************************************************************************************/
void H_TRANS_H_BRIDGE_VoidPIN2_ON()
{
#if((TRANSISTOR_PIN1_TYPE == TRANS_SWITCH_NPN)&&(TRANSISTOR_PIN2_TYPE == TRANS_SWITCH_NPN))
	
	/*Setting the Half of H_BRIDGE Switch NPN OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN1_PORT, TRANS_H_BRIDGE_PIN1,LOW);
	/*Setting the Other Half of H_BRIDGE Switch NPN ON*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN2_PORT, TRANS_H_BRIDGE_PIN2,HIGH);

#elif((TRANSISTOR_PIN1_TYPE == TRANS_SWITCH_PNP)&&(TRANSISTOR_PIN2_TYPE == TRANS_SWITCH_NPN))
	
	/*Setting the Half of H_BRIDGE Switch PNP OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN1_PORT, TRANS_H_BRIDGE_PIN1,HIGH);
	/*Setting the Other Half of H_BRIDGE Switch NPN ON*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN2_PORT, TRANS_H_BRIDGE_PIN2,HIGH);

#elif((TRANSISTOR_PIN1_TYPE == TRANS_SWITCH_NPN)&&(TRANSISTOR_PIN2_TYPE == TRANS_SWITCH_PNP))
	
	/*Setting the Half of H_BRIDGE Switch NPN OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN1_PORT, TRANS_H_BRIDGE_PIN1,LOW);
	/*Setting the Other Half of H_BRIDGE Switch PNP ON*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN2_PORT, TRANS_H_BRIDGE_PIN2,LOW);
	
#elif((TRANSISTOR_PIN1_TYPE == TRANS_SWITCH_PNP)&&(TRANSISTOR_PIN2_TYPE == TRANS_SWITCH_PNP))
	
	/*Setting the Half of H_BRIDGE Switch PNP OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN1_PORT, TRANS_H_BRIDGE_PIN1,HIGH);
	/*Setting the Other Half of H_BRIDGE Switch PNP ON*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN2_PORT, TRANS_H_BRIDGE_PIN2,LOW);

#endif
}

/**************************************************************************************************************************************
* Function Name		: H_TRANS_H_BRIDGE_VoidStopMotor															                      *
* Parameters (in)	: None                                                           							                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Stop Motor                        									                              *
**************************************************************************************************************************************/
void H_TRANS_H_BRIDGE_VoidStopMotor()
{
#if((TRANSISTOR_PIN1_TYPE == TRANS_SWITCH_NPN)&&(TRANSISTOR_PIN2_TYPE == TRANS_SWITCH_NPN))
	
	/*Setting the Half of H_BRIDGE Switch NPN OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN1_PORT, TRANS_H_BRIDGE_PIN1,LOW);
	/*Setting the Other Half of H_BRIDGE Switch NPN OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN2_PORT, TRANS_H_BRIDGE_PIN2,LOW);

#elif((TRANSISTOR_PIN1_TYPE == TRANS_SWITCH_PNP)&&(TRANSISTOR_PIN2_TYPE == TRANS_SWITCH_NPN))
	
	/*Setting the Half of H_BRIDGE Switch PNP OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN1_PORT, TRANS_H_BRIDGE_PIN1,HIGH);
	/*Setting the Other Half of H_BRIDGE Switch NPN OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN2_PORT, TRANS_H_BRIDGE_PIN2,LOW);

#elif((TRANSISTOR_PIN1_TYPE == TRANS_SWITCH_NPN)&&(TRANSISTOR_PIN2_TYPE == TRANS_SWITCH_PNP))
	
	/*Setting the Half of H_BRIDGE Switch NPN OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN1_PORT, TRANS_H_BRIDGE_PIN1,LOW);
	/*Setting the Other Half of H_BRIDGE Switch PNP OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN2_PORT, TRANS_H_BRIDGE_PIN2,HIGH);
	
#elif((TRANSISTOR_PIN1_TYPE == TRANS_SWITCH_PNP)&&(TRANSISTOR_PIN2_TYPE == TRANS_SWITCH_PNP))
	
	/*Setting the Half of H_BRIDGE Switch PNP OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN1_PORT, TRANS_H_BRIDGE_PIN1,HIGH);
	/*Setting the Other Half of H_BRIDGE Switch PNP OFF*/
	MDIO_voidSetPinValue(TRANS_H_BRIDGE_PIN2_PORT, TRANS_H_BRIDGE_PIN2,HIGH);

#endif
}
