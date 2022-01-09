/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						14 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: KEYPAD Driver                                                        							                      *
* ! File Name	: KEYPAD_program.c                                                     							                      *
* ! Description : This file has the implementation of Basic functions of KEYPAD (4x4 Keypad)  						                  *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                   						                                         							  *
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
#include"KEYPAD_intrface.h"  
#include"KEYPAD_private.h"
#include"KEYPAD_config.h"


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HKPD_VoidInit												    							                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to initialize the Keypad matrix		    					 					                      *
**************************************************************************************************************************************/
void HKPD_VoidInit()
{
	/*Configure the direction of Row Pins as Input*/
	MDIO_voidSetPinDirection(KPD_PORT, KPD_ROW0_PIN, INPUT);
	MDIO_voidSetPinDirection(KPD_PORT, KPD_ROW1_PIN, INPUT);
	MDIO_voidSetPinDirection(KPD_PORT, KPD_ROW2_PIN, INPUT);
	MDIO_voidSetPinDirection(KPD_PORT, KPD_ROW3_PIN, INPUT);
	
	/*Activate Pull up resistor for row Pins*/
	MDIO_voidSetPinValue(KPD_PORT, KPD_ROW0_PIN, HIGH);
	MDIO_voidSetPinValue(KPD_PORT, KPD_ROW1_PIN, HIGH);
	MDIO_voidSetPinValue(KPD_PORT, KPD_ROW2_PIN, HIGH);
	MDIO_voidSetPinValue(KPD_PORT, KPD_ROW3_PIN, HIGH);
	
	/*Configure the direction of Columns Pins as Output*/
	MDIO_voidSetPinDirection(KPD_PORT, KPD_COL0_PIN, OUTPUT);
	MDIO_voidSetPinDirection(KPD_PORT, KPD_COL1_PIN, OUTPUT);
	MDIO_voidSetPinDirection(KPD_PORT, KPD_COL2_PIN, OUTPUT);
	MDIO_voidSetPinDirection(KPD_PORT, KPD_COL3_PIN, OUTPUT);
	
	/*Deactivate All columns*/
	MDIO_voidSetPinValue(KPD_PORT, KPD_COL0_PIN, HIGH);
	MDIO_voidSetPinValue(KPD_PORT, KPD_COL1_PIN, HIGH);
	MDIO_voidSetPinValue(KPD_PORT, KPD_COL2_PIN, HIGH);
	MDIO_voidSetPinValue(KPD_PORT, KPD_COL3_PIN, HIGH);
	
}

/**************************************************************************************************************************************
* Function Name		: HKPD_uint8GetPressedKey															    	                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: uint8																						                      *
* Description		: Function to get the pressed Key from the Keypad matrix		    		    			                      *
**************************************************************************************************************************************/
uint8 HKPD_uint8GetPressedKey()
{
	/*loop Counter for Columns for*/
	uint8 Local_uint8ColLoopCounter = 0;
	/*loop Counter for Rows for*/
	uint8 Local_uint8RowLoopCounter = 0;
	/*Storing the Pin State 0 or 1*/
	uint8 Local_uint8PinState = 0;
	/*Storing the real value of the key from the KPD_MatrixArray*/
	uint8 Local_uint8PressedKey = 0xFF;
	
	/*Initialize the real values of each Key*/
	uint8 Local_uint8KPD_MatrixArray[KPD_ROW_NUM][KPD_COL_NUM] = KPD_Matrix_Arr;
	
	
	/*Array for Columns for looping*/
	uint8 Local_uint8ColArray[KPD_COL_NUM] = {KPD_COL0_PIN, KPD_COL1_PIN, KPD_COL2_PIN, KPD_COL3_PIN};
	/*Array for Rows for looping*/
	uint8 Local_uint8ROWArray[KPD_ROW_NUM] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
	
	for(Local_uint8ColLoopCounter = 0; Local_uint8ColLoopCounter < KPD_COL_NUM; Local_uint8ColLoopCounter++)
	{
		/*Activate the current col*/
		MDIO_voidSetPinValue(KPD_PORT, Local_uint8ColArray[Local_uint8ColLoopCounter], LOW);
		
		for(Local_uint8RowLoopCounter = 0; Local_uint8RowLoopCounter < KPD_ROW_NUM; Local_uint8RowLoopCounter++)
		{
			/*Get the current Row Pin Value*/
			Local_uint8PinState = MDIO_uint8GetPinValue(KPD_PORT, Local_uint8ROWArray[Local_uint8RowLoopCounter]);
			
			if(Local_uint8PinState == 0)
			{
				/*Return the Pressed Key*/
				while(Local_uint8PinState == 0)
				{
					/*Get the current Row Pin Value*/
					Local_uint8PinState = MDIO_uint8GetPinValue(KPD_PORT, Local_uint8ROWArray[Local_uint8RowLoopCounter]);
					/*Getting the real value of the key from the KPD_MatrixArray*/
					Local_uint8PressedKey = Local_uint8KPD_MatrixArray[Local_uint8RowLoopCounter][Local_uint8ColLoopCounter];
				}
				_delay_ms(200);
				return Local_uint8PressedKey;
			}

		}
		
		/*Deactivate the current col*/
		MDIO_voidSetPinValue(KPD_PORT, Local_uint8ColArray[Local_uint8ColLoopCounter], HIGH);
	}
	/*No Key Pressd*/
	return Local_uint8PressedKey;
}


