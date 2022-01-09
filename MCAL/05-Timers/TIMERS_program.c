/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						28 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: TIMERS Driver                                                        							                      *
* ! File Name	: TIMERS_program.c                                                       							                  *
* ! Description : This file has the implementation of Basic of TIMERS functions        							                      *
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
#include"TIMERS_intrface.h"  
#include"TIMERS_private.h"
#include"TIMERS_config.h"

/***************************************************** Global Variables **************************************************************/

static void (*Global_pvTimer0CallBack[TIMER0_ISR_NUM])(void);					  	// Timer 0 Array of Pointers to ISR Function 
static void (*Global_pvTimer1CallBack[TIMER1_ISR_NUM])(void);					  	// Timer 1 Array of Pointers to ISR Function 
static void (*Global_pvTimer2CallBack[TIMER2_ISR_NUM])(void);					  	// Timer 2 Array of Pointers to ISR Function 

/***********************************************************************************************************************************************/
/***************************************************** Timer0 Functions Definition *************************************************************/
/***********************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: MTIMERS_VoidTimer0Init 																	                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialize All Timer0	Configrations.		     								                      *
**************************************************************************************************************************************/
void MTIMERS_VoidTimer0Init()
{	/*Checking if Timer0 is Enabled or Disabled*/
	 #if TIMER0_ENABLE == ENABLE
		
		/*Checking if Timer0 Mode is NORMAL_MODE*/
		 #if TIMER0_MODE == NORMAL_MODE
			
			/*Set Timer0 mode to NORMAL_MODE*/
			 CLR_BIT(TCCR0,TCCR0_WGM01);
			 CLR_BIT(TCCR0,TCCR0_WGM00);
		
		/*Checking if Timer0 Mode is PWM_PHASE_CORRECT_MODE*/
		 #elif TIMER0_MODE == PWM_PHASE_CORRECT_MODE
			
			/*Set Timer0 mode to PWM_PHASE_CORRECT_MODE*/
			 CLR_BIT(TCCR0,TCCR0_WGM01);
			 SET_BIT(TCCR0,TCCR0_WGM00);
			/*Checking and Set PWM Mode*/
			 SET_SPECIFIC_REG_BITS_VALUE(TCCR0,TIMER0_CTC_PWM_MODES_MASK,TIMER0_CTC_PWM_MODES_VALUE);
		
		/*Checking if Timer0 Mode is CTC_MODE*/		
		 #elif TIMER0_MODE == CTC_MODE
		
			/*Set Timer0 mode to CTC_MODE*/
			 SET_BIT(TCCR0,TCCR0_WGM01);
			 CLR_BIT(TCCR0,TCCR0_WGM00);
			/*Checking and Set CTC Mode*/
			 SET_SPECIFIC_REG_BITS_VALUE(TCCR0,TIMER0_CTC_PWM_MODES_MASK,TIMER0_CTC_PWM_MODES_VALUE);
		
		/*Checking if Timer0 Mode is FAST_PWM_MODE*/
		 #elif TIMER0_MODE == FAST_PWM_MODE
		
			/*Set Timer0 mode to FAST_PWM_MODE*/
			SET_BIT(TCCR0,TCCR0_WGM01);
			SET_BIT(TCCR0,TCCR0_WGM00);
			/*Checking and Set PWM Mode*/
			SET_SPECIFIC_REG_BITS_VALUE(TCCR0,TIMER0_CTC_PWM_MODES_MASK,TIMER0_CTC_PWM_MODES_VALUE);
			
		 #else
		
			/*Printing a message that TIMER0_MODE Configration Error*/
			 #error"TIMER0_MODE Configration Error"
		
		 #endif
		
		/*Checking if Timer0 Normal Mode interrupt is Enabled or not*/
		 #if (TIMER0_INT_ENABLE == ENABLE)&&(TIMER0_MODE == NORMAL_MODE)
			
			/*Enable the Normal Mode interrupt*/
			 SET_BIT(TIMSK,TIMSK_TOIE0);
		
		/*Checking if Timer0 Other Modes interrupt is Enabled or not*/
		 #elif TIMER0_INT_ENABLE == ENABLE
			
			/*Enable the Other Mode interrupt*/
			 SET_BIT(TIMSK,TIMSK_OCIE0);
		
		/*Checking if Timer0 interrupt is Disabled or not*/
		 #elif TIMER0_INT_ENABLE == DISABLE
			
			/*Disable all Timer0 Interrupts*/
			 CLR_BIT(TIMSK,TIMSK_TOIE0);
			 CLR_BIT(TIMSK,TIMSK_OCIE0);
		 #else
			
			/*Printing a message that TIMER0_INT_ENABLE Configration Error*/
			 #error"TIMER0_INT_ENABLE Configration Error"
			
		 #endif
		
		/*Setting Timer0 Prescaller Value*/
		 SET_SPECIFIC_REG_BITS_VALUE(TCCR0,TIMER0_PRESCALLER_MASK,TIMER0_PRESCALLER_VALUE);
	
	 #elif TIMER0_ENABLE == DISABLE
	
		/*Disable Timer0 By Making No Clock coming*/
		 SET_SPECIFIC_REG_BITS_VALUE(TCCR0,TIMER0_PRESCALLER_MASK,T0_NO_CLOCK_SOURCE);
	
	 #else
		/*Printing a message that TIMER0_INT_ENABLE Configration Error*/
		 #error"TIMER0_INT_ENABLE Configration Error"
		
	 #endif
}

/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer0SetPreloadValue 																	          *
* Parameters (in)	: Copy_uint8PreloadValue																						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Preload Value to Start Count From it. 					  					              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer0SetPreloadValue(uint8 Copy_uint8PreloadValue)
{
	/*Set The Preload Value In The Timer0 Register*/
	TCNT0 = Copy_uint8PreloadValue;
}

/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer0SetCompareMatchValue 																	      *
* Parameters (in)	: Copy_u8CompareMatchValue																						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Compare Valve to match with it. 					  					                      *
**************************************************************************************************************************************/
void MTIMERS_voidTimer0SetCompareMatchValue(uint8 Copy_u8CompareMatchValue)
{
	/*Set The Compare Match Value In The OCR0 Register*/
	OCR0 = Copy_u8CompareMatchValue;
}

/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidSetBusyWait 																	                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set Busy time as a Delay. 					  					       				              *
**************************************************************************************************************************************/
void MTIMERS_voidSetBusyWait(uint32 Copy_u32MilliSeconds)
{
	/*
		Prescaler = 8;
		OCR0 = 250
		Compare Match Time = 250 * 8/8MHz = 250usec
	*/
	/* Make Sure The Prescaler Is = 8
	   Set The OCR0 (Compare Match Value) = 250
	   Make Sure The Flag Is Cleared
	*/
	/*Make Sure The Prescaler Is = 8*/
	 SET_SPECIFIC_REG_BITS_VALUE(TCCR0,TIMER0_PRESCALLER_MASK,T0_DIVIDE_BY_8);

	/*Set the Compare Value*/
	 OCR0 = 250;

	/*Make Sure The OVF Flag Is Cleared*/
	 SET_BIT(TIFR, TIFR_OCF0);

	uint32 Local_u32TickCounter = 0;

	/*Count the Required Time To Be Busy wait*/
	 while(Local_u32TickCounter < (Copy_u32MilliSeconds*4))
	 {
		/*Check if The Flag Is Raised Up Or Not*/
		 if(GET_BIT(TIFR, TIFR_OCF0) == 1)
		 {
			/*Increment The Counter*/
			 Local_u32TickCounter++;
			/*Clear The Flag*/
			 SET_BIT(TIFR, TIFR_OCF0);
		 }
	 }
}


/***********************************************************************************************************************************************/
/***************************************************** Timer1 Functions Definition *************************************************************/
/***********************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: MTIMERS_VoidTimer1Init 																	                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialize All Timer1	Configrations.		     								                      *
**************************************************************************************************************************************/
void MTIMERS_VoidTimer1Init()
{
	/*Checking if Timer 1 is Enabled or not*/
	 #if TIMER1_ENABLE == ENABLE
		/*Checking if Channel A is Enabled or not*/
		 #if TIMER1_Channel_A_ENABLE == ENABLE

			/*Setting Channel A Mode*/
			 SET_SPECIFIC_REG_BITS_VALUE(TCCR1A,TIMER1_TCCR1A_MODE_MASK,TIMER1_TCCR1A_MODE);
			 SET_SPECIFIC_REG_BITS_VALUE(TCCR1B,TIMER1_TCCR1B_MODE_MASK,TIMER1_TCCR1B_MODE);

			/*Setting Channel A PWM & CTC Mode*/
			 SET_SPECIFIC_REG_BITS_VALUE(TCCR1A,TIMER1_Channel_A_CTC_PWM_MODES_MASK,TIMER1_Channel_A_CTC_PWM_MODES_VALUE);

		 #elif TIMER1_Channel_A_ENABLE == DISABLED

		 #else

			/*Printing a message that TIMER1_Channel_A_ENABLE Configration Error*/
			 #error"TIMER1_Channel_A_ENABLE Configration Error"

		 #endif

		 
		/*Checking if Channel B is Enabled or not*/
		 #if TIMER1_Channel_B_ENABLE == ENABLE

			/*Setting Channel B Mode*/
			 SET_SPECIFIC_REG_BITS_VALUE(TCCR1A,TIMER1_TCCR1A_MODE_MASK,TIMER1_TCCR1A_MODE);
			 SET_SPECIFIC_REG_BITS_VALUE(TCCR1B,TIMER1_TCCR1B_MODE_MASK,TIMER1_TCCR1B_MODE);
	
			/*Setting Channel B PWM & CTC Mode*/
			 SET_SPECIFIC_REG_BITS_VALUE(TCCR1A,TIMER1_Channel_B_CTC_PWM_MODES_MASK,TIMER1_Channel_B_CTC_PWM_MODES_VALUE);

		 #elif TIMER1_Channel_B_ENABLE == DISABLED

		 #else

			/*Printing a message that TIMER1_Channel_B_ENABLE Configration Error*/
			 #error"TIMER1_Channel_B_ENABLE Configration Error"

		 #endif


		/*Checking If ICU Interrupt is Enabled or Not*/
		 #if (TIMER1_ICU_INT_ENABLE == ENABLE)
			 
			/*Enable ICU Interrupt*/
			 SET_BIT(TIMSK,TIMSK_TICIE1);
			
		 #elif (TIMER1_ICU_INT_ENABLE == DISABLE)

			/*Disable ICU Interrupt*/
			 CLR_BIT(TIMSK,TIMSK_TICIE1);
		 #else

			/*Printing a message that TIMER1_ICU_INT_ENABLE Configration Error*/
			 #error"TIMER1_ICU_INT_ENABLE Configration Error"

		 #endif


		 /*Checking If Over Flow Interrupt Channel A is Enabled or Not*/
		 #if (TIMER1_Channel_A_INT_ENABLE == ENABLE)&&(TIMER1_TCCR1A_MODE == TCCR1A_NORMAL_0XFFFF_IMMEDIATE_MAX)

			/*Enable Over Flow Interrupt*/
			 SET_BIT(TIMSK,TIMSK_TOIE1);

		/*Checking If Other Modes Interrupt Channel A is Enabled or Not*/
		 #elif TIMER1_Channel_A_INT_ENABLE == ENABLE

			/*Enable Other Modes Interrupt*/
			 SET_BIT(TIMSK,TIMSK_OCIE1A);

		 #elif TIMER1_Channel_A_INT_ENABLE == DISABLE

			/*Disable All Interrupts*/
			CLR_BIT(TIMSK,TIMSK_TOIE1);
			CLR_BIT(TIMSK,TIMSK_OCIE1A);
		 #else

			/*Printing a message that TIMER1_Channel_A_INT_ENABLE Configration Error*/
			 #error"TIMER1_Channel_A_INT_ENABLE Configration Error"

		 #endif


		/*Checking If Over Flow Interrupt Channel B is Enabled or Not*/
		 #if (TIMER1_Channel_B_INT_ENABLE == ENABLE)&&(TIMER1_TCCR1A_MODE == TCCR1A_NORMAL_0XFFFF_IMMEDIATE_MAX)
         
		 	/*Enable Over Flow Interrupt*/
		 	 SET_BIT(TIMSK,TIMSK_TOIE1);
         
		 /*Checking If Other Modes Interrupt Channel B is Enabled or Not*/
		 #elif TIMER1_Channel_B_INT_ENABLE == ENABLE
         
		 	/*Enable Other Modes Interrupt*/
		 	 SET_BIT(TIMSK,TIMSK_OCIE1A);
         
		 #elif TIMER1_Channel_B_INT_ENABLE == DISABLE
         
		 	/*Disable All Interrupts*/
		 	 CLR_BIT(TIMSK,TIMSK_TOIE1);
		 	 CLR_BIT(TIMSK,TIMSK_OCIE1B);
		 #else
         
		 	/*Printing a message that TIMER1_Channel_B_INT_ENABLE Configration Error*/
		 	 #error"TIMER1_Channel_B_INT_ENABLE Configration Error"
         
		 #endif

		/*Setting Timer 1 Prescaller*/
		 SET_SPECIFIC_REG_BITS_VALUE(TCCR1B,TIMER1_PRESCALLER_MASK,TIMER1_PRESCALLER_VALUE);

	 #elif TIMER1_ENABLE == DISABLE

		/*Setting Timer 1 Prescaller to No CLK Source To Disabel Timer 1*/
		 SET_SPECIFIC_REG_BITS_VALUE(TCCR1B,TIMER1_PRESCALLER_MASK,T1_No_clock_source);

	 #else
	
		/*Printing a message that TIMER1_ENABLE Configration Error*/
		 #error"TIMER1_ENABLE Configration Error"

	 #endif

}

/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer1SetPreloadValue 																	          *
* Parameters (in)	: Copy_uint16PreloadValue																						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Preload Value to Start Count From it. 					  					              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer1SetPreloadValue(uint16 Copy_uint16PreloadValue)
{
	/*Set The Preload Value In The Timer1 Register*/
	TCNT1 = Copy_uint16PreloadValue;
}

/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer1SetTopValue 																	              *
* Parameters (in)	: Copy_uint8PreloadValue																						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Top Valve of the Timer.		 					  					                      *
**************************************************************************************************************************************/
void MTIMERS_voidTimer1SetTopValue(uint16 Copy_uint8PreloadValue)
{
	/*Set The Top Value In The Timer1 Register*/
	ICR1 = Copy_uint8PreloadValue;
}

/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer1SetChannelACompareMatchValue 																  *
* Parameters (in)	: Copy_uint16CompareMatchValue																					  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Channel A  Compare Valve to match with it.        					  		              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer1SetChannelACompareMatchValue(uint16 Copy_uint16CompareMatchValue)
{
	/*Set The Compare Match Channel A Value In The OCR0 Register*/
	OCR1A = Copy_uint16CompareMatchValue;
}

/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer1SetChannelBCompareMatchValue 																  *
* Parameters (in)	: Copy_uint16CompareMatchValue																					  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Channel B Compare Valve to match with it.       			  					              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer1SetChannelBCompareMatchValue(uint16 Copy_uint16CompareMatchValue)
{
	/*Set The Compare Match Channel B Value In The OCR0 Register*/
	OCR1B = Copy_uint16CompareMatchValue;
}

/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer1ICUSetSenseSignal			 																  *
* Parameters (in)	: Copy_uint16CompareMatchValue																					  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set Sense Signal to ICU.       			  											              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer1ICUSetSenseSignal(uint16 Copy_uint8SignalValue)
{
	switch(Copy_uint8SignalValue)
	{
		case FALLING_EDGE:
		
			/*Setting The /input Capture Unit To Sense On The Falling Edge */
			CLR_BIT(TCCR1B, TCCR1B_ICES1);
		break;
		case RISING_EDGE:
		
			/*Setting The /input Capture Unit To Sense On The Rising Edge */
			SET_BIT(TCCR1B, TCCR1B_ICES1);
		break;
	}
}

/**************************************************************************************************************************************
* Function Name		: MTIMERS_uint16Timer1GetICR1Value				 																  *
* Parameters (in)	: Copy_uint16CompareMatchValue																					  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Get ICR1.											       			  					              *
**************************************************************************************************************************************/
uint16 MTIMERS_uint16Timer1GetICR1Value()
{
	/*Return The Input Capture Unit Sense Value*/
	return ICR1;
}

/**************************************************************************************************************************************
* Function Name		: MTIMERS_uint16Timer1GICUInterruptControl				 														  *
* Parameters (in)	: Copy_uint16CompareMatchValue																					  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Get ICR1.											       			  					              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer1GICUInterruptControl(uint8 Copy_uint8InterruptState)
{
	switch(Copy_uint8InterruptState)
	{
		case ENABLE:
			
			/*Enable ICU Interrupt*/
			SET_BIT(TIMSK, TIMSK_TICIE1);
		break;
		case DISABLE:
			
			/*Disable ICU Interrupt*/
			CLR_BIT(TIMSK, TIMSK_TICIE1);
		break;
	}
}


/***********************************************************************************************************************************************/
/***************************************************** Timer2 Functions Definition *************************************************************/
/***********************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: MTIMERS_VoidTimer2Init 																	                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialize All Timer2	Configrations.		     								                      *
**************************************************************************************************************************************/
void MTIMERS_VoidTimer2Init()
{
	/*Checking if Timer2 is Enabled or Disabled*/
	 #if TIMER2_ENABLE == ENABLE
		
		/*Checking if Timer2 Mode is NORMAL_MODE*/
		 #if TIMER2_MODE == NORMAL_MODE
		
			/*Set Timer2 mode to NORMAL_MODE*/
			 CLR_BIT(TCCR2,TCCR2_WGM21);
			 CLR_BIT(TCCR2,TCCR2_WGM20);
	
		/*Checking if Timer2 Mode is PWM_PHASE_CORRECT_MODE*/
		 #elif TIMER2_MODE == PWM_PHASE_CORRECT_MODE
			
			/*Set Timer2 mode to PWM_PHASE_CORRECT_MODE*/
			 CLR_BIT(TCCR2,TCCR2_WGM21);
			 SET_BIT(TCCR2,TCCR2_WGM20);
			/*Checking and Set PWM Mode*/
			 SET_SPECIFIC_REG_BITS_VALUE(TCCR2,TIMER2_CTC_PWM_MODES_MASK,TIMER2_CTC_PWM_MODES_VALUE);
		
		/*Checking if Timer2 Mode is CTC_MODE*/			
		 #elif TIMER2_MODE == CTC_MODE
		
			/*Set Timer2 mode to CTC_MODE*/
			 SET_BIT(TCCR2,TCCR2_WGM21);
			 CLR_BIT(TCCR2,TCCR2_WGM20);
			/*Checking and Set CTC Mode*/
			 SET_SPECIFIC_REG_BITS_VALUE(TCCR2,TIMER2_CTC_PWM_MODES_MASK,TIMER2_CTC_PWM_MODES_VALUE);
		
		/*Checking if Timer2 Mode is FAST_PWM_MODE*/
		 #elif TIMER2_MODE == FAST_PWM_MODE
		
			/*Set Timer2 mode to FAST_PWM_MODE*/
			 SET_BIT(TCCR2,TCCR2_WGM21);
			 SET_BIT(TCCR2,TCCR2_WGM20);
			/*Checking and Set PWM Mode*/
			 SET_SPECIFIC_REG_BITS_VALUE(TCCR2,TIMER2_CTC_PWM_MODES_MASK,TIMER2_CTC_PWM_MODES_VALUE);
			
		 #else
		
			/*Printing a message that TIMER2_MODE Configration Error*/
			 #error"TIMER2_MODE Configration Error"
		
		 #endif
		
		
		/*Checking if Timer2 Normal Mode interrupt is Enabled or not*/
		 #if (TIMER2_INT_ENABLE == ENABLE)&&(TIMER0_MODE == NORMAL_MODE)
			
			/*Enable the Normal Mode interrupt*/
			 SET_BIT(TIMSK,TIMSK_TOIE2);
		
		/*Checking if Timer2 Other Modes interrupt is Enabled or not*/
		 #elif TIMER2_INT_ENABLE == ENABLE
		
			/*Enable the Other Mode interrupt*/
			 SET_BIT(TIMSK,TIMSK_OCIE2);
		
		 #elif TIMER2_INT_ENABLE == DISABLE
			
			/*Disable all Timer2 Interrupts*/
			 CLR_BIT(TIMSK,TIMSK_TOIE2);
			 CLR_BIT(TIMSK,TIMSK_OCIE2);
		 #else
			
			/*Printing a message that TIMER2_INT_ENABLE Configration Error*/
			 #error"TIMER2_INT_ENABLE Configration Error"
			
		 #endif
		
		
		/*Setting Timer2 Prescaller Value*/
		 SET_SPECIFIC_REG_BITS_VALUE(TCCR2,TIMER2_PRESCALLER_MASK,TIMER2_PRESCALLER_VALUE);
	
	 #elif TIMER2_ENABLE == DISABLE
	
		/*Disable Timer2 By Making No Clock coming*/
		 SET_SPECIFIC_REG_BITS_VALUE(TCCR2,TIMER2_PRESCALLER_MASK,T2_No_clock_source);
	
	 #else
		
		/*Printing a message that TIMER2_ENABLE Configration Error*/
		 #error"TIMER2_ENABLE Configration Error"
		
	 #endif
}

/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer2SetPreloadValue 																	          *
* Parameters (in)	: Copy_uint8PreloadValue																						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Preload Value to Start Count From it. 					  					              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer2SetPreloadValue(uint8 Copy_uint8PreloadValue)
{
	/*Set The Preload Value In The Timer2 Register*/
	TCNT2 = Copy_uint8PreloadValue;
}

/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidTimer2SetCompareMatchValue 																	      *
* Parameters (in)	: Copy_u8CompareMatchValue																						  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set the Compare Valve to match with it.       					  					              *
**************************************************************************************************************************************/
void MTIMERS_voidTimer2SetCompareMatchValue(uint8 Copy_u8CompareMatchValue)
{
	/*Set The Compare Match Value In The OCR2 Register*/
	OCR2 = Copy_u8CompareMatchValue;
}


/***********************************************************************************************************************************************/
/***************************************************** Set_CBK Function Prototypes *************************************************************/
/***********************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: MTIMERS_voidSetCallBack 																	                      *
* Parameters (in)	: uint8 Copy_uint8TimerNum, uint8 Copy_uint8TimerISRType, void (*Copy_pvCallbackFunction)(void))				  *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Set Function to the ISR of the Timer          					  					              *
**************************************************************************************************************************************/
void MTIMERS_voidSetCallBack(uint8 Copy_uint8TimerNum, uint8 Copy_uint8TimerISRType, void (*Copy_pvCallbackFunction)(void))
{
	/*Switching the Timer Number*/
	 switch(Copy_uint8TimerNum)
	 {
		case TIMER0:
		
				/*Switching the Timer ISR Type*/
				 switch(Copy_uint8TimerISRType)
				 {
					case OVERFLOW:
					
							/*Setting the Timer0 OVERFLOW ISR Function*/
							 Global_pvTimer0CallBack[OVERFLOW] = Copy_pvCallbackFunction;
					break;
					case CTC:
					
							/*Setting the Timer0 CTC ISR Function*/
							 Global_pvTimer0CallBack[CTC] = Copy_pvCallbackFunction;
					break;
				 }
		break;
		
		case TIMER1:
		
				/*Switching the Timer ISR Type*/
				 switch(Copy_uint8TimerISRType)
				 {
					case OVERFLOW:
					
							/*Setting the Timer1 OVERFLOW ISR Function*/
							 Global_pvTimer1CallBack[OVERFLOW] = Copy_pvCallbackFunction;
					break;
					case CTC_CH_A:
						
							/*Setting the Timer1 Channel A CTC ISR Function*/
							 Global_pvTimer1CallBack[CTC_CH_A] = Copy_pvCallbackFunction;
					break;
					case CTC_CH_B:
					
							/*Setting the Timer1 Channel B CTC ISR Function*/
							 Global_pvTimer1CallBack[CTC_CH_B] = Copy_pvCallbackFunction;
					break;
					case ICU:
					
							/*Setting the Timer1 ICU ISR Function*/
							 Global_pvTimer1CallBack[ICU] = Copy_pvCallbackFunction;
					break;
				 }
		break;
		
		case TIMER2:
		
				/*Switching the Timer ISR Type*/
				 switch(Copy_uint8TimerISRType)
				 {
					case OVERFLOW:
					
							/*Setting the Timer2 OVERFLOW ISR Function*/
							 Global_pvTimer2CallBack[OVERFLOW] = Copy_pvCallbackFunction;
					break;
					case CTC:
					
							/*Setting the Timer2 CTC ISR Function*/
							 Global_pvTimer2CallBack[CTC] = Copy_pvCallbackFunction;
					break;
				 }
		break;
	}
}



/*************************************************************************************************************************************/
/******************************************************** TIMER0 OVF ISR *************************************************************/
/*************************************************************************************************************************************/
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	/*Check If The Global Pointer To Function has its Initial Value or not*/
	if(Global_pvTimer0CallBack[OVERFLOW] != NULL)
	{
		/*Invoke The Callback Function*/
		Global_pvTimer0CallBack[OVERFLOW]();
	}
	else
	{
		/*Do Nothing*/
	}
}

/*************************************************************************************************************************************/
/******************************************************** TIMER0 CTC ISR *************************************************************/
/*************************************************************************************************************************************/
/*ISR For Timer 0 CTC*/
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	/*Check If The Global Pointer To Function has its Initial Value or not*/
	if(Global_pvTimer0CallBack[CTC] != NULL)
	{
		/*Invoke The Callback Function*/
		Global_pvTimer0CallBack[CTC]();
	}
	else
	{
		/*Do Nothing*/
	}
}

/*************************************************************************************************************************************/
/******************************************************** TIMER1 OVF ISR *************************************************************/
/*************************************************************************************************************************************/
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	/*Check If The Global Pointer To Function has its Initial Value or not*/
	if(Global_pvTimer1CallBack[OVERFLOW] != NULL)
	{
		/*Invoke The Callback Function*/
		Global_pvTimer1CallBack[OVERFLOW]();
	}
	else
	{
		/*Do Nothing*/
	}
}

/*************************************************************************************************************************************/
/*************************************************** TIMER1 CTC CHANNEL A ISR ********************************************************/
/*************************************************************************************************************************************/
/*ISR For Timer 0 CTC*/
void __vector_8 (void) __attribute__((signal));
void __vector_8 (void)
{
	/*Check If The Global Pointer To Function has its Initial Value or not*/
	if(Global_pvTimer1CallBack[CTC_CH_A] != NULL)
	{
		/*Invoke The Callback Function*/
		Global_pvTimer1CallBack[CTC_CH_A]();
	}
	else
	{
		/*Do Nothing*/
	}
}

/*************************************************************************************************************************************/
/*************************************************** TIMER1 CTC CHANNEL B ISR ********************************************************/
/*************************************************************************************************************************************/
/*ISR For Timer 0 CTC*/
void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{
	/*Check If The Global Pointer To Function has its Initial Value or not*/
	if(Global_pvTimer1CallBack[CTC_CH_B] != NULL)
	{
		/*Invoke The Callback Function*/
		Global_pvTimer1CallBack[CTC_CH_B]();
	}
	else
	{
		/*Do Nothing*/
	}
}

/*************************************************************************************************************************************/
/******************************************************** TIMER1 ICU ISR *************************************************************/
/*************************************************************************************************************************************/
/*ISR For Timer 0 CTC*/
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	/*Check If The Global Pointer To Function has its Initial Value or not*/
	if(Global_pvTimer1CallBack[ICU] != NULL)
	{
		/*Invoke The Callback Function*/
		Global_pvTimer1CallBack[ICU]();
	}
	else
	{
		/*Do Nothing*/
	}
}

/*************************************************************************************************************************************/
/******************************************************** TIMER2 OVF ISR *************************************************************/
/*************************************************************************************************************************************/
void __vector_5 (void) __attribute__((signal));
void __vector_5 (void)
{
	/*Check If The Global Pointer To Function has its Initial Value or not*/
	if(Global_pvTimer2CallBack[OVERFLOW] != NULL)
	{
		/*Invoke The Callback Function*/
		Global_pvTimer2CallBack[OVERFLOW]();
	}
	else
	{
		/*Do Nothing*/
	}
}

/*************************************************************************************************************************************/
/******************************************************** TIMER2 CTC ISR *************************************************************/
/*************************************************************************************************************************************/
/*ISR For Timer 0 CTC*/
void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{
	/*Check If The Global Pointer To Function has its Initial Value or not*/
	if(Global_pvTimer2CallBack[CTC] != NULL)
	{
		/*Invoke The Callback Function*/
		Global_pvTimer2CallBack[CTC]();
	}
	else
	{
		/*Do Nothing*/
	}
}
