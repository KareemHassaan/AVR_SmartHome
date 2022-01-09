/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						26 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: ADC Driver                                                        							                      *                     
* ! File Name	: ADC_intrface.h                                                     							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ENABLE 					1
#define DISABLE 				0 

#define ADC0					0b00000
#define ADC1                   	0b00001
#define ADC2                   	0b00010
#define ADC3                   	0b00011
#define ADC4                   	0b00100
#define ADC5                   	0b00101
#define ADC6                   	0b00110
#define ADC7                   	0b00111
#define ADC0_ADC0_10X          	0b01000
#define ADC1_ADC0_10X          	0b01001
#define ADC0_ADC0_200X         	0b01010
#define ADC1_ADC0_200X         	0b01011
#define ADC2_ADC2_10X          	0b01100
#define ADC3_ADC2_10X          	0b01101
#define ADC2_ADC2_200X         	0b01110
#define ADC3_ADC2_200X         	0b01111
#define ADC0_ADC1_1X           	0b10000
#define ADC1_ADC1_1X           	0b10001
#define ADC2_ADC1_1X           	0b10010
#define ADC3_ADC1_1X           	0b10011
#define ADC4_ADC1_1X           	0b10100
#define ADC5_ADC1_1X           	0b10101
#define ADC6_ADC1_1X           	0b10110
#define ADC7_ADC1_1X           	0b10111
#define ADC0_ADC2_1X           	0b11000
#define ADC1_ADC2_1X           	0b11001
#define ADC2_ADC2_1X           	0b11010
#define ADC3_ADC2_1X           	0b11011
#define ADC4_ADC2_1X           	0b11100
#define ADC5_ADC2_1X           	0b11101
#define ADC_1_22_V_VBG          0b11110
#define ADC_0_V_GND	            0b11111

/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: M_ADC_VoidInit         																	                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: 														  									                      *
**************************************************************************************************************************************/
 void MADC_VoidInit();
 /**************************************************************************************************************************************
* Function Name		: M_ADC_VoidInit         																	                      *
* Parameters (in)	: uint8 Copy_uint8ChannelNumber																                      *
* Parameters (out)	: None																						                      *
* Return value		: uint16 ADC_L_H																						          *
* Description		: Function to Start Conversion and return ADC Data Reg.		     							                      *
**************************************************************************************************************************************/
 uint16 MADC_uint16StartConversionSync(uint8 Copy_uint8ChannelNumber);
/**************************************************************************************************************************************
* Function Name		: MADC_uint8StartConversionSync         														                  *
* Parameters (in)	: uint8 Copy_uint8ChannelNumber																                      *
* Parameters (out)	: None																						                      *
* Return value		: uint16 ADC_L_H																						          *
* Description		: Function to Start Conversion and return ADC High Data Reg.		     					                      *
**************************************************************************************************************************************/
 uint8 MADC_uint8StartConversionSync(uint8 Copy_uint8ChannelNumber);
 /**************************************************************************************************************************************
* Function Name		: MADC_uint8StartConversionSync         														                  *
* Parameters (in)	: uint8 Copy_uint8ChannelNumber																                      *
* Parameters (out)	: None																						                      *
* Return value		: uint16 ADC_L_H																						          *
* Description		: Function to Start Conversion and return ADC High Data Reg.		     					                      *
**************************************************************************************************************************************/
 void MADC_voidStartConversionAsync(uint8 Copy_u8ChannelNumber);
 /**************************************************************************************************************************************
* Function Name		: MADC_voidSetCallback         														                              *
* Parameters (in)	: void (*Copy_pvNotificationFunction)(void)																          *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Start Conversion and return ADC High Data Reg.		     					                      *
**************************************************************************************************************************************/
void MADC_voidSetCallback(void (*Copy_pvNotificationFunction)(void));
/**************************************************************************************************************************************
* Function Name		: MAP							         														                  *
* Parameters (in)	: sint16 Copy_sint16InputMin, sint16 Copy_sint16InputMax, sint16 Copy_sint16OutputMin, 							  *
					  sint16 Copy_sint16OutputMax, sint16 Copy_sint16InputValue							                              *
* Parameters (out)	: None																						                      *
* Return value		: uint16 ADC_L_H																						          *
* Description		: Function to get the oppisite value on a linear graph.		 		    					                      *
**************************************************************************************************************************************/
sint16 MAP(sint16 Copy_sint16InputMin, sint16 Copy_sint16InputMax, sint16 Copy_sint16OutputMin, sint16 Copy_sint16OutputMax, sint16 Copy_sint16InputValue);

#endif /*ADC_INTERFACE_H*/