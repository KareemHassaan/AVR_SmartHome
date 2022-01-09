/**************************************************************************************************************************************
* LOG:                                               														     					  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION        				  		  *
* 1.0.0 					Kareem Hassaan						12 DEC,2021					- Initial Creation				  		  *
* 1.0.1 					Kareem Hassaan						15 DEC,2021					- Fix some bugs in 4bit mode			  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: LCD Driver                                                        							                      *                   
* ! File Name	: LCD_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of LCD functions (16x2 Character LCD for chip LMB161A)                    *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL						                                         							                      *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#define F_CPU 8000000UL
#include<util/delay.h>
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
/************************************************** Lower Layer Inclusions ***********************************************************/
#include"../../MCAL/01-DIO/DIO_intrface.h"

/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
/*Must be with that order maybe change Private with config only*/
#include"LCD_intrface.h"  
#include"LCD_private.h"
#include"LCD_config.h"


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HLCD_VoidInit																				                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to initialize the Lcd and send commands		 									                      *
**************************************************************************************************************************************/
void HLCD_VoidInit()
{
#if(HALF_LOAD_4BITS == 0)
	
	/*Set Data Port of LCD Output*/
	MDIO_voidSetPortDirection(LCD_DATA_PORT, ALL_OUTPUT);
	/*Set Control Pins of LCD to Output*/
	MDIO_voidSetPortSpecificDirection(LCD_CONTROL_PORT, 0xFF, ALL_INPUT|(OUTPUT << LCD_EN_PIN)|(OUTPUT << LCD_RW_PIN)|(OUTPUT << LCD_RS_PIN) );
	/*Wait for 40 msec*/
	_delay_ms(40);
	
	/*Send Function Set Command*/
	HLCD_VoidSendCommand((LCD_FunctionSetFixed)|(LCD_LineNumbers << PIN3)|(LCD_FontSize << PIN2));
	
	/*Send Display ON/OFF Command*/
	HLCD_VoidSendCommand((LCD_DisplayFixed)|(LCD_EntireDisplay << PIN2)|(LCD_CursorDisplay << PIN1)|(LCD_CursorBlinking << PIN0));
	
	/*Send Clear Command*/
	HLCD_VoidSendCommand(LCD_ClearValue);
	
#elif(HALF_LOAD_4BITS == 1)

	/*Set Data Pins of LCD to Output*/
	MDIO_voidSetPortSpecificDirection(LCD_DATA_PORT_4BIT, ALL_LOW|(HIGH << LCD_D0)|(HIGH << LCD_D1)|(HIGH << LCD_D2)|(HIGH << LCD_D3),\
														ALL_INPUT|(OUTPUT << LCD_D0)|(OUTPUT << LCD_D1)|(OUTPUT << LCD_D2)|(OUTPUT << LCD_D3));
	/*Set Control Pins of LCD to Output*/
	MDIO_voidSetPortSpecificDirection(LCD_CONTROL_PORT_4BIT, ALL_LOW|(HIGH << LCD_EN_PIN_4BIT)|(HIGH << LCD_RW_PIN_4BIT)|(HIGH << LCD_RS_PIN_4BIT),\
														ALL_INPUT|(OUTPUT << LCD_EN_PIN_4BIT)|(OUTPUT << LCD_RW_PIN_4BIT)|(OUTPUT << LCD_RS_PIN_4BIT));
	/*Wait for 40 msec*/
	_delay_ms(40);
	
	/*Send Function Set Command*/
	HLCD_VoidSendCommand(LCD_FunctionSetFixed_4BIT);
	/*Send Function Set Command*/
	HLCD_VoidSendCommand(LCD_FunctionSetFixed_4BIT);
	/*Send Function Set Command*/
	HLCD_VoidSendCommand(0x00|(LCD_LineNumbers_4BIT << PIN3)|(LCD_FontSize_4BIT << PIN2));
	
	/*Send Display ON/OFF Command*/
	HLCD_VoidSendCommand(LCD_DisplayFixed_4BIT);
	/*Send Display ON/OFF Command*/
	HLCD_VoidSendCommand((0x08)|(LCD_EntireDisplay_4BIT << PIN2)|(LCD_CursorDisplay_4BIT << PIN1)|(LCD_CursorBlinking_4BIT << PIN0));
	
	/*Send Clear Command*/
	HLCD_VoidSendCommand(LCD_ClearValue_HighNibble);
	/*Send Clear Command*/
	HLCD_VoidSendCommand(LCD_ClearValue_LowNibble);
	
#endif	
}

/**************************************************************************************************************************************
* Function Name		: HLCD_VoidSendCommand										                    								  *
* Parameters (in)	: uint8 Copy_uint8Command														                    			  *
* Parameters (out)	: None					                    																	  *
* Return value		: None										                    												  *
* Description		: Function to Send commands to the LCD					  		                    							  *
**************************************************************************************************************************************/
static void HLCD_VoidSendCommand(uint8 Copy_uint8Command)
{
#if(HALF_LOAD_4BITS == 0)	

	/*Set Rs Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, LOW);
	/*Set RW Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, LOW);
	
	/*Set Command on the Data Port*/
	MDIO_voidSetPortSpecificValue(LCD_DATA_PORT, 0xFF, Copy_uint8Command);
	
	/*Set En Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, HIGH);
	/*Wait for 2 msec*/
	_delay_ms(2);
	/*Set En Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, LOW);

#elif(HALF_LOAD_4BITS == 1)	
	
	/*Set Rs Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT_4BIT, LCD_RS_PIN_4BIT, LOW);
	/*Set RW Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT_4BIT, LCD_RW_PIN_4BIT, LOW);
	
	/*Set Command on the Data Port*/
	MDIO_voidSetPortSpecificValue(LCD_DATA_PORT_4BIT,\
	ALL_LOW|(HIGH << LCD_D0)|(HIGH << LCD_D1)|(HIGH << LCD_D2)|(HIGH << LCD_D3), Copy_uint8Command<<LCD_D0);
	
	/*Set En Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT_4BIT, LCD_EN_PIN_4BIT, HIGH);
	/*Wait for 2 msec*/
	_delay_ms(2);
	/*Set En Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT_4BIT, LCD_EN_PIN_4BIT, LOW);
	
#endif	
}

/**************************************************************************************************************************************
* Function Name		: HLCD_VoidSendData		                    																	  *
* Parameters (in)	: uint8 Copy_uint8Data						                    												  *
* Parameters (out)	: None															                    							  *
* Return value		: None																				                    		  *
* Description		: Function to Send Data to the LCD															                      *
**************************************************************************************************************************************/
void HLCD_VoidSendData(uint8 Copy_uint8Data)
{
#if(HALF_LOAD_4BITS == 0)	
		
	/*Set Rs Pin to be HIGH*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, HIGH);
	/*Set RW Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, LOW);
	/*Set Data on the Data Port*/
	MDIO_voidSetPortSpecificValue(LCD_DATA_PORT, 0xFF, Copy_uint8Data);
	/*Set En Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, HIGH);
	/*Wait for 2 msec*/
	_delay_ms(2);
	/*Set En Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_EN_PIN, LOW);
	
#elif(HALF_LOAD_4BITS == 1)	

	/*Set Rs Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT_4BIT, LCD_RS_PIN_4BIT, HIGH);
	/*Set RW Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT_4BIT, LCD_RW_PIN_4BIT, LOW);

	/*Set High Nibble Data on the Data Port*/
	MDIO_voidSetPortSpecificValue(LCD_DATA_PORT_4BIT,ALL_LOW|(HIGH << LCD_D0)|(HIGH << LCD_D1)|(HIGH << LCD_D2)|(HIGH << LCD_D3),\
						ALL_LOW|(GET_BIT(Copy_uint8Data,PIN4) << LCD_D0)|(GET_BIT(Copy_uint8Data,PIN5) << LCD_D1)|(GET_BIT(Copy_uint8Data,PIN6) << LCD_D2)|(GET_BIT(Copy_uint8Data,PIN7) << LCD_D3));
	
	/*Set En Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT_4BIT, LCD_EN_PIN_4BIT, HIGH);
	/*Wait for 2 msec*/
	_delay_ms(2);
	/*Set En Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT_4BIT, LCD_EN_PIN_4BIT, LOW);

	/*Set Low Nibble Data on the Data Port*/
	MDIO_voidSetPortSpecificValue(LCD_DATA_PORT_4BIT,ALL_LOW|(HIGH << LCD_D0)|(HIGH << LCD_D1)|(HIGH << LCD_D2)|(HIGH << LCD_D3),\
			ALL_LOW|(GET_BIT(Copy_uint8Data,PIN0) << LCD_D0)|(GET_BIT(Copy_uint8Data,PIN1) << LCD_D1)|(GET_BIT(Copy_uint8Data,PIN2) << LCD_D2)|(GET_BIT(Copy_uint8Data,PIN3) << LCD_D3));
	
	/*Set En Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT_4BIT, LCD_EN_PIN_4BIT, HIGH);
	/*Wait for 2 msec*/
	_delay_ms(2);
	/*Set En Pin to be Low*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT_4BIT, LCD_EN_PIN_4BIT, LOW);
	
#endif	
}

/**************************************************************************************************************************************
* Function Name		: HLCD_VoidSendString	                    																	  *
* Parameters (in)	: uint8 * Copy_uint8Data					                    												  *
* Parameters (out)	: None															                    							  *
* Return value		: None																				                    		  *
* Description		: Function to Send a string of Character to the LCD											                      *
**************************************************************************************************************************************/
void HLCD_VoidSendString(uint8 * Copy_uint8Data)
{
	
	uint8 Local_uint8LoopCounter = 0;
	
	while(Copy_uint8Data[Local_uint8LoopCounter] != '\0')
	 {
		/*Sending char by char from the string to the LCD till NULL*/
		HLCD_VoidSendData(Copy_uint8Data[Local_uint8LoopCounter]);
		/*Increment the Loop counter*/
		Local_uint8LoopCounter++;
	 }
	
}

/**************************************************************************************************************************************
* Function Name		: HLCD_VoidSendNumber		                    																  *
* Parameters (in)	: uint8 Copy_uint32Data							                    										  	  *
* Parameters (out)	: None																                    						  *
* Return value		: None																					                    	  *
* Description		: Function to Send a string of Numbers to the LCD											                      *
**************************************************************************************************************************************/
void HLCD_VoidSendNumber(uint32 Copy_uint32Data)
{
	/*Loop counter for the two Loops*/
	uint8 Local_uint8LoopCounter = 0;
	/*Extract single number in that variable*/
	uint8 Local_uint8SingleNumber = 0;
	/*Store number of Zeros at the end */
	uint8 Local_Copy_uint8DigitNumbers = 0;
	/*Store the reversed number*/
	uint32 Local_Copy_uint32DataReversed = 1;
	
	if(Copy_uint32Data != 0)
	{
		while(Copy_uint32Data != 0)
		{
			/*Extract Last single number from the whole number*/
			Local_uint8SingleNumber = Copy_uint32Data % 10;
			/*storing the number reversed*/
			Local_Copy_uint32DataReversed = (Local_Copy_uint32DataReversed*10) + (Local_uint8SingleNumber);
			/*Delete the extracted number from the whole number*/
			Copy_uint32Data /= 10;
			/*Increment the Loop counter*/
			Local_uint8LoopCounter++;
			/*Counting the digit numbers*/
			Local_Copy_uint8DigitNumbers++;
		}

		for(Local_uint8LoopCounter = 0; Local_uint8LoopCounter < Local_Copy_uint8DigitNumbers; Local_uint8LoopCounter++)
		{
			/*Extract Last single number from the whole number*/
			Local_uint8SingleNumber = Local_Copy_uint32DataReversed % 10;
			/*Delete the extracted number from the whole number*/
			Local_Copy_uint32DataReversed /= 10;
			/*Sending the extracted single number Asci code from the Asci array to the LCD */
			HLCD_VoidSendData(ZERO_ASCII_CODE + Local_uint8SingleNumber);
		}
	}
	else
	{
		HLCD_VoidSendData('0');
	}
}

/**************************************************************************************************************************************
* Function Name		: HLCD_VoidGoTo	                    																			  *
* Parameters (in)	: uint8 Copy_uint8_XPosition, uint8 Copy_uint8_YPosition					                    				  *
* Parameters (out)	: None															                    							  *
* Return value		: None																				                    		  *
* Description		: Function to go to specific coordinate in the LCD											                      *
**************************************************************************************************************************************/
void HLCD_VoidGoTo(uint8 Copy_uint8_XPosition, uint8 Copy_uint8_YPosition)
{
	/*Local varaiable to store the final Address of DDRAM*/
	uint8 Local_uint8PositionAdress = 0;
	
	if(Copy_uint8_XPosition == 0)
	{
		/*The user choosed the first row so the address will be the column only */
		Local_uint8PositionAdress = Copy_uint8_YPosition;
	}
	else if(Copy_uint8_XPosition == 1)
	{
		/*The user choosed the Second row so the address will be the column Plus 40 */
		Local_uint8PositionAdress = Copy_uint8_YPosition + POSITION_FIXED_ADRESS;
	}
	else
	{
		/*return error*/
	}
	
	/*Setting a fixed bit in the byte*/
	SET_BIT(Local_uint8PositionAdress, PIN7);


#if(HALF_LOAD_4BITS == 0)

	/*Sending the command*/
	HLCD_VoidSendCommand(Local_uint8PositionAdress);

#elif(HALF_LOAD_4BITS == 1)

	/*Set High Nibble Data on the Data Port*/
	HLCD_VoidSendCommand((Local_uint8PositionAdress >> 4) & 0x0F);
	/*Set High Nibble Data on the Data Port*/
	HLCD_VoidSendCommand((Local_uint8PositionAdress) & 0x0F);

#endif
}

/**************************************************************************************************************************************
* Function Name		: HLCD_VoidClearLcd	                    																		  *
* Parameters (in)	: None					                    								  									  *
* Parameters (out)	: None															                    							  *
* Return value		: None																				                    		  *
* Description		: Function to Clear the LCD											                   							  *
**************************************************************************************************************************************/
void HLCD_VoidClearLcd()
{
#if(HALF_LOAD_4BITS == 0)

	/*Send Clear Command*/
	HLCD_VoidSendCommand(LCD_ClearValue);

#elif(HALF_LOAD_4BITS == 1)

	/*Send Clear Command*/
	HLCD_VoidSendCommand(LCD_ClearValue_HighNibble);
	/*Send Clear Command*/
	HLCD_VoidSendCommand(LCD_ClearValue_LowNibble);

#endif
}

/**************************************************************************************************************************************
* Function Name		: HLCD_VoidSendCustomPattern	                    															  *
* Parameters (in)	: uint8 * Copy_uint8Data,uint8 Copy_uint8_PatternPosition,uint8 Copy_uint8_XPosition,uint8 Copy_uint8_YPosition   * 
*Parameters (out)	: None															                    							  *
* Return value		: None																				                    		  *
* Description		: Function to Clear the LCD											                   							  *
**************************************************************************************************************************************/
void HLCD_VoidSendCustomPattern(uint8 * Copy_uint8Data,  uint8 Copy_uint8_PatternPosition, uint8 Copy_uint8_XPosition, uint8 Copy_uint8_YPosition)
{
	uint8 Local_uint8_CGRAM_Adress = 0;
	uint8 Local_uint8_LoopCounter  = 0;
	
	Local_uint8_CGRAM_Adress = Copy_uint8_PatternPosition*8;
	
	SET_BIT(Local_uint8_CGRAM_Adress, PIN6);
	CLR_BIT(Local_uint8_CGRAM_Adress, PIN7);

#if(HALF_LOAD_4BITS == 0)

	HLCD_VoidSendCommand(Local_uint8_CGRAM_Adress);
	
#elif(HALF_LOAD_4BITS == 1)

	/*Set High Nibble Data on the Data Port*/
	HLCD_VoidSendCommand((Local_uint8_CGRAM_Adress >> 4) & 0x0F);
	/*Set High Nibble Data on the Data Port*/
	HLCD_VoidSendCommand((Local_uint8_CGRAM_Adress) & 0x0F);

#endif

	for(Local_uint8_LoopCounter = 0; Local_uint8_LoopCounter < 8; Local_uint8_LoopCounter++)
	{
		HLCD_VoidSendData(Copy_uint8Data[Local_uint8_LoopCounter]);
	}
	
	HLCD_VoidGoTo(Copy_uint8_XPosition, Copy_uint8_YPosition);
	HLCD_VoidSendData(Copy_uint8_PatternPosition);
}
