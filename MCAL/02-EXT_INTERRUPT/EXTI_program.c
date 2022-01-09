/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						22 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: TNTERRUPT Driver                                                   							                      *
* ! File Name	: EXTI_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of EXTI functions        							                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include<util/delay.h>
/************************************************** Lower Layer Inclusions ***********************************************************/
#include"../01-DIO/DIO_intrface.h"
/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
/*Must be with that order maybe change Private with config only*/
#include"EXTI_intrface.h"  
#include"EXTI_private.h"
#include"EXTI_config.h"

/***************************************************** Global Variables **************************************************************/
/*Global Array of Pointers To Function*/
static void (*Global_pvCallbackFunction[ISR_NUM])(void);

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: LAYERXXXVoidFunctionName																	                      *
* Parameters (in)	: xintx Copy_xintxParameterName, xintx * Copy_pxintxParameterName							                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialise the External interupt according to pre compile configration			                  *
**************************************************************************************************************************************/
void M_EXTI_VoidInit()
{
	/************************************ PreCompile Check that INT0 Enabled or Disabled *********************************************/
	
	#if EXTI_INT0_ENABLE == ENABLE
		
			/*PreCompile Check the interrupt sense control */
			#if  EXTI_INT0_SENSE_SIGNAL  == FALLING_EDGE

					/*Setting the Sense Signal to Falling Edge*/
					CLR_BIT(MCUCR,MCUCR_ISC00);
					SET_BIT(MCUCR,MCUCR_ISC01);

			#elif EXTI_INT0_SENSE_SIGNAL == RISING_EDGE

					/*Setting the Sense Signal to Rising Edge*/
					SET_BIT(MCUCR,MCUCR_ISC00);
					SET_BIT(MCUCR,MCUCR_ISC01);

			#elif EXTI_INT0_SENSE_SIGNAL == ON_CHANGE

					/*Setting the Sense Signal to Any Cahnge*/
					SET_BIT(MCUCR,MCUCR_ISC00);
					CLR_BIT(MCUCR,MCUCR_ISC01);

			#elif EXTI_INT0_SENSE_SIGNAL == LOW_LEVEL

					/*Setting the Sense Signal to the low level*/
					CLR_BIT(MCUCR,MCUCR_ISC00);
					CLR_BIT(MCUCR,MCUCR_ISC01);

			#else

					/*Generate Error that EXTI_INT0_SENSE_SIGNAL Configration not sutiable*/
					#error"EXTI_INT0_SENSE_SIGNAL Configration Error"

			#endif
			
			/*Enable the INT0*/
			SET_BIT(GICR,GICR_INT0);
			
	#elif EXTI_INT0_ENABLE == DISABLE
		
			/*Disable the INT0*/
			CLR_BIT(GICR,GICR_INT0);
		
	#else
		
			/*Generate Error that EXTI_INT0_ENABLE Configration not sutiable*/
			#error"EXTI_INT0_ENABLE Configration Error"
		
	#endif
	
	/************************************ PreCompile Check that INT1 Enabled or Disabled *********************************************/
	
	#if EXTI_INT1_ENABLE == ENABLE
		
			/*PreCompile Check the interrupt sense control */
			#if  EXTI_INT1_SENSE_SIGNAL  == FALLING_EDGE
			
					/*Setting the Sense Signal to Falling Edge*/
					CLR_BIT(MCUCR,MCUCR_ISC10);
					SET_BIT(MCUCR,MCUCR_ISC11);
			
			#elif EXTI_INT1_SENSE_SIGNAL == RISING_EDGE
			
					/*Setting the Sense Signal to Rising Edge*/
					SET_BIT(MCUCR,MCUCR_ISC10);
					SET_BIT(MCUCR,MCUCR_ISC11);
			
			#elif EXTI_INT1_SENSE_SIGNAL == ON_CHANGE
			
					/*Setting the Sense Signal to Any Cahnge*/
					SET_BIT(MCUCR,MCUCR_ISC10);
					CLR_BIT(MCUCR,MCUCR_ISC11);
			
			#elif EXTI_INT1_SENSE_SIGNAL == LOW_LEVEL
			
					/*Setting the Sense Signal to the low level*/
					CLR_BIT(MCUCR,MCUCR_ISC10);
					CLR_BIT(MCUCR,MCUCR_ISC11);
					
			#else
				
					/*Generate Error that EXTI_INT1_SENSE_SIGNAL Configration not sutiable*/
					#error"EXTI_INT1_SENSE_SIGNAL Configration Error"
			
			#endif
			
			/*Enable the INT1*/
			SET_BIT(GICR,GICR_INT1);
		
	#elif EXTI_INT1_ENABLE == DISABLE
		
			/*Disable the INT1*/
			CLR_BIT(GICR,GICR_INT1);
		
	#else
		
			/*Generate Error that EXTI_INT1_ENABLE Configration not sutiable*/
			#error"EXTI_INT1_ENABLE Configration Error"
		
	#endif
	
	/************************************ PreCompile Check that INT2 Enabled or Disabled *********************************************/
	
	#if EXTI_INT2_ENABLE == ENABLE
		
			/*PreCompile Check the interrupt sense control */
			#if  EXTI_INT2_SENSE_SIGNAL  == FALLING_EDGE
			
					/*Setting the Sense Signal to Falling Edge*/
					CLR_BIT(MCUCSR,MCUCR_ISC2);
			
			#elif EXTI_INT2_SENSE_SIGNAL == RISING_EDGE
			
					/*Setting the Sense Signal to Rising Edge*/
					SET_BIT(MCUCSR,MCUCR_ISC2);

			#else
				
					/*Generate Error that EXTI_INT2_SENSE_SIGNAL Configration not sutiable*/
					#error"EXTI_INT2_SENSE_SIGNAL Configration Error"
			
			#endif
			
			/*Enable the INT2*/
			SET_BIT(GICR,GICR_INT2);
		
	#elif EXTI_INT2_ENABLE == DISABLE
		
			/*Disable the INT2*/
			CLR_BIT(GICR,GICR_INT2);
		
	#else
		
			/*Generate Error that EXTI_INT2_ENABLE Configration not sutiable*/
			#error"EXTI_INT2_ENABLE Configration Error"
		
	#endif
}

/**************************************************************************************************************************************
* Function Name		: M_EXTI_VoidInterruptEnable																	                  *
* Parameters (in)	: uint8 Copy_uint8InterruptControllerID, uint8 Copy_uint8InterruptControllerStatus							      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Interrupt Controller Enable or Disable									                  *
**************************************************************************************************************************************/
void M_EXTI_VoidInterruptEnable(uint8 Copy_uint8InterruptControllerID, uint8 Copy_uint8InterruptControllerStatus)
{
	/*Searching which Interrupt Controller*/
	switch(Copy_uint8InterruptControllerID)
	{
			case INT0:
					/*Searching which Status*/
					switch(Copy_uint8InterruptControllerStatus)
					{
							case ENABLE:
									/*Enable the INT0*/
									SET_BIT(GICR,GICR_INT0);
							break;
								
							case DISABLE:
									/*Disable the INT0*/
									CLR_BIT(GICR,GICR_INT0);
							break;
								
							default:
									/*Return Error*/
							break;
					}
			break;
				
			case INT1:
					/*Searching which Status*/
					switch(Copy_uint8InterruptControllerStatus)
					{
							case ENABLE:
									/*Enable the INT1*/
									SET_BIT(GICR,GICR_INT1);
							break;
								
							case DISABLE:
									/*Disable the INT1*/
									CLR_BIT(GICR,GICR_INT1);
							break;
								
							default:
									/*Return Error*/
							break;
					}
			break;
				
			case INT2:
			
					/*Searching which Status*/
					switch(Copy_uint8InterruptControllerStatus)
					{
							case ENABLE:
									/*Enable the INT2*/
									SET_BIT(GICR,GICR_INT2);
							break;
								
							case DISABLE:
									/*Disable the INT2*/
									CLR_BIT(GICR,GICR_INT2);
							break;
								
							default:
									/*Return Error*/
							break;
					}
			break;
				
			default:
						/*Return Error*/
			break;
	}
}

/**************************************************************************************************************************************
* Function Name		: M_EXTI_VoidInterruptSenseControl																	              *
* Parameters (in)	: uint8 Copy_uint8InterruptControllerID, uint8 Copy_uint8InterruptControllerSenseSignal						      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Interrupt Controller Sense Signal											                  *
**************************************************************************************************************************************/
void M_EXTI_VoidInterruptSenseControl(uint8 Copy_uint8InterruptControllerID, uint8 Copy_uint8InterruptControllerSenseSignal)
{
	/*Searching which Interrupt Controller*/
	switch(Copy_uint8InterruptControllerID)
	{
			case INT0:
					/*Searching which Sense Signal*/
					switch(Copy_uint8InterruptControllerSenseSignal)
					{
							case FALLING_EDGE:
									/*Setting the Sense Signal to Falling Edge*/
									CLR_BIT(MCUCR,MCUCR_ISC00);
									SET_BIT(MCUCR,MCUCR_ISC01);
							break;
								
							case RISING_EDGE:
									/*Setting the Sense Signal to Rising Edge*/
									SET_BIT(MCUCR,MCUCR_ISC00);
									SET_BIT(MCUCR,MCUCR_ISC01);
							break;
							
							case ON_CHANGE:
									/*Setting the Sense Signal to Any Cahnge*/
									SET_BIT(MCUCR,MCUCR_ISC00);
									CLR_BIT(MCUCR,MCUCR_ISC01);
							break;
								
							case LOW_LEVEL:
									/*Setting the Sense Signal to the low level*/
									CLR_BIT(MCUCR,MCUCR_ISC00);
									CLR_BIT(MCUCR,MCUCR_ISC01);
							break;
								
							default:
									/*Return Error*/
							break;
					}
			break;
				
			case INT1:
					/*Searching which Sense Signal*/
					switch(Copy_uint8InterruptControllerSenseSignal)
					{
							case FALLING_EDGE:
									/*Setting the Sense Signal to Falling Edge*/
									CLR_BIT(MCUCR,MCUCR_ISC10);
									SET_BIT(MCUCR,MCUCR_ISC11);
							break;
								
							case RISING_EDGE:
									/*Setting the Sense Signal to Rising Edge*/
									SET_BIT(MCUCR,MCUCR_ISC10);
									SET_BIT(MCUCR,MCUCR_ISC11);
							break;
							
							case ON_CHANGE:
									/*Setting the Sense Signal to Any Cahnge*/
									SET_BIT(MCUCR,MCUCR_ISC10);
									CLR_BIT(MCUCR,MCUCR_ISC11);
							break;
								
							case LOW_LEVEL:
									/*Setting the Sense Signal to the low level*/
									CLR_BIT(MCUCR,MCUCR_ISC10);
									CLR_BIT(MCUCR,MCUCR_ISC11);
							break;
								
							default:
									/*Return Error*/
							break;
					}
			break;
				
			case INT2:
			
					/*Searching which Sense Signal*/
					switch(Copy_uint8InterruptControllerSenseSignal)
					{
							case FALLING_EDGE:
									/*Setting the Sense Signal to Falling Edge*/
									CLR_BIT(MCUCSR,MCUCR_ISC2);
							break;
								
							case RISING_EDGE:
									/*Setting the Sense Signal to Rising Edge*/
									SET_BIT(MCUCSR,MCUCR_ISC2);
							break;
								
							default:
									/*Return Error*/
							break;
					}
			break;
				
			default:
						/*Return Error*/
			break;
	}
}

/**************************************************************************************************************************************
* Function Name		: M_EXTI_voidSetCallback         														                          *
* Parameters (in)	: void (*Copy_pvNotificationFunction)(void)																          *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set an address to a function to each INT.      		     					                      *
**************************************************************************************************************************************/
void M_EXTI_voidSetCallback(uint8 Copy_uint8IntNum, void (*Copy_pvNotificationFunction)(void))
{
	switch(Copy_uint8IntNum)
	{
		case INT0:
		
				/*Set the ISR Function to Int 0*/
				Global_pvCallbackFunction[INT0] = Copy_pvNotificationFunction;
		break;
		case INT1:
		
				/*Set the ISR Function to Int 1*/
				Global_pvCallbackFunction[INT1] = Copy_pvNotificationFunction;
		break;
		case INT2:
				
				/*Set the ISR Function to Int 2*/
				Global_pvCallbackFunction[INT2] = Copy_pvNotificationFunction;
		break;
	}
    
}

/*************************************************************************************************************************************/
/********************************************************** ISR INT0 *****************************************************************/
/*************************************************************************************************************************************/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(Global_pvCallbackFunction[INT0] != NULL)
    {   
       (Global_pvCallbackFunction[INT0])();
    }
    else
    {
        /*Do Nothing*/
    }
}

/*************************************************************************************************************************************/
/********************************************************** ISR INT1 *****************************************************************/
/*************************************************************************************************************************************/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(Global_pvCallbackFunction[INT1] != NULL)
    {   
       (Global_pvCallbackFunction[INT1])();
    }
    else
    {
        /*Do Nothing*/
    }
	
}

/*************************************************************************************************************************************/
/********************************************************** ISR INT2 *****************************************************************/
/*************************************************************************************************************************************/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(Global_pvCallbackFunction[INT2] != NULL)
    {   
       (Global_pvCallbackFunction[INT2])();
    }
    else
    {
        /*Do Nothing*/
    }
	
}




