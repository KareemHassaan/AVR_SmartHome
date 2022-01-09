/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						30 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: USART Driver                                                        							                      *
* ! File Name	: USART_program.c                                                       							                  *
* ! Description : This file has the implementation of Basic of USART functions        							                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
/************************************************** Lower Layer Inclusions ***********************************************************/

/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
/*Must be with that order maybe change Private with config only*/
#include"USART_intrface.h"  
#include"USART_private.h"
#include"USART_config.h"

/***************************************************** Global Variables **************************************************************/
static void (*Global_pvUSARTCallBack[USART_ISR_NUM])(void);					  	// USART Array of Pointers to ISR Function 

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MUSART_VoidInit																			                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Configer All Pre-Build in USART												                      *
**************************************************************************************************************************************/
void MUSART_VoidInit()
{
	/*Checking if the USART Enabled or Not*/
	 #if USART_ENABLE == ENABLE
	
		/*Checking if the USART Interrupt Enabled or Not*/
		 #if USART_INTERRUPT_ENABLE == ENABLE
		
			/*Enable RX Complete Interrupt*/
			 SET_BIT(UCSRB, UCSRB_RXCIE);
			/*Enable TX Complete Interrupt*/
			 SET_BIT(UCSRB, UCSRB_TXCIE);
			/*Enable USART Data Register Empty Interrupt*/
			 SET_BIT(UCSRB, UCSRB_UDRIE);
			
		 #elif USART_INTERRUPT_ENABLE == DISABLE
		
			/*Disable RX Complete Interrupt*/
			 CLR_BIT(UCSRB, UCSRB_RXCIE);
			/*Disable TX Complete Interrupt*/
			 CLR_BIT(UCSRB, UCSRB_TXCIE);
			/*Disable USART Data Register Empty Interrupt*/
			 CLR_BIT(UCSRB, UCSRB_UDRIE);
			
		 #else
			 
			/*Printig an Error Message That USART_INTERRUPT_ENABLE Configration error*/
			 #error"USART_INTERRUPT_ENABLE Configration error"
			
		 #endif 
		
		
		/*Checking the USART in Which Mode*/
		 #if SYNCHRONOUS_ENABLE == ASYNCHRONOUS_OPERATION
		
			/*Checking the USART in Which Speed Mode*/
			 #if SENDING_SPEED == NORMAL_SPEED
			
				/*Setting the Baudrate on Asychronous~Normal Speed Equation*/
				 UBRR = (CPU_CLK/(16.0*BAUD_RATE))-1.0;
				/*Disable Double Speed Mode*/
				 CLR_BIT(UCSRA, UCSRA_U2X);
				
			 #elif SENDING_SPEED == DOUBLE_SPEED
				
				/*Setting the Baudrate on Asychronous~Double Speed Equation*/
				 UBRR = (CPU_CLK/(8.0*BAUD_RATE))-1.0;
				/*Enable Double Speed Mode*/
				 SET_BIT(UCSRA, UCSRA_U2X);
				
			 #else
				
				/*Printig an Error Message That SENDING_SPEED Configration error*/
				 #error"SENDING_SPEED Configration error"
				
			 #endif
			
		 #elif SYNCHRONOUS_ENABLE == SYNCHRONOUS_OPERATION
	
			/*Setting the Baudrate on Sychronous Equation*/
			 UBRR = (CPU_CLK/(2.0*BAUD_RATE))-1.0;
	
		 #else
			
			/*Printig an Error Message That SYNCHRONOUS_ENABLE Configration error*/
			 #error"SYNCHRONOUS_ENABLE Configration error"
			
		 #endif  
	
		
		/*Setting UCSRC Reg with Selection to it in one Clk Cycle*/
		 UCSRC = (UCSRC_SELECT<<UCSRC_URSEL)|(SYNCHRONOUS_ENABLE<<UCSRC_UMSEL)|(PARITY_ENABLE<<UCSRC_UPM0)|\
				 (DOUBLE_STOP_BIT_ENABLE<<UCSRC_USBS)|(DATA_SIZE<<UCSRC_UCSZ0)|(EDGE_SELECT<<UCSRC_UCPOL);
		
		
		/*Checking the Data Size If it is 9-Bits or Not*/
		 #if DATA_SIZE == UCSRC_DATA_SIZE_9_BIT
			
			/*Enable 9-Bit Mode*/
			 SET_BIT(UCSRB, UCSRB_UCSZ2);
			
		 #else
			
			/*Disable 9-Bit Mode*/
			 CLR_BIT(UCSRB, UCSRB_UCSZ2);
			
		 #endif
		
		/*Enable Transmitter*/
		 SET_BIT(UCSRB, UCSRB_TXEN);
		/*Enable Receiver*/
		 SET_BIT(UCSRB, UCSRB_RXEN);
			
	    	
	 #elif USART_ENABLE == DISABLED
		
		/*Disable Transmitter*/
		 CLR_BIT(UCSRB, UCSRB_TXEN);
		/*Disable Receiver*/
		 CLR_BIT(UCSRB, UCSRB_RXEN);
		
	 #else
		
		/*Printig an Error Message That USART_ENABLE Configration error*/
		 #error"USART_ENABLE Configration error"
		 
	 #endif

}

/**************************************************************************************************************************************
* Function Name		: MUSART_VoidTransimt																		                      *
* Parameters (in)	: Copy_sint16Data																			                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Transmit Data		             			  									                      *
**************************************************************************************************************************************/
void MUSART_VoidTransimt(sint16 Copy_sint16Data)
{
	/* Wait for empty transmit buffer */
	 while (!GET_BIT(UCSRA,UCSRA_UDRE));
	
	/*Checking the Data Size If it is 9-Bits or Not*/
	 #if DATA_SIZE == UCSRC_DATA_SIZE_9_BIT
		
		/*Checking Bit 8 is 1 or 0*/		
		 if(GET_BIT(Copy_sint16Data,NINTH_BIT))
		 {
			/*Set Bit 8*/
			 SET_BIT(UCSRB,UCSRB_TXB8);
		 }
		 else
		 {
			/*Clear Bit 8*/
			 CLR_BIT(UCSRB,UCSRB_TXB8);
		 }
	 #endif
	
	/* Put data into buffer, sends the data */
	 UDR = Copy_sint16Data;
}

/**************************************************************************************************************************************
* Function Name		: MUSART_VoidReceive																		                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: Local_sint16ReturnData																	                      *
* Description		: Function To Receive Data								  									                      *
**************************************************************************************************************************************/
sint16 MUSART_VoidReceive()
{
	/*Local Variable To Return Tha Received Message*/
	 sint16 Local_sint16ReturnData = 0;
	
	/* Wait for data to be received */
	 while (!GET_BIT(UCSRA,UCSRA_RXC));
	
	/*Checking If the Error Checking Enabled or Not*/
	 #if ERROR_CHECK_ENABLE == ENABLE
		
		 if(GET_BIT(UCSRA,UCSRA_FE) || GET_BIT(UCSRA,UCSRA_DOR) || GET_BIT(UCSRA,UCSRA_PE))
		 {
			/*Return -1 if there is an error*/
			 Local_sint16ReturnData = -1;
		 }
		
	 #endif
	
	/*Checking the Data Size If it is 9-Bits or Not*/
	#if DATA_SIZE == UCSRC_DATA_SIZE_9_BIT
	
		/*Checking Bit 8 is 1 or 0*/
		 if(GET_BIT(UCSRB,UCSRB_TXB8))
		 {
			/*Set Bit 8*/
		 	 SET_BIT(Local_sint16ReturnData,NINTH_BIT);
		 }
		 else
		 {
			/*Clear Bit 8*/
		 	 CLR_BIT(Local_sint16ReturnData,NINTH_BIT);
		 }
	
	#endif
	
	/*Storing The Rest 8-Bits*/
	Local_sint16ReturnData |= UDR;
	
	/*Return received data from buffer */
	 return Local_sint16ReturnData;
}

/**************************************************************************************************************************************
* Function Name		: MUSART_VoidSendNumber																			                  *
* Parameters (in)	: Copy_uint32Data																			                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Send An Integer Number					  									                      *
**************************************************************************************************************************************/
void MUSART_VoidSendNumber(uint32 Copy_uint32Data)
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
			MUSART_VoidTransimt('0' + Local_uint8SingleNumber);
		}
	}
	else
	{
		/*Sending Char Zero*/
		MUSART_VoidTransimt('0');
	}
}

/**************************************************************************************************************************************
* Function Name		: MUSART_VoidSendString																			                  *
* Parameters (in)	: uint8 * Copy_uint8Data																	                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Send String								  									                      *
**************************************************************************************************************************************/
void MUSART_VoidSendString(uint8 * Copy_uint8Data)
{
	
	uint8 Local_uint8LoopCounter = 0;
	
	while(Copy_uint8Data[Local_uint8LoopCounter] != '\0')
	 {
		/*Sending char by char from the string on the USART till NULL*/
		MUSART_VoidTransimt(Copy_uint8Data[Local_uint8LoopCounter]);
		/*Increment the Loop counter*/
		Local_uint8LoopCounter++;
	 }
}

/**************************************************************************************************************************************
* Function Name		: MUSART_voidSetCallBack 																	                      *
* Parameters (in)	: uint8 Copy_uint8TimerISRType, void (*Copy_pvCallbackFunction)(void))				  							  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set Function to the ISR of the USART          					  					              *
**************************************************************************************************************************************/
void MUSART_voidSetCallBack(uint8 Copy_uint8USARTISRType, void (*Copy_pvCallbackFunction)(void))
{
	switch(Copy_uint8USARTISRType)
	{
		case TRANSMIT:
				Global_pvUSARTCallBack[TRANSMIT]=Copy_pvCallbackFunction;
		break;
		
		case UDR_EMPTY:
				Global_pvUSARTCallBack[UDR_EMPTY]=Copy_pvCallbackFunction;
		break;
		
		case RECEIVE:
				Global_pvUSARTCallBack[RECEIVE]=Copy_pvCallbackFunction;
		break;
	}
}


/*************************************************************************************************************************************/
/********************************************************* Reciver ISR ***************************************************************/
/*************************************************************************************************************************************/
void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	/*Check If The Global Pointer To Function has its Initial Value or not*/
	if(Global_pvUSARTCallBack[TRANSMIT] != NULL)
	{
		/*Invoke The Callback Function*/
		Global_pvUSARTCallBack[TRANSMIT]();
	}
	else
	{
		/*Do Nothing*/
	}
}

/*************************************************************************************************************************************/
/******************************************************** UDR Empty ISR **************************************************************/
/*************************************************************************************************************************************/
void __vector_14 (void) __attribute__((signal));
void __vector_14 (void)
{
	/*Check If The Global Pointer To Function has its Initial Value or not*/
	if(Global_pvUSARTCallBack[UDR_EMPTY] != NULL)
	{
		/*Invoke The Callback Function*/
		Global_pvUSARTCallBack[UDR_EMPTY]();
	}
	else
	{
		/*Do Nothing*/
	}
}

/*************************************************************************************************************************************/
/********************************************************* Transmit ISR **************************************************************/
/*************************************************************************************************************************************/
void __vector_15 (void) __attribute__((signal));
void __vector_15 (void)
{
	/*Check If The Global Pointer To Function has its Initial Value or not*/
	if(Global_pvUSARTCallBack[RECEIVE] != NULL)
	{
		/*Invoke The Callback Function*/
		Global_pvUSARTCallBack[RECEIVE]();
	}
	else
	{
		/*Do Nothing*/
	}
}
