/**************************************************************************************************************************************
* LOG:                                               														     					  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION        				  		  *
* 1.0.0 					Kareem Hassaan						12 DEC,2021					- Initial Creation				  		  *
* 1.0.1 					Kareem Hassaan						15 DEC,2021					- Fix some bugs in 4bit mode			  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: LCD Driver                                                         							                      *
* ! File Name	: LCD_config.h                                                                          							  *
* ! Description : This file has the Configrations needed		     		        	 			                    			  *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL						                                         							                      *
**************************************************************************************************************************************/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#define HALF_LOAD_4BITS  				0x00				//Precompile Configration (0) for 8-Bit Data & (1) for 4-Bit Data.

/**************************************************************************************************************************************/
/******************************************************* 8-Bit Configrations **********************************************************/
/**************************************************************************************************************************************/

#define LCD_DATA_PORT    				PORTA				//Data Port
#define LCD_CONTROL_PORT 				PORTB				//Control Port

#define LCD_EN_PIN 						PIN0				//Enable Pin
#define LCD_RW_PIN 						PIN1				//Read / Write pin
#define LCD_RS_PIN 						PIN2				//Register selection Data or Command

#define LCD_FunctionSetFixed 			0x30        		//Fixed Command Value.
#define LCD_LineNumbers      			0x01		 		//PIN3 --> (0) for one line Display & (1) for two lines Display.
#define LCD_FontSize         			0x00				//PIN2 --> (0) for 5x7 Display      & (1) for 5x11 Display.

#define LCD_DisplayFixed     			0x08				//Fixed Command Value.
#define LCD_EntireDisplay    			0x01				//PIN2 --> (0) for Entire Display  OFF & (1) for Entire Display  ON.
#define LCD_CursorDisplay    			0x01				//PIN1 --> (0) for Cursor Display  OFF & (1) for Cursor Display  ON.
#define LCD_CursorBlinking   			0x01				//PIN0 --> (0) for Cursor Blinking OFF & (1) for Cursor Blinking ON.

#define LCD_ClearValue       			0x01				//Clear LCD Command

/**************************************************************************************************************************************/
/******************************************************* 4-Bit Configrations **********************************************************/
/**************************************************************************************************************************************/

#define LCD_DATA_PORT_4BIT    			PORTA				//Data Port
#define LCD_CONTROL_PORT_4BIT 			PORTB				//Control Port

#define LCD_D0 							PIN0				//Enable Pin
#define LCD_D1 							PIN1				//Read / Write pin
#define LCD_D2 							PIN2				//Register selection Data or Command
#define LCD_D3 							PIN3				//Register selection Data or Command

#define LCD_EN_PIN_4BIT 				PIN0				//Enable Pin
#define LCD_RW_PIN_4BIT 				PIN1				//Read / Write pin
#define LCD_RS_PIN_4BIT 				PIN2				//Register selection Data or Command

#define LCD_FunctionSetFixed_4BIT 		0x02        		//Fixed Command Value.
#define LCD_LineNumbers_4BIT      		0x01			 	//PIN3 --> (0) for one line Display & (1) for two lines Display.
#define LCD_FontSize_4BIT         		0x00			 	//PIN2 --> (0) for 5x7 Display      & (1) for 5x11 Display.

#define LCD_DisplayFixed_4BIT     		0x00				//Fixed Command Value.
#define LCD_EntireDisplay_4BIT    		0x01				//PIN2 --> (0) for Entire Display  OFF & (1) for Entire Display  ON.
#define LCD_CursorDisplay_4BIT    		0x01				//PIN1 --> (0) for Cursor Display  OFF & (1) for Cursor Display  ON.
#define LCD_CursorBlinking_4BIT   		0x01				//PIN0 --> (0) for Cursor Blinking OFF & (1) for Cursor Blinking ON.

#define LCD_ClearValue_HighNibble       0x00				//Clear LCD Command
#define LCD_ClearValue_LowNibble       	0x01				//Clear LCD Command

#endif /*LCD_CONFIG_H*/