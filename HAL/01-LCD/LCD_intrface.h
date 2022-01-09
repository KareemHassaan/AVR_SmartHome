/**************************************************************************************************************************************
* LOG:                                               														     					  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION        				  		  *
* 1.0.0 					Kareem Hassaan						12 DEC,2021					- Initial Creation				  		  *
* 1.0.1 					Kareem Hassaan						15 DEC,2021					- Fix some bugs in 4bit mode			  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: LCD Driver                                                                            							  *
* ! File Name	: LCD_intrface.h                                                                         							  *
* ! Description : This file has the Definitions needed		         		        					                    		  *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *                    
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL						                                         							                      *
**************************************************************************************************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/*************************************************************************************************************************************/
/********************************************************* Goto Macros ***************************************************************/
/*************************************************************************************************************************************/
#define ROW0 0
#define ROW1 1

#define COL0  0
#define COL1  1
#define COL2  2
#define COL3  3
#define COL4  4
#define COL5  5
#define COL6  6
#define COL7  7
#define COL8  8
#define COL9  9 
#define COL10 10
#define COL11 11
#define COL12 12
#define COL13 13
#define COL14 14
#define COL15 15

/*************************************************************************************************************************************/
/************************************************* CGRAM Positions Macros Macros *****************************************************/
/*************************************************************************************************************************************/
#define PATTERN_POSITION_0 0
#define PATTERN_POSITION_1 1
#define PATTERN_POSITION_2 2
#define PATTERN_POSITION_3 3
#define PATTERN_POSITION_4 4
#define PATTERN_POSITION_5 5
#define PATTERN_POSITION_6 6
#define PATTERN_POSITION_7 7

/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HLCD_VoidInit				                    																  *
* Parameters (in)	: None											                    											  *
* Parameters (out)	: None																                    						  *
* Return value		: None																					                    	  *
* Description		: Function to initialize the Lcd and send commands	                            								  *
**************************************************************************************************************************************/
void HLCD_VoidInit();
/**************************************************************************************************************************************
* Function Name		: HLCD_VoidSendData																		                    	  *
* Parameters (in)	: uint8 Copy_uint8Data																	                    	  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Send Data to the LCD																				  *
**************************************************************************************************************************************/
void HLCD_VoidSendData(uint8 Copy_uint8Data);
/**************************************************************************************************************************************
* Function Name		: HLCD_VoidSendString																		                      *
* Parameters (in)	: uint8 * Copy_uint8Data																	                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Send a string of Character to the LCD											                      *
**************************************************************************************************************************************/
void HLCD_VoidSendString(uint8 * Copy_uint8Data);
/**************************************************************************************************************************************
* Function Name		: HLCD_VoidSendNumber																		                      *
* Parameters (in)	: uint32 Copy_uint32Data																	  	                  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Send a string of Numbers to the LCD											                      *
**************************************************************************************************************************************/
void HLCD_VoidSendNumber(uint32 Copy_uint32Data);
/**************************************************************************************************************************************
* Function Name		: HLCD_VoidGoTo	                    																			  *
* Parameters (in)	: uint8 Copy_uint8_XPosition, uint8 Copy_uint8_YPosition					                    				  *
* Parameters (out)	: None															                    							  *
* Return value		: None																				                    		  *
* Description		: Function to go to specific coordinate in the LCD											                      *
**************************************************************************************************************************************/
void HLCD_VoidGoTo(uint8 Copy_uint8_XPosition, uint8 Copy_uint8_YPosition);

/**************************************************************************************************************************************
* Function Name		: HLCD_VoidClearLcd	                    																		  *
* Parameters (in)	: None					                    								  									  *
* Parameters (out)	: None															                    							  *
* Return value		: None																				                    		  *
* Description		: Function to Clear the LCD											                   							  *
**************************************************************************************************************************************/
void HLCD_VoidClearLcd();
/**************************************************************************************************************************************
* Function Name		: HLCD_VoidSendCustomPattern	                    															  *
* Parameters (in)	: uint8 * Copy_uint8Data,uint8 Copy_uint8_PatternPosition,uint8 Copy_uint8_XPosition,uint8 Copy_uint8_YPosition   * 
*Parameters (out)	: None															                    							  *
* Return value		: None																				                    		  *
* Description		: Function to Clear the LCD											                   							  *
**************************************************************************************************************************************/
void HLCD_VoidSendCustomPattern(uint8 * Copy_uint8Data,  uint8 Copy_uint8_PatternPosition, uint8 Copy_uint8_XPosition, uint8 Copy_uint8_YPosition);


#endif /*LCD_INTERFACE_H*/