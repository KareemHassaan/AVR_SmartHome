/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						21 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Stepper Motor Driver                                                        							              *                     
* ! File Name	: STEPPER_M_intrface.h                                                     							                  *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                   						                                         							  *
**************************************************************************************************************************************/
#ifndef STEPPER_M_INTERFACE_H
#define STEPPER_M_INTERFACE_H
/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: H_STEPPER_M_VoidInit																	                          *
* Parameters (in)	: None						                																      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialize teh four Pins of the Stepper Motor                 									  *
**************************************************************************************************************************************/
void H_STEPPER_M_VoidInit();
/**************************************************************************************************************************************
* Function Name		: H_STEPPER_M_VoidRotateClockWise														                          *
* Parameters (in)	: None						                																      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Rotate the Stepper Motor Clockwise direction                   									  *
**************************************************************************************************************************************/
void H_STEPPER_M_VoidRotateClockWise(uint16 Copy_uint16WantedAngle, float32 Copy_float32TickTime_InSec);
/**************************************************************************************************************************************
* Function Name		: H_STEPPER_M_VoidRotateAntiClockWise													                          *
* Parameters (in)	: None						                																      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Rotate the Stepper Motor Anti Clockwise direction                   								  *
**************************************************************************************************************************************/
void H_STEPPER_M_VoidRotateAntiClockWise(uint16 Copy_uint16WantedAngle, float32 Copy_float32TickTime_InSec);
/**************************************************************************************************************************************
* Function Name		: H_STEPPER_M_VoidStopMotor			             										                          *
* Parameters (in)	: None						                																      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Stop the Stepper Motor 						                   									  *
**************************************************************************************************************************************/
void H_STEPPER_M_VoidStopMotor();

#endif /*STEPPER_M_INTERFACE_H*/