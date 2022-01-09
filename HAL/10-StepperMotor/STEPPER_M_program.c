/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						21 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Stepper Motor Driver                                                 							                      *
* ! File Name	: STEPPER_M_program.c                                                  							                      *
* ! Description : This file has the implementation of Basic of Stepper Mototr functions        					                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                   						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<util/delay.h>
/************************************************** Lower Layer Inclusions ***********************************************************/
#include"../../MCAL/01-DIO/DIO_intrface.h"
/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
/*Must be with that order maybe change Private with config only*/
#include"STEPPER_M_intrface.h"  
#include"STEPPER_M_private.h"
#include"STEPPER_M_config.h"


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: H_STEPPER_M_VoidInit																	                          *
* Parameters (in)	: None						                																      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialize teh four Pins of the Stepper Motor                 									  *
**************************************************************************************************************************************/
void H_STEPPER_M_VoidInit()
{
	/*Setting the four Pins of the Stepper Motor*/
	MDIO_voidSetPinDirection(STEPPER_M_PORT,STEPPER_M_PIN0,OUTPUT);
	MDIO_voidSetPinDirection(STEPPER_M_PORT,STEPPER_M_PIN1,OUTPUT);
	MDIO_voidSetPinDirection(STEPPER_M_PORT,STEPPER_M_PIN2,OUTPUT);
	MDIO_voidSetPinDirection(STEPPER_M_PORT,STEPPER_M_PIN3,OUTPUT);
	
}

/**************************************************************************************************************************************
* Function Name		: H_STEPPER_M_VoidRotateClockWise														                          *
* Parameters (in)	: uint16 Copy_uint16WantedAngle, float32 Copy_float32TickTime_InSec						       				      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Rotate the Stepper Motor Clockwise direction                   									  *
**************************************************************************************************************************************/
void H_STEPPER_M_VoidRotateClockWise(uint16 Copy_uint16WantedAngle, float32 Copy_float32TickTime_InSec)
{
	/*Loop itterator variable*/
	uint16 Local_uint16LoopCounter = 0;
	/*variable to store the steps needed for the wanted Angle*/
	uint16 Local_uint16StepsNum    = 0;
	
	/*Initially stop the motor*/
	H_STEPPER_M_VoidStopMotor();

	/*Calculate the steps Needed for the Wanted Angle*/
	Local_uint16StepsNum =( (STEPS_NUM_FOR_360Deg*Copy_uint16WantedAngle) /STEPPER_M_Single_ROTATION ) /4;
	
	for(Local_uint16LoopCounter = 0; Local_uint16LoopCounter < Local_uint16StepsNum; Local_uint16LoopCounter++)
	{
		/*Activate Coil 4 to take one step Clockwise*/
		MDIO_voidSetPinValue(PORTA, PIN0,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN1,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN2,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN3,LOW);
		_delay_ms(Copy_float32TickTime_InSec*STEPPER_M_1K);

		/*Activate Coil 3 to take one step Clockwise*/
		MDIO_voidSetPinValue(PORTA, PIN0,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN1,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN2,LOW);
		MDIO_voidSetPinValue(PORTA, PIN3,HIGH);
		_delay_ms(Copy_float32TickTime_InSec*STEPPER_M_1K);

		/*Activate Coil 2 to take one step Clockwise*/
		MDIO_voidSetPinValue(PORTA, PIN0,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN1,LOW);
		MDIO_voidSetPinValue(PORTA, PIN2,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN3,HIGH);
		_delay_ms(Copy_float32TickTime_InSec*STEPPER_M_1K);

		/*Activate Coil 1 to take one step Clockwise*/
		MDIO_voidSetPinValue(PORTA, PIN0,LOW);
		MDIO_voidSetPinValue(PORTA, PIN1,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN2,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN3,HIGH);
		_delay_ms(Copy_float32TickTime_InSec*STEPPER_M_1K);
	}
}

/**************************************************************************************************************************************
* Function Name		: H_STEPPER_M_VoidRotateAntiClockWise													                          *
* Parameters (in)	: None						                																      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Rotate the Stepper Motor Anti Clockwise direction                   								  *
**************************************************************************************************************************************/
void H_STEPPER_M_VoidRotateAntiClockWise(uint16 Copy_uint16WantedAngle, float32 Copy_float32TickTime_InSec)
{
	/*Loop itterator variable*/
	uint16 Local_uint16LoopCounter = 0;
	/*variable to store the steps needed for the wanted Angle*/
	uint16 Local_uint16StepsNum    = 0;
	
	/*Initially stop the motor*/
	H_STEPPER_M_VoidStopMotor();

	/*Calculate the steps Needed for the Wanted Angle*/
	Local_uint16StepsNum =( (STEPS_NUM_FOR_360Deg*Copy_uint16WantedAngle) /STEPPER_M_Single_ROTATION ) /4;
	
	for(Local_uint16LoopCounter = 0; Local_uint16LoopCounter < Local_uint16StepsNum; Local_uint16LoopCounter++)
	{
		/*Activate Coil 1 to take one step Anti Clockwise*/
		MDIO_voidSetPinValue(PORTA, PIN0,LOW);
		MDIO_voidSetPinValue(PORTA, PIN1,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN2,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN3,HIGH);
		_delay_ms(Copy_float32TickTime_InSec*STEPPER_M_1K);

		/*Activate Coil 2 to take one step Anti Clockwise*/
		MDIO_voidSetPinValue(PORTA, PIN0,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN1,LOW);
		MDIO_voidSetPinValue(PORTA, PIN2,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN3,HIGH);
		_delay_ms(Copy_float32TickTime_InSec*STEPPER_M_1K);

		/*Activate Coil 3 to take one step Anti Clockwise*/
		MDIO_voidSetPinValue(PORTA, PIN0,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN1,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN2,LOW);
		MDIO_voidSetPinValue(PORTA, PIN3,HIGH);
		_delay_ms(Copy_float32TickTime_InSec*STEPPER_M_1K);

		/*Activate Coil 4 to take one step Anti Clockwise*/
		MDIO_voidSetPinValue(PORTA, PIN0,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN1,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN2,HIGH);
		MDIO_voidSetPinValue(PORTA, PIN3,LOW);
		_delay_ms(Copy_float32TickTime_InSec*STEPPER_M_1K);
	}
}

/**************************************************************************************************************************************
* Function Name		: H_STEPPER_M_VoidStopMotor			             										                          *
* Parameters (in)	: None						                																      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Stop the Stepper Motor 						                   									  *
**************************************************************************************************************************************/
void H_STEPPER_M_VoidStopMotor()
{	
	/*Deactivate All coils to stop the motor*/
	MDIO_voidSetPinValue(PORTA, PIN0,HIGH);
	MDIO_voidSetPinValue(PORTA, PIN1,HIGH);
	MDIO_voidSetPinValue(PORTA, PIN2,HIGH);
	MDIO_voidSetPinValue(PORTA, PIN3,HIGH);
}




