/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						03 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: SPI Driver                                                        							                      *
* ! File Name	: SPI_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of SPI functions        							                      *
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
#include"SPI_intrface.h"  
#include"SPI_private.h"
#include"SPI_config.h"

/***************************************************** Global Variables **************************************************************/
uint8 MSPI_uint8ReceiveData;

/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: MSPI_VoidInit																	                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: 														  									                      *
**************************************************************************************************************************************/
void MSPI_VoidMasterInit()
{
	/*Set the node to be master*/
	SET_BIT(SPCR,SPCR_MSTR);
	
	/*Set MSB Firt*/
	CLR_BIT(SPCR,SPCR_DORD);
	
	/*Set Clock Pol ,Leading = Rising Edge and write on it*/
	CLR_BIT(SPCR,SPCR_CPOL);
	SET_BIT(SPCR,SPCR_CPHA);
	
	/*Set Prescaller = 16*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
	
	/*Enable SPI*/
	SET_BIT(SPCR,SPCR_SPE);
}

/**************************************************************************************************************************************
* Function Name		: MSPI_VoidInit																	                      			  *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: 														  									                      *
**************************************************************************************************************************************/
void MSPI_VoidSlaveInit()
{
	/*Set the node to be master*/
	CLR_BIT(SPCR,SPCR_MSTR);
	
	/*Set MSB Firt*/
	CLR_BIT(SPCR,SPCR_DORD);
	
	/*Set Clock Pol ,Leading = Rising Edge and write on it*/
	CLR_BIT(SPCR,SPCR_CPOL);
	SET_BIT(SPCR,SPCR_CPHA);
	
	/*Set Prescaller = 16*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
	
	/*Enable SPI */
	SET_BIT(SPCR,SPCR_SPE);
}

void MSPI_voidTranseiverDataAsynch(uint8 Copy_uint8Data);
{
	SPDR = Copy_uint8Data;
	/*Enable Spi Interrupt*/
	SET_BIT(SPCR,SPCR_SPIE);
}


void __vector_num12 (void) __attribute__((signal));
void __vector_num12 (void)
{
	MSPI_uint8ReceiveData = SPDR;
	
	
	
	if( MSPI_uint8ReceiveData == 10)
	{
		
	}
	else
	{
		
	}
	
	CLR_BIT(SPCR,SPCR_SPIE);
}