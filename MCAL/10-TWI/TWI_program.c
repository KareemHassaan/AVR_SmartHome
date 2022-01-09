/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						04 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: TWI Driver                                                        							                      *
* ! File Name	: TWI_program.c                                                       							                      *
* ! Description : This file has the implementation of Basic of TWI functions        							                      *
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
#include"TWI_intrface.h"  
#include"TWI_private.h"
#include"TWI_config.h"


/*************************************************************************************************************************************/
/***************************************************** Functions Definition **********************************************************/
/*************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: MTWI_voidMasterInit																		                      *
* Parameters (in)	: uint8 Copy_uint8SlaveAddress																                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialize The Node as a Master					  							                      *
**************************************************************************************************************************************/
void MTWI_voidMasterInit(uint8 Copy_uint8SlaveAddress)
{
	/*Configre The Acknowledge Enable*/
	 SET_SPECIFIC_REG_BITS_VALUE(TWCR,ACK_ENABLE_MASK,ACKNOWLEDGE_ENABLE_VALUE);

	/*Configure The TWBR Register According To The Configration*/
	 TWBR = (((CPU_FREQUENCY)/(SCL_FREQUENCY_KHZ*KILO))- EQU_CONSTANT16) / (EQU_CONSTANT2 * Power(EQU_CONSTANT4,MASTER_PRESCALLER_VALUE));
	/*Configre The Prescaler Bit (TWPS0, TWPS1)*/
	 SET_SPECIFIC_REG_BITS_VALUE(TWSR,PRESCALLER_MASK,MASTER_PRESCALLER_VALUE);
	
	/*Check if the master node will be addressed or not*/
	 if(Copy_uint8SlaveAddress != 0)
	 {
		/*Assign The Slave Address*/
		 TWAR = Copy_uint8SlaveAddress << 1;
	 }
	 else
	 {
		/*Do Nothing*/
	 }
	 
	/*Enable TWI*/
	 SET_BIT(TWCR, TWCR_TWEN);
}

/**************************************************************************************************************************************
* Function Name		: MTWI_voidSlaveInit																		                      *
* Parameters (in)	: uint8 Copy_uint8SlaveAddress																                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialize The Node as a Slave					  							                      *
**************************************************************************************************************************************/
void MTWI_voidSlaveInit(uint8 Copy_uint8SlaveAddress)
{
	/*Configre The Acknowledge Enable*/
	 SET_SPECIFIC_REG_BITS_VALUE(TWCR,ACK_ENABLE_MASK,ACKNOWLEDGE_ENABLE_VALUE);

	/*Assign The Slave Address*/
	 TWAR = Copy_uint8SlaveAddress << 1;
	
	/*Enable TWI*/
	 SET_BIT(TWCR, TWCR_TWEN);
}

/**************************************************************************************************************************************
* Function Name		: MTWI_ErrorStatusSendStartCondition														                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Send Start Condition								  							                      *
**************************************************************************************************************************************/
TWI_ErrorStatus_t MTWI_ErrorStatusSendStartCondition()
{
	/*Initialize Returned Error With No Error*/
	 TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	
	/*Set The Start Condition Bit*/
	 SET_BIT(TWCR, TWCR_TWSTA);
	/*Clear The TWINT Flag*/
	 SET_BIT(TWCR, TWCR_TWINT);
	
	/*Polling (Busy Wait) until the flag is raised again*/
	 while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	 
	/*Check if the Start Condition is Transmitted*/
	 if((TWSR & STATUS_CODE_MASK) != START_ACK)
	 {
		/*Set the Returned Error to Start Condition Error*/ 
 		 Local_ErrorStatus = StartConditionError;
	 }
	
	/*Return The Error Indicator*/
	 return Local_ErrorStatus;
}

/**************************************************************************************************************************************
* Function Name		: MTWI_ErrorStatusSendRepeatedStartCondition												                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Send Repeated Start Condition						  							                      *
**************************************************************************************************************************************/
TWI_ErrorStatus_t MTWI_ErrorStatusSendRepeatedStartCondition()
{
	/*Initialize Returned Error With No Error*/
	 TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	 
	/*Set The Start Condition Bit*/
	 SET_BIT(TWCR, TWCR_TWSTA);
	/*Clear The Flag*/
	 SET_BIT(TWCR, TWCR_TWINT);
	 
	/*Polling (Busy Wait) until the flag is raised again*/
	 while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	
	/*Check if the Start Condition is Transmitted*/
	 if((TWSR & STATUS_CODE_MASK) != REP_START_ACK)
	 {
		/*Set the Returned Error to Repeated Start Condition Error*/ 
		 Local_ErrorStatus = RepeatedStartConditionError;
 	 }
	
	/*Return The Error Indicator*/
	 return Local_ErrorStatus;
}

/**************************************************************************************************************************************
* Function Name		: MTWI_ErrorStatusSendSlaveAddressWithWrite													                      *
* Parameters (in)	: uint8 Copy_uint8SlaveAddress																                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Send Slave Address With Write Request				  							                      *
**************************************************************************************************************************************/
TWI_ErrorStatus_t MTWI_ErrorStatusSendSlaveAddressWithWrite(uint8 Copy_uint8SlaveAddress)
{	
	/*Initialize Returned Error With No Error*/
	 TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	
	/*Load The Slave Address To The TWDR Register*/
	 TWDR = Copy_uint8SlaveAddress << 1;
	/*Clear The Bit 0 For The Write Request*/
	 CLR_BIT(TWDR, TWDR_TWD0);
	/*Clear The Start Condition Bit*/
	 CLR_BIT(TWCR, TWCR_TWSTA);
	/*Clear The Flag*/
	 SET_BIT(TWCR, TWCR_TWINT);
	 
	/*Polling (Busy Wait) until the flag is raised again*/
	 while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	 
	/*Check if the Start Condition is Transmitted*/
	 if((TWSR & STATUS_CODE_MASK) != SLAVE_ADD_AND_WR_ACK)
	 {
		/*Set the Returned Error to Slave Address With Write Error*/ 
		 Local_ErrorStatus = SlaveAddressWithWriteError;
	 }
	 
	/*Return The Error Indicator*/
	 return Local_ErrorStatus;
}

/**************************************************************************************************************************************
* Function Name		: MTWI_ErrorStatusSendSlaveAddressWithRead													                      *
* Parameters (in)	: uint8 Copy_uint8SlaveAddress																                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Send Slave Address With Read Request				  							                      *
**************************************************************************************************************************************/
TWI_ErrorStatus_t MTWI_ErrorStatusSendSlaveAddressWithRead(uint8 Copy_uint8SlaveAddress)
{
	/*Initialize Returned Error With No Error*/
	 TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	 
	/*Load The Slave Address To The TWDR Register*/
	 TWDR = Copy_uint8SlaveAddress << 1;
	/*Set The Bit 0 For The Read Request*/
	 SET_BIT(TWDR, TWDR_TWD0);
	/*Clear The Start Condition Bit*/
	 CLR_BIT(TWCR, TWCR_TWSTA);
	/*Clear The Flag*/
	 SET_BIT(TWCR, TWCR_TWINT);
	 
	/*Polling (Busy Wait) until the flag is raised again*/
	 while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	
	/*Check if the Start Condition is Transmitted*/
	 if((TWSR & STATUS_CODE_MASK) != SLAVE_ADD_AND_RD_ACK)
	 {
		/*Set the Returned Error to Slave Address With Read Error*/ 
		 Local_ErrorStatus = SlaveAddressWithReadError;
	 }
	 
	/*Return The Error Indicator*/
	 return Local_ErrorStatus;
}

/**************************************************************************************************************************************
* Function Name		: MTWI_ErrorStatusMasterWriteDataByte														                      *
* Parameters (in)	: uint8 Copy_uint8Data																		                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to write a Data										  							                      *
**************************************************************************************************************************************/
TWI_ErrorStatus_t MTWI_ErrorStatusMasterWriteDataByte(uint8 Copy_uint8Data)
{
	/*Initialize Returned Error With No Error*/
	 TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	 
	/*Load The Data Into The TWDR Register*/
	 TWDR = Copy_uint8Data;
	/*Clear The Flag*/
	 SET_BIT(TWCR, TWCR_TWINT);
	 
	/*Polling (Busy Wait) until the flag is raised again*/
	 while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	
	/*Check if the Start Condition is Transmitted*/
	 if((TWSR & STATUS_CODE_MASK) != MSTR_WR_BYTE_ACK)
	 {
		/*Set the Returned Error to Master Write Byte Error*/ 
		 Local_ErrorStatus = MasterWriteByteError;
	 } 
	 
	/*Return The Error Indicator*/
	 return Local_ErrorStatus;
}

/**************************************************************************************************************************************
* Function Name		: MTWI_ErrorStatusMasterReadDataByte														                      *
* Parameters (in)	: uint8 * Copy_puint8ReceivedData															                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Read a Data										  							                      *
**************************************************************************************************************************************/
TWI_ErrorStatus_t MTWI_ErrorStatusMasterReadDataByte(uint8 * Copy_puint8ReceivedData)
{
	/*Initialize Returned Error With No Error*/
	 TWI_ErrorStatus_t Local_ErrorStatus = NoError;
	 
	/*Clear The Flag, To Make The Slave Send Its Data*/
	 SET_BIT(TWCR, TWCR_TWINT);
	 
	/*Polling (Busy Wait) until the flag is raised again*/
	 while(GET_BIT(TWCR, TWCR_TWINT) == 0);
	
	/*Check if the Start Condition is Transmitted*/
	 if((TWSR & STATUS_CODE_MASK) != MSTR_RD_BYTE_WITH_ACK)
	 {
		/*Set the Returned Error to Master Read Byte Error*/ 
		 Local_ErrorStatus = MasterReadByteError;
	 } 
	 else
	 {
		/*Get The Received Data*/
		 *Copy_puint8ReceivedData = TWDR;
	 }
	 
	/*Return The Error Indicator*/
	 return Local_ErrorStatus;
}

/**************************************************************************************************************************************
* Function Name		: MTWI_voidSendStopCondition																                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Send Stop condition								  							                      *
**************************************************************************************************************************************/
void MTWI_voidSendStopCondition()
{
	/*Set The STOP CONDITION Bit*/
	SET_BIT(TWCR, TWCR_TWSTO);
	/*Clear The Flag, To Make The Slave Send Its Data*/
	SET_BIT(TWCR, TWCR_TWINT);
}

/**************************************************************************************************************************************
* Function Name		: Power																						                      *
* Parameters (in)	: uint8 Copy_uint8BaseValue,uint8 Copy_uint8PowerValue										                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Calculate The Power Any Number					  							                      *
**************************************************************************************************************************************/
uint8 Power(uint8 Copy_uint8BaseValue,uint8 Copy_uint8PowerValue)
{
    uint8 Local_uint8Result = 1;
    uint8 Local_uint8LoopCounter = 0;
    
	/*Add The Number To Itself Power Num Times*/
    for(Local_uint8LoopCounter = 0; Local_uint8LoopCounter < Copy_uint8PowerValue; Local_uint8LoopCounter++)
    {
        Local_uint8Result *= Copy_uint8BaseValue;
    }
	
	/*Return The Result*/
    return Local_uint8Result;
}
