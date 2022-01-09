/******************************************************************************************************************
* LOG:                                               														      *
* VERSION				AUTHOR           				DATE 				DESCRIPTION        				  	  *
* 1.0.0 				Kareem Hassaan					8 Dec,2021			- Initial Creation				  	  *
* 1.1.0 				  ~      ~						14 Dec,2021			- Changing Specific Port functions    *
******************************************************************************************************************/
/******************************************************************************************************************
* ! Title      	: DIO Driver                                                        							  *
* ! File Name	: DIO_program.c                                                       							  *
* ! Description : This file has the implementation of Basic of DIO functions        							  *
* ! Compiler  	: GNU AVR cross Compiler                                            							  *
* ! Target 	  	: Atmega32 Micro-Controller                                         							  *
* ! Layer 	  	: MCAL						                                         							  *
******************************************************************************************************************/

/***************************************** Libraries Inclusion ***************************************************/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
/**************************************** Lower Layer Inclusions *************************************************/

/**************************************** Self Layer Inclusions **************************************************/

/**************************************** Self Files Inclusions **************************************************/
/*Must be with that order maybe change Private with config only*/
#include"DIO_intrface.h"  
#include"DIO_private.h"
#include"DIO_config.h"

/*****************************************************************************************************************/
/******************************************* Functions Definition ************************************************/
/*****************************************************************************************************************/
/******************************************************************************************************************
* Function Name: MDIO_voidSetPinDirection																		  *
* Parameters (in): None																							  *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Set Pin Direction.														  *
******************************************************************************************************************/
void MDIO_voidSetPinDirection(uint8 Copy_uint8PortName, uint8 Copy_uint8PinNumber, uint8 Copy_uint8PinDirection)
{
	if(Copy_uint8PinNumber <= PIN7)
	{
		/*switch on which Port needed*/
		switch(Copy_uint8PortName)
		{
			case PORTA:
			
				/*switch on which Pin Direction needed*/
				switch(Copy_uint8PinDirection)
				{
					case INPUT:
						/*Set Pin needed INPUT in PortA By clear it in DDRA*/
						CLR_BIT(DIO_DDRA, Copy_uint8PinNumber);
						break;
					case OUTPUT:
						/*Set Pin needed OUTPUT in PortA By Set it in DDRA*/
						SET_BIT(DIO_DDRA, Copy_uint8PinNumber);
						break;
					default:
						/*Return error*/
						break;
				}
				break;
				
			case PORTB:
			
				/*switch on which Pin Direction needed*/
				switch(Copy_uint8PinDirection)
				{
					case INPUT:
						/*Set Pin needed INPUT in PortB By clear it in DDRB*/
						CLR_BIT(DIO_DDRB, Copy_uint8PinNumber);
						break;	
					case OUTPUT:
						/*Set Pin needed OUTPUT in PortB By Set it in DDRB*/
						SET_BIT(DIO_DDRB, Copy_uint8PinNumber);
						break;
					default:
						/*Return error*/
						break;
				}
				break;
				
			case PORTC:
			
				/*switch on which Pin Direction needed*/
				switch(Copy_uint8PinDirection)
				{
					case INPUT:
						/*Set Pin needed INPUT in PortC By clear it in DDRC*/
						CLR_BIT(DIO_DDRC, Copy_uint8PinNumber);
						break;
					case OUTPUT:
						/*Set Pin needed OUTPUT in PortC By Set it in DDRC*/
						SET_BIT(DIO_DDRC, Copy_uint8PinNumber);
						break;
					default:
						/*Return error*/
						break;
				}
				break;
				
			case PORTD:
			
				/*switch on which Pin Direction needed*/
				switch(Copy_uint8PinDirection)
				{
					case INPUT:
						/*Set Pin needed INPUT in PortD By clear it in DDRD*/
						CLR_BIT(DIO_DDRD, Copy_uint8PinNumber);
						break;
					case OUTPUT:
						/*Set Pin needed OUTPUT in PortD By Set it in DDRD*/
						SET_BIT(DIO_DDRD, Copy_uint8PinNumber);
						break;
					default:
						/*Return error*/
						break;
				}
				break;
				
			default:
			
				/*Return error*/
				break;
		}
	}
	else
	{
		/*Return error*/
	}
}
/******************************************************************************************************************
* Function Name: MDIO_voidSetPinValue																			  *
* Parameters (in): uint8 Copy_uint8PortName, uint8 Copy_uint8PinNumber, uint8 Copy_uint8PinValue  				  *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Set Pin Value.															  *
******************************************************************************************************************/
void MDIO_voidSetPinValue(uint8 Copy_uint8PortName, uint8 Copy_uint8PinNumber,uint8 Copy_uint8PinValue)
{
	if(Copy_uint8PinNumber <= PIN7)
	{
		/*switch on which Port needed*/
		switch(Copy_uint8PortName)
		{
			case PORTA:
				
				/*switch on which Pin Value needed*/
				switch(Copy_uint8PinValue)
				{
					case LOW:
						/*Set Pin needed LOW in PortA By Clear it in PortA REG*/
						CLR_BIT(DIO_PORTA, Copy_uint8PinNumber);
						break;
					case HIGH:
						/*Set Pin needed HIGH in PortA By Set it in PortA REG*/
						SET_BIT(DIO_PORTA, Copy_uint8PinNumber);
						break;
					default:
						/*Return error*/
						break;
				}
				break;
				
			case PORTB:
			
				/*switch on which Pin Value needed*/
				switch(Copy_uint8PinValue)
				{
					case LOW:
						/*Set Pin needed LOW in PortB By Clear it in PortB REG*/
						CLR_BIT(DIO_PORTB, Copy_uint8PinNumber);
						break;	
					case HIGH:
						/*Set Pin needed HIGH in PortB By Set it in PortB REG*/
						SET_BIT(DIO_PORTB, Copy_uint8PinNumber);
						break;
					default:
						/*Return error*/
						break;
				}
				break;
				
			case PORTC:
				
				/*switch on which Pin Value needed*/
				switch(Copy_uint8PinValue)
				{
					case LOW:
						/*Set Pin needed LOW in PortC By Clear it in PortC REG*/
						CLR_BIT(DIO_PORTC, Copy_uint8PinNumber);
						break;
					case HIGH:
						/*Set Pin needed HIGH in PortC By Set it in PortC REG*/
						SET_BIT(DIO_PORTC, Copy_uint8PinNumber);
						break;
					default:
						/*Return error*/
						break;
				}
				break;
				
			case PORTD:
				
				/*switch on which Pin Value needed*/
				switch(Copy_uint8PinValue)
				{
					case LOW:
						/*Set Pin needed LOW in PortD By Clear it in PortD REG*/
						CLR_BIT(DIO_PORTD, Copy_uint8PinNumber);
						break;
					case HIGH:
						/*Set Pin needed HIGH in PortD By Set it in PortD REG*/
						SET_BIT(DIO_PORTD, Copy_uint8PinNumber);
						break;
					default:
						/*Return error*/
						break;
				}
				break;
			
			default:
			
				/*Return error*/
				break;
		}
	}
	else
	{
		/*Return error*/
	}
}
/******************************************************************************************************************
* Function Name: MDIO_uint8GetPinValue																			  *
* Parameters (in): uint8 Copy_uint8PortName, uint8 Copy_uint8PinNumber							   				  *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Get Pin Value.															  *
******************************************************************************************************************/
uint8 MDIO_uint8GetPinValue(uint8 Copy_uint8PortName, uint8 Copy_uint8PinNumber)
{
	/*Return variable to store in it the Pin Needed value*/
	uint8 Local_uint8PinValue;
	
	if(Copy_uint8PinNumber <= PIN7)
	{
		/*switch on which Port needed*/
		switch(Copy_uint8PortName)
		{
			case PORTA:
				/*Getting the Needed Pin Value in PORTA and store it in the Return variable*/
				Local_uint8PinValue = GET_BIT(DIO_PINA,Copy_uint8PinNumber);
				break;
				
			case PORTB:
				/*Getting the Needed Pin Value in PORTB and store it in the Return variable*/
				Local_uint8PinValue = GET_BIT(DIO_PINB,Copy_uint8PinNumber);
				break;
				
			case PORTC:
				/*Getting the Needed Pin Value in PORTC and store it in the Return variable*/
				Local_uint8PinValue = GET_BIT(DIO_PINC,Copy_uint8PinNumber);
				break;
				
			case PORTD:
				/*Getting the Needed Pin Value in PORTD and store it in the Return variable*/
				Local_uint8PinValue = GET_BIT(DIO_PIND,Copy_uint8PinNumber);
				break;
			
			default:
			
				/*Return error*/
				break;
		}
	}
	else
	{
		/*Return error*/
	}
	
	/*Returning the Pin Needed value*/
	return Local_uint8PinValue;
}
/******************************************************************************************************************
* Function Name: MDIO_voidSetPortDirection																		  *
* Parameters (in): uint8 Copy_uint8PortName, uint8 Copy_uint8PortDirection										  *
* Parameters (out): None																						  *
* Return value: None																						      *
* Description: Function declaration to Set Port Direction.														  *
******************************************************************************************************************/
void MDIO_voidSetPortDirection(uint8 Copy_uint8PortName, uint8 Copy_uint8PortDirection)
{
	if((Copy_uint8PortDirection == ALL_INPUT) || (Copy_uint8PortDirection == ALL_OUTPUT))
	{
		/*switch on which Port needed*/
		switch(Copy_uint8PortName)
		{
			case PORTA:
				/*Setting all PORTA All input (0x00) or All output (0xFF)*/
				DIO_DDRA = Copy_uint8PortDirection;
				break;
				
			case PORTB:
				/*Setting all PORTB All input (0x00) or All output (0xFF)*/
				DIO_DDRB = Copy_uint8PortDirection;
				break;
				
			case PORTC:
				/*Setting all PORTC All input (0x00) or All output (0xFF)*/
				DIO_DDRC = Copy_uint8PortDirection;
				break;
				
			case PORTD:
				/*Setting all PORTD All input (0x00) or All output (0xFF)*/
				DIO_DDRD = Copy_uint8PortDirection;
				break;
			
			default:
			
				/*Return error*/
				break;
		}
	}
	else
	{
		/*Return error*/
	}
}
/******************************************************************************************************************
* Function Name: MDIO_voidSetPortValue																			  *
* Parameters (in): uint8 Copy_uint8PortName, uint8 Copy_uint8PortValue											  *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Set Port Value.															  *
******************************************************************************************************************/
void MDIO_voidSetPortValue(uint8 Copy_uint8PortName, uint8 Copy_uint8PortValue)
{
	if((Copy_uint8PortValue == ALL_LOW) || (Copy_uint8PortValue == ALL_HIGH))
	{
		/*switch on which Port needed*/
		switch(Copy_uint8PortName)
		{
			case PORTA:
				/*Setting all PORTA All Low (0x00) or All High (0xFF)*/
				DIO_PORTA = Copy_uint8PortValue;
				break;
				
			case PORTB:
				/*Setting all PORTB All Low (0x00) or All High (0xFF)*/
				DIO_PORTB = Copy_uint8PortValue;
				break;
				
			case PORTC:
				/*Setting all PORTC All Low (0x00) or All High (0xFF)*/
				DIO_PORTC = Copy_uint8PortValue;
				break;
				
			case PORTD:
				/*Setting all PORTD All Low (0x00) or All High (0xFF)*/
				DIO_PORTD = Copy_uint8PortValue;
				break;
				
			default:
			
				/*Return error*/
				break;
		}
	}
	else
	{
		/*Return error*/
	}
}
/******************************************************************************************************************
* Function Name: MDIO_voidSetPortSpecificDirection																  *
* Parameters (in): uint8 Copy_uint8PortName, uint8 Copy_uint8PinsMask, uint8 Copy_uint8PortSpecificDirection      *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Set Port Specific Direction.												  *
******************************************************************************************************************/
void MDIO_voidSetPortSpecificDirection(uint8 Copy_uint8PortName, uint8 Copy_uint8PinsMask, uint8 Copy_uint8PortSpecificDirection)
{
	uint8 Local_uint8LoopCounter;

	if((Copy_uint8PortName == PORTA)||(Copy_uint8PortName == PORTB)||(Copy_uint8PortName == PORTC)||(Copy_uint8PortName == PORTD))
	{
		/*Setting the value of DDRA (Direction of Pins) as the Specific value entered*/
		for(Local_uint8LoopCounter = PIN0; Local_uint8LoopCounter <= PIN7; Local_uint8LoopCounter++)
		{
			if(GET_BIT(Copy_uint8PinsMask, Local_uint8LoopCounter))
			{
				if(INPUT == GET_BIT(Copy_uint8PortSpecificDirection, Local_uint8LoopCounter))
				{
					MDIO_voidSetPinDirection(Copy_uint8PortName, Local_uint8LoopCounter, INPUT);

				}
				else if(OUTPUT == (GET_BIT(Copy_uint8PortSpecificDirection, Local_uint8LoopCounter)))
				{
					MDIO_voidSetPinDirection(Copy_uint8PortName, Local_uint8LoopCounter, OUTPUT);
				}
			}
		}
	}
	else
	{
		/*return error*/
	}
}
/******************************************************************************************************************
* Function Name: MDIO_voidSetPortSpecificValue																	  *
* Parameters (in): uint8 Copy_uint8PortName, uint8 Copy_uint8PinsMask, uint8 Copy_uint8PortSpecificValue		  *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Set Port Specific Value.													  *
******************************************************************************************************************/
void MDIO_voidSetPortSpecificValue(uint8 Copy_uint8PortName, uint8 Copy_uint8PinsMask, uint8 Copy_uint8PortSpecificValue)
{
	uint8 Local_uint8LoopCounter;

	if((Copy_uint8PortName == PORTA)||(Copy_uint8PortName == PORTB)||(Copy_uint8PortName == PORTC)||(Copy_uint8PortName == PORTD))
	{
		/*Setting the value of DDRA (Direction of Pins) as the Specific value entered*/
		for(Local_uint8LoopCounter = PIN0; Local_uint8LoopCounter <= PIN7; Local_uint8LoopCounter++)
		{
			if(GET_BIT(Copy_uint8PinsMask, Local_uint8LoopCounter))
			{
				if(LOW == GET_BIT(Copy_uint8PortSpecificValue, Local_uint8LoopCounter))
				{
					MDIO_voidSetPinValue(Copy_uint8PortName, Local_uint8LoopCounter, LOW);

				}
				else if(HIGH == (GET_BIT(Copy_uint8PortSpecificValue, Local_uint8LoopCounter)))
				{
					MDIO_voidSetPinValue(Copy_uint8PortName, Local_uint8LoopCounter, HIGH);
				}
			}
		}
	}
	else
	{
		/*return error*/
	}
}
/******************************************************************************************************************
* Function Name: MDIO_uint8GetPortValue																			  *
* Parameters (in): uint8 Copy_uint8PortName														   				  *
* Parameters (out): None																						  *
* Return value: None																							  *
* Description: Function declaration to Get Port Value.															  *
******************************************************************************************************************/
uint8 MDIO_uint8GetPortValue(uint8 Copy_uint8PortName)
{
	/*Return variable to store in it the Pin Needed value*/
	uint8 Local_uint8PortValue;

	/*switch on which Port needed*/
	switch(Copy_uint8PortName)
	{
		case PORTA:
			/*Getting the Needed PortA Value and store PINA REG in the Return variable*/
			Local_uint8PortValue = DIO_PINA;
			break;
			
		case PORTB:
			/*Getting the Needed PortB Value and store PINB REG in the Return variable*/
			Local_uint8PortValue = DIO_PINB;
			break;
			
		case PORTC:
			/*Getting the Needed PortC Value and store PINC REG in the Return variable*/
			Local_uint8PortValue = DIO_PINC;
			break;
			
		case PORTD:
			/*Getting the Needed PortD Value and store PIND REG in the Return variable*/
			Local_uint8PortValue = DIO_PIND;
			break;

		default:
		
			/*Return error*/
			break;
	}

	/*Returning the Port Needed value*/
	return Local_uint8PortValue;
}

