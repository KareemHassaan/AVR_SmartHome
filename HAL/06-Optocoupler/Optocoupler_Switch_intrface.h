/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						20 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Optocoupler Switch Driver                                                        		                              *                     
* ! File Name	: Optocoupler_Switch_intrface.h                                        							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                  						                                         				    			  *
**************************************************************************************************************************************/
#ifndef OPTOCOUPLER_SWITCH_INTERFACE_H
#define OPTOCOUPLER_SWITCH_INTERFACE_H
/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: Optocoupler_Switch_VoidInit																	                  *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to initialize the pin of the switch to output									                      *
**************************************************************************************************************************************/
void Optocoupler_Switch_VoidInit();
/**************************************************************************************************************************************
* Function Name		: Optocoupler_Switch_VoidSetSwitch_ON															                  *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Switch ON									                        					      *
**************************************************************************************************************************************/
void Optocoupler_Switch_VoidSetSwitch_ON();
/**************************************************************************************************************************************
* Function Name		: Optocoupler_Switch_VoidSetSwitch_OFF															                  *
* Parameters (in)	: None							                      															  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Switch OFF									                        					  *
**************************************************************************************************************************************/
void Optocoupler_Switch_VoidSetSwitch_OFF();

#endif /*OPTOCOUPLER_SWITCH_INTERFACE_H*/