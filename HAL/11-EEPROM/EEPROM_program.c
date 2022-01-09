/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						05 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: EEPROM Driver                                                        							                      *
* ! File Name	: EEPROM_program.c                                                     							                      *
* ! Description : This file has the implementation of Basic of EEPROM functions (24C08 EEPROM)  				                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: HAL                  						        	                                 							  *
**************************************************************************************************************************************/

/**************************************************** Library Inclusions *************************************************************/
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
/************************************************** Lower Layer Inclusions ***********************************************************/
#include"../../MCAL/10-TWI/TWI_intrface.h"
/************************************************** Self Layer Inclusions ************************************************************/

/************************************************** Self Files Inclusions ************************************************************/
/*Must be with that order maybe change Private with config only*/
#include"EEPROM_intrface.h"  
#include"EEPROM_private.h"
#include"EEPROM_config.h"

/***************************************************** Global Variables **************************************************************/


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/
/**************************************************************************************************************************************
* Function Name		: HEEPROM_voidWriteData																		                      *
* Parameters (in)	: uint16 Copy_uint16Location, uint8  Copy_uint8Data											                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Write Data in Specific Location in The EEPROM									                      *
**************************************************************************************************************************************/
void HEEPROM_voidWriteData(uint16 Copy_uint16Location, uint8  Copy_uint8Data)
{
	if(Copy_uint16Location <= 1023)
	{
		uint8 Local_uint8AddressPacket = 0;
		Local_uint8AddressPacket = EEPROM_ADDRESS_FIXED | (A2_Connection << 2) | ((uint8)Copy_uint16Location >> 8);
		
		/*Send Start Condition*/
		MTWI_ErrorStatusSendStartCondition();
		/*Send Slave Address With Write Request*/
		MTWI_ErrorStatusSendSlaveAddressWithWrite(Local_uint8AddressPacket);
		/*Send The Rest Of Byte Address*/
		MTWI_ErrorStatusMasterWriteDataByte((uint8)Copy_uint16Location);
		/*Send The Data Byte*/
		MTWI_ErrorStatusMasterWriteDataByte(Copy_uint8Data);
		/*Send Stop Condition*/
		MTWI_voidSendStopCondition();
		_delay_ms(10);
	}	
}

/**************************************************************************************************************************************
* Function Name		: HEEPROM_voidReadData																		                      *
* Parameters (in)	: uint16 Copy_uint16Location, uint8  * Copy_uint8ReceivedData								                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Read Data from Specific Location in The EEPROM		  						                      *
**************************************************************************************************************************************/
void HEEPROM_voidReadData(uint16 Copy_uint16Location, uint8  * Copy_uint8ReceivedData)
{
	if(Copy_uint16Location <= 1023)
	{
		uint8 Local_uint8AddressPacket = 0;
		Local_uint8AddressPacket = EEPROM_ADDRESS_FIXED | (A2_Connection << 2) | ((uint8)Copy_uint16Location >> 8);
		
		/*Send Start Condition*/
		MTWI_ErrorStatusSendStartCondition();
		
		/*Send Slave Address With Write Request*/
		MTWI_ErrorStatusSendSlaveAddressWithWrite(Local_uint8AddressPacket);
		/*Send The Rest Of Byte Address*/
		MTWI_ErrorStatusMasterWriteDataByte((uint8)Copy_uint16Location);
		/*Send Repeated Start Condition*/
		MTWI_ErrorStatusSendRepeatedStartCondition();
		
		/*Send The Slave Address With Read Request*/
		MTWI_ErrorStatusSendSlaveAddressWithRead(Local_uint8AddressPacket);
		/*Get The Data From The Memory*/
		MTWI_ErrorStatusMasterReadDataByte(Copy_uint8ReceivedData);
		/*Send Stop Condition*/
		MTWI_voidSendStopCondition();
		
		_delay_ms(10);
	}	
}






