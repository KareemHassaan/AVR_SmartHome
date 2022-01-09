/**************************************************************************************************************************************
* LOG:                                               														     					  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION        				  		  *
* 1.0.0 					Kareem Hassaan						12 DEC,2021					- Initial Creation				  		  *
* 1.0.1 					Kareem Hassaan						15 DEC,2021					- Fix some bugs in 4bit mode			  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: LCD Driver                                                                            							  *
* ! File Name	: LCD_private.h                                                                         							  *
* ! Description : This file has the Private definitions needed				       		                    					      *
* ! Compiler  	: GNU AVR cross Compiler                                            						                    	  *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL						                                         							                      *
**************************************************************************************************************************************/
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define POSITION_FIXED_ADRESS 0x40
#define ZERO_ASCII_CODE       0x30


/**************************************************************************************************************************************
* Function Name		: static HLCD_VoidSendCommand											                    					  *
* Parameters (in)	: uint8 Copy_uint8Command															                    		  *
* Parameters (out)	: None																						                      *                    
* Return value		: None																						                      *
* Description		: Function to Send commands to the LCD														       				  *
**************************************************************************************************************************************/
static void HLCD_VoidSendCommand(uint8 Copy_uint8Command);

#endif /*LCD_PRIVATE_H*/