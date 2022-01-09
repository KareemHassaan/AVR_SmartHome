/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						26 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: ADC Driver                                                        							                      *
* ! File Name	: ADC_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of ADC functions        							                      *
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
#include"ADC_intrface.h"  
#include"ADC_private.h"
#include"ADC_config.h"

/***************************************************** Global Variables **************************************************************/
/*Global Pointer To Function*/
static void (*Global_pvCallbackFunction)(void) = NULL;
/*Global Variable To Store The Data*/
uint16 Global_u16DigitalValue = 0;

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: M_ADC_VoidInit         																	                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Init All the configirations of the ADC.		     							                      *
**************************************************************************************************************************************/
 void MADC_VoidInit()
 {
	/*Checking If The ADC Is Enabled Or Disabled*/
	 #if ADC_ENABLE == ENABLE
	
		/*Checking The Reference Selection Voltage*/
		 #if ADC_REF_SELECTION == AREF
		
			 CLR_BIT(ADCMUX,ADCMUX_REFS0);
			 CLR_BIT(ADCMUX,ADCMUX_REFS1);
		
		 #elif ADC_REF_SELECTION == AVCC
		
			 SET_BIT(ADCMUX,ADCMUX_REFS0);
			 CLR_BIT(ADCMUX,ADCMUX_REFS1);
		
		 #elif ADC_REF_SELECTION == INTERNAL_2_56_VOLT
			
			 SET_BIT(ADCMUX,ADCMUX_REFS0);
			 SET_BIT(ADCMUX,ADCMUX_REFS1);
		
		 #else
		
			/*Generating an error that ADC_REF_SELECTION Configiration Error*/
			 #error"ADC_REF_SELECTION Configiration Error"
			
		 #endif
		
		/*Setting the Prescaller Value by the Bit Masking*/
		 SET_SPECIFIC_REG_BITS_VALUE(ADCSRA,PRESCALER_MASK,ADC_PRESCALER_VALUE);
		 
		/*Setting the Trigger Source Value by the Bit Masking*/
		 SET_SPECIFIC_REG_BITS_VALUE(SFIOR,TRIGGER_SOURCE_MASK,ADC_TRIGGER_SOURCE);
	
		/*Enable the ADC*/
		 SET_BIT(ADCSRA,ADCSRA_ADEN);
		
	 #elif ADC_ENABLE == DISABLE
	
		/*Disable the ADC*/
		 SET_BIT(ADCSRA,ADCSRA_ADEN);
		
	 #else
		
		/*Generating an error that ADC_ENABLE Configiration Error*/
		 #error"ADC_ENABLE Configiration Error"
		
	 #endif
	
 }

/**************************************************************************************************************************************
* Function Name		: MADC_uint16StartConversionSync         													                      *
* Parameters (in)	: uint8 Copy_uint8ChannelNumber																                      *
* Parameters (out)	: None																						                      *
* Return value		: uint16 ADC_L_H																						          *
* Description		: Function to Start Conversion and return ADC Data Reg.		     							                      *
**************************************************************************************************************************************/
 uint16 MADC_uint16StartConversionSync(uint8 Copy_uint8ChannelNumber)
 {
	/*Setting the Conversion Channel*/
	 SET_SPECIFIC_REG_BITS_VALUE(ADCMUX,CHANNEL_MASK,Copy_uint8ChannelNumber);
	 
	/*Start The Conversion*/
     SET_BIT(ADCSRA, ADCSRA_ADSC);
    /*Polling Conversion The Flag*/
     while(GET_BIT(ADCSRA, ADCSRA_ADIF) == FLAG_NOT_FIRED);
    /*Clear The Flag*/
     SET_BIT(ADCSRA, ADCSRA_ADIF);
    /*Return The Digital Data*/
     return ADC_L_H;
 }

/**************************************************************************************************************************************
* Function Name		: MADC_uint8StartConversionSync         														                  *
* Parameters (in)	: uint8 Copy_uint8ChannelNumber																                      *
* Parameters (out)	: None																						                      *
* Return value		: uint16 ADC_L_H																						          *
* Description		: Function to Start Conversion and return ADC High Data Reg.		     					                      *
**************************************************************************************************************************************/
 uint8 MADC_uint8StartConversionSync(uint8 Copy_uint8ChannelNumber)
 {
	/*Setting the Conversion Channel*/
	 SET_SPECIFIC_REG_BITS_VALUE(ADCMUX,CHANNEL_MASK,Copy_uint8ChannelNumber);
	/*Select The Left Adjust*/
	 SET_BIT(ADCMUX, ADCMUX_ADLAR);
	 
	/*Start The Conversion*/
     SET_BIT(ADCSRA, ADCSRA_ADSC);
    /*Polling Conversion The Flag*/
     while(GET_BIT(ADCSRA, ADCSRA_ADIF) == FLAG_NOT_FIRED);
    /*Clear The Flag*/
     SET_BIT(ADCSRA, ADCSRA_ADIF);
    /*Return The Digital Data*/
     return ADCH;
 }

/**************************************************************************************************************************************
* Function Name		: MADC_uint8StartConversionSync         														                  *
* Parameters (in)	: uint8 Copy_uint8ChannelNumber																                      *
* Parameters (out)	: None																						                      *
* Return value		: uint16 ADC_L_H																						          *
* Description		: Function to Start Conversion and return ADC High Data Reg.		     					                      *
**************************************************************************************************************************************/
 void MADC_voidStartConversionAsync(uint8 Copy_uint8ChannelNumber)
 {
	/*Setting the Conversion Channel*/
	 SET_SPECIFIC_REG_BITS_VALUE(ADCMUX,CHANNEL_MASK,Copy_uint8ChannelNumber);
	 
	/*Start The Conversion*/
     SET_BIT(ADCSRA, ADCSRA_ADSC);
    /*Enable The ADC Interrupt*/
    SET_BIT(ADCSRA, ADCSRA_ADIE);
  
 }

/**************************************************************************************************************************************
* Function Name		: MADC_voidSetCallback         														                              *
* Parameters (in)	: void (*Copy_pvNotificationFunction)(void)																          *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Start Conversion and return ADC High Data Reg.		     					                      *
**************************************************************************************************************************************/
void MADC_voidSetCallback(void (*Copy_pvNotificationFunction)(void))
{
    Global_pvCallbackFunction = Copy_pvNotificationFunction;
}

/**************************************************************************************************************************************
* Function Name		: ISR For ADC Peripheral        														                          *
* Parameters (in)	: None																                                              *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Call the Nedded function by its pointer.		     					                                          *
**************************************************************************************************************************************/
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
    if(Global_pvCallbackFunction != NULL)
    {   
        /*Get Data And Store It In A Global Varibale*/
        Global_u16DigitalValue = ADC_L_H;
        /*Call The Callback Function*/
        Global_pvCallbackFunction();
        /*Disable The Interrupt*/
        CLR_BIT(ADCSRA, ADCSRA_ADIE);
    }
    else
    {
        /*Do Nothing*/
    }
}

/**************************************************************************************************************************************
* Function Name		: MAP							         														                  *
* Parameters (in)	: sint16 Copy_sint16InputMin, sint16 Copy_sint16InputMax, sint16 Copy_sint16OutputMin, 							  *
					  sint16 Copy_sint16OutputMax, sint16 Copy_sint16InputValue							                              *
* Parameters (out)	: None																						                      *
* Return value		: uint16 ADC_L_H																						          *
* Description		: Function to get the oppisite value on a linear graph.		 		    					                      *
**************************************************************************************************************************************/
sint16 MAP(sint16 Copy_sint16InputMin, sint16 Copy_sint16InputMax, sint16 Copy_sint16OutputMin, sint16 Copy_sint16OutputMax, sint16 Copy_sint16InputValue)
 {
	/*Local variable to Store in it the return value*/
	 sint16 Local_sint16ReturnX;
	/*Calculating the slope of the Linear graph*/
     sint16 Slope = (Copy_sint16InputMax-Copy_sint16InputMin)/(Copy_sint16OutputMax-Copy_sint16OutputMin);
	/*Getting the Entered Value in the variable Y*/
     sint16 Y = Copy_sint16InputValue;
	/*Define a variable to store the opposite value on the line*/ 
     sint16 X = 0;

	/*Calculating the wanted oppisite value on the line*/
     X = ((Y - Copy_sint16InputMin)/Slope)+Copy_sint16OutputMin;
	 
	/*Check if the Entered value Smaller than the minimum*/
     if(Copy_sint16InputValue < Copy_sint16InputMin)
     {
		/*Return the MIN value*/
    	 Local_sint16ReturnX = Copy_sint16OutputMin;
     }
	 /*Check if the Entered value Bigger than the maximum*/
     else if(Copy_sint16InputValue > Copy_sint16InputMax)
     {
		/*Return the MAX value*/
    	 Local_sint16ReturnX = Copy_sint16OutputMax;
     }
     else
     {
		/*Return the Calculated value*/
    	 Local_sint16ReturnX = X;
     }

	 
    return Local_sint16ReturnX;
 }