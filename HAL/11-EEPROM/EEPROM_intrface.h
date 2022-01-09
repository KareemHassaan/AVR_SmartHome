/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						05 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: EEPROM Driver                                                        							                      *                     
* ! File Name	: EEPROM_intrface.h                                                    							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL	                  						                                         							  *
**************************************************************************************************************************************/
#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H
/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: HEEPROM_voidWriteData																		                      *
* Parameters (in)	: uint16 Copy_uint16Location, uint8  Copy_uint8Data											                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Write Data in Specific Location in The EEPROM									                      *
**************************************************************************************************************************************/
void HEEPROM_voidWriteData(uint16 Copy_uint16Location, uint8  Copy_uint8Data);
/**************************************************************************************************************************************
* Function Name		: HEEPROM_voidReadData																		                      *
* Parameters (in)	: uint16 Copy_uint16Location, uint8  * Copy_uint8ReceivedData								                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Read Data from Specific Location in The EEPROM		  						                      *
**************************************************************************************************************************************/
void HEEPROM_voidReadData(uint16 Copy_uint16Location, uint8  * Copy_uint8ReceivedData);

#endif /*EEPROM_INTERFACE_H*/