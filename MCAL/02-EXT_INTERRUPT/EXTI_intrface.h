/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						22 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: INTERRUPT Driver                                                     							                      *                     
* ! File Name	: EXTI_intrface.h                                                     							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: LAYERXXXVoidFunctionName																	                      *
* Parameters (in)	: xintx Copy_xintxParameterName, xintx * Copy_pxintxParameterName							                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialise the External interupt according to pre compile configration			                  *
**************************************************************************************************************************************/
void M_EXTI_VoidInit();
/**************************************************************************************************************************************
* Function Name		: M_EXTI_VoidInterruptEnable																	                  *
* Parameters (in)	: uint8 Copy_uint8InterruptControllerID, uint8 Copy_uint8InterruptControllerStatus							      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Interrupt Controller Enable or Disable									                  *
**************************************************************************************************************************************/
void M_EXTI_VoidInterruptEnable(uint8 Copy_uint8InterruptControllerID, uint8 Copy_uint8InterruptControllerStatus);
/**************************************************************************************************************************************
* Function Name		: M_EXTI_VoidInterruptSenseControl																	              *
* Parameters (in)	: uint8 Copy_uint8InterruptControllerID, uint8 Copy_uint8InterruptControllerSenseSignal						      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Interrupt Controller Sense Signal											                  *
**************************************************************************************************************************************/
void M_EXTI_VoidInterruptSenseControl(uint8 Copy_uint8InterruptControllerID, uint8 Copy_uint8InterruptControllerSenseSignal);

/*********************************************** Interrupt Controllers Macros ********************************************************/

#define INT0			0
#define INT1			1
#define INT2			2

/********************************************************* E/D Macros ****************************************************************/

#define ENABLE  		0 
#define DISABLE 		1 

/*********************************************** Interrupt Sense Control Macros ******************************************************/

#define FALLING_EDGE  	0 
#define RISING_EDGE 	1 
#define ON_CHANGE  		2 
#define LOW_LEVEL 		3 






#endif /*EXTI_INTERFACE_H*/