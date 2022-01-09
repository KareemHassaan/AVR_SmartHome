/******************************************************************************************************************
* LOG:                                               														      *
* VERSION				AUTHOR           				DATE 				DESCRIPTION        				  	  *
* 1.0.0 				Kareem Hassaan					8 Dec,2021			- Initial Creation				  	  *
* 1.1.0 				  ~      ~						14 Dec,2021			- Changing Specific Port functions    *
******************************************************************************************************************/
/******************************************************************************************************************
* ! Title      	: DIO Driver                                                        							  *
* ! File Name	: DIO_intrface.h                                                     							  *
* ! Description : This file has the Definitions needed		         		        							  *
* ! Compiler  	: GNU AVR cross Compiler                                            							  *
* ! Target 	  	: Atmega32 Micro-Controller                                         							  *
* ! Layer 	  	: MCAL						                                         							  *
******************************************************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
/*****************************************************************************************************************/
/******************************************* Functions Prototypes ************************************************/
/*****************************************************************************************************************/
/******************************************************************************************************************
* Function Name: MDIO_voidSetPinDirection																		  *
* Parameters (in): None																							  *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Set Pin Direction.														  *
******************************************************************************************************************/
void MDIO_voidSetPinDirection(uint8 Copy_uint8PortName, uint8 Copy_uint8PinNumber,uint8 Copy_uint8PortDirection);
/******************************************************************************************************************
* Function Name: MDIO_voidSetPinValue																			  *
* Parameters (in): uint8 Copy_uint8PortName, uint8 Copy_uint8PinNumber, uint8 Copy_uint8PinValue  				  *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Set Pin Value.															  *
******************************************************************************************************************/
void MDIO_voidSetPinValue(uint8 Copy_uint8PortName, uint8 Copy_uint8PinNumber,uint8 Copy_uint8PinValue);
/******************************************************************************************************************
* Function Name: MDIO_uint8GetPinValue																			  *
* Parameters (in): uint8 Copy_uint8PortName, uint8 Copy_uint8PinNumber							   				  *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Get Pin Value.															  *
******************************************************************************************************************/
uint8 MDIO_uint8GetPinValue(uint8 Copy_uint8PortName, uint8 Copy_uint8PinNumber);
/******************************************************************************************************************
* Function Name: MDIO_voidSetPortDirection																		  *
* Parameters (in): uint8 Copy_uint8PortName, uint8 Copy_uint8PortDirection										  *
* Parameters (out): None																						  *
* Return value: None																						      *
* Description: Function declaration to Set Port Direction.														  *
******************************************************************************************************************/
void MDIO_voidSetPortDirection(uint8 Copy_uint8PortName, uint8 Copy_uint8PortDirection);
/******************************************************************************************************************
* Function Name: MDIO_voidSetPortValue																			  *
* Parameters (in): uint8 Copy_uint8PortName, uint8 Copy_uint8PortValue											  *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Set Port Value.															  *
******************************************************************************************************************/
void MDIO_voidSetPortValue(uint8 Copy_uint8PortName, uint8 Copy_uint8PortValue);
/******************************************************************************************************************
* Function Name: MDIO_voidSetPortSpecificDirection																  *
* Parameters (in): uint8 Copy_uint8PortName, uint8 Copy_uint8PinsMask, uint8 Copy_uint8PortSpecificDirection      *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Set Port Specific Direction.												  *
******************************************************************************************************************/
void MDIO_voidSetPortSpecificDirection(uint8 Copy_uint8PortName, uint8 Copy_uint8PinsMask, uint8 Copy_uint8PortSpecificDirection);
/******************************************************************************************************************
* Function Name: MDIO_voidSetPortSpecificValue																	  *
* Parameters (in): uint8 Copy_uint8PortName, uint8 Copy_uint8PinsMask, uint8 Copy_uint8PortSpecificValue		  *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Set Port Specific Value.													  *
******************************************************************************************************************/
void MDIO_voidSetPortSpecificValue(uint8 Copy_uint8PortName, uint8 Copy_uint8PinsMask, uint8 Copy_uint8PortSpecificValue);
/******************************************************************************************************************
* Function Name: MDIO_uint8GetPortValue																			  *
* Parameters (in): uint8 Copy_uint8PortName														   				  *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Get Port Value.															  *
******************************************************************************************************************/
uint8 MDIO_uint8GetPortValue(uint8 Copy_uint8PortName);

/*****************************************************************************************************************/
/******************************************** Ports Definitions **************************************************/
/*****************************************************************************************************************/

/********************************************** Ports Macros *****************************************************/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/*********************************************** Pins Macros *****************************************************/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/********************************************** I/O Macros ******************************************************/
#define INPUT  0
#define OUTPUT 1 

#define ALL_INPUT  0x00
#define ALL_OUTPUT 0xFF

/********************************************** H/L Macros ******************************************************/
#define LOW  0
#define HIGH 1 

#define ALL_LOW  0x00
#define ALL_HIGH 0xFF

#endif /*DIO_INTERFACE_H*/