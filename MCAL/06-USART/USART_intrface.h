/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						30 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: USART Driver                                                        							                      *                     
* ! File Name	: USART_intrface.h                                                     							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#define TRANSMIT		0															//To Choose the ISR Type to Transmit
#define UDR_EMPTY		1															//To Choose the ISR Type to UDR Empty
#define RECEIVE			2															//To Choose the ISR Type to Receive

/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MUSART_VoidInit																			                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Configer All Pre-Build in USART												                      *
**************************************************************************************************************************************/
void MUSART_VoidInit();
/**************************************************************************************************************************************
* Function Name		: MUSART_VoidTransimt																		                      *
* Parameters (in)	: Copy_sint16Data																			                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Transmit Data		             			  									                      *
**************************************************************************************************************************************/
void MUSART_VoidTransimt(sint16 Copy_sint16Data);
/**************************************************************************************************************************************
* Function Name		: MUSART_VoidReceive																		                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: Local_sint16ReturnData																	                      *
* Description		: Function To Receive Data								  									                      *
**************************************************************************************************************************************/
sint16 MUSART_VoidReceive();
/**************************************************************************************************************************************
* Function Name		: MUSART_VoidSendNumber																			                  *
* Parameters (in)	: Copy_uint32Data																			                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Send An Integer Number					  									                      *
**************************************************************************************************************************************/
void MUSART_VoidSendNumber(uint32 Copy_uint32Data);
/**************************************************************************************************************************************
* Function Name		: MUSART_VoidSendString																			                  *
* Parameters (in)	: uint8 * Copy_uint8Data																	                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function To Send String								  									                      *
**************************************************************************************************************************************/
void MUSART_VoidSendString(uint8 * Copy_uint8Data);
/**************************************************************************************************************************************
* Function Name		: MUSART_voidSetCallBack 																	                      *
* Parameters (in)	: uint8 Copy_uint8TimerISRType, void (*Copy_pvCallbackFunction)(void))				  							  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set Function to the ISR of the USART          					  					              *
**************************************************************************************************************************************/
void MUSART_voidSetCallBack(uint8 Copy_uint8USARTISRType, void (*Copy_pvCallbackFunction)(void));

#endif /*USART_INTERFACE_H*/