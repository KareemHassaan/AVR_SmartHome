/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						04 JAN,2022					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: TWI Driver                                                        							                      *                     
* ! File Name	: TWI_intrface.h                                                     							                      *
* ! Description : This file has the Definitions needed		         		        							                      *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: MCAL                  						                                         							  *
**************************************************************************************************************************************/
#ifndef TWI_INTRFACE_H
#define TWI_INTRFACE_H

/*************************************************************************************************************************************/
/****************************************************** Error Return Error ***********************************************************/
/*************************************************************************************************************************************/
typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartConditionError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteError,
	MasterReadByteError,

}TWI_ErrorStatus_t;

/*************************************************************************************************************************************/
/***************************************************** Functions Prototypes **********************************************************/
/*************************************************************************************************************************************/

/**************************************************************************************************************************************
* Function Name		: MTWI_voidMasterInit																		                      *
* Parameters (in)	: uint8 Copy_uint8SlaveAddress																                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialize The Node as a Master					  							                      *
**************************************************************************************************************************************/
void MTWI_voidMasterInit(uint8 Copy_uint8SlaveAddress);
/**************************************************************************************************************************************
* Function Name		: MTWI_voidSlaveInit																		                      *
* Parameters (in)	: uint8 Copy_uint8SlaveAddress																                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Initialize The Node as a Slave					  							                      *
**************************************************************************************************************************************/
void MTWI_voidSlaveInit(uint8 Copy_uint8SlaveAddress);
/**************************************************************************************************************************************
* Function Name		: MTWI_ErrorStatusSendStartCondition														                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Send Start Condition								  							                      *
**************************************************************************************************************************************/
TWI_ErrorStatus_t MTWI_ErrorStatusSendStartCondition();
/**************************************************************************************************************************************
* Function Name		: MTWI_ErrorStatusSendRepeatedStartCondition												                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Send Repeated Start Condition						  							                      *
**************************************************************************************************************************************/
TWI_ErrorStatus_t MTWI_ErrorStatusSendRepeatedStartCondition();
/**************************************************************************************************************************************
* Function Name		: MTWI_ErrorStatusSendSlaveAddressWithWrite													                      *
* Parameters (in)	: uint8 Copy_uint8SlaveAddress																                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Send Slave Address With Write Request				  							                      *
**************************************************************************************************************************************/
TWI_ErrorStatus_t MTWI_ErrorStatusSendSlaveAddressWithWrite(uint8 Copy_uint8SlaveAddress);
/**************************************************************************************************************************************
* Function Name		: MTWI_ErrorStatusSendSlaveAddressWithRead													                      *
* Parameters (in)	: uint8 Copy_uint8SlaveAddress																                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Send Slave Address With Read Request				  							                      *
**************************************************************************************************************************************/
TWI_ErrorStatus_t MTWI_ErrorStatusSendSlaveAddressWithRead(uint8 Copy_uint8SlaveAddress);
/**************************************************************************************************************************************
* Function Name		: MTWI_ErrorStatusMasterWriteDataByte														                      *
* Parameters (in)	: uint8 Copy_uint8Data																		                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to write a Data										  							                      *
**************************************************************************************************************************************/
TWI_ErrorStatus_t MTWI_ErrorStatusMasterWriteDataByte(uint8 Copy_uint8Data);
/**************************************************************************************************************************************
* Function Name		: MTWI_ErrorStatusMasterReadDataByte														                      *
* Parameters (in)	: uint8 * Copy_puint8ReceivedData															                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Read a Data										  							                      *
**************************************************************************************************************************************/
TWI_ErrorStatus_t MTWI_ErrorStatusMasterReadDataByte(uint8 * Copy_puint8ReceivedData);
/**************************************************************************************************************************************
* Function Name		: MTWI_voidSendStopCondition																                      *
* Parameters (in)	: None																						                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Send Stop condition								  							                      *
**************************************************************************************************************************************/
void MTWI_voidSendStopCondition();
/**************************************************************************************************************************************
* Function Name		: Power																						                      *
* Parameters (in)	: uint8 Copy_uint8BaseValue,uint8 Copy_uint8PowerValue										                      *
* Parameters (out)	: None																						                      *
* Return value		: None																						                      *
* Description		: Function to Calculate The Power Any Number					  							                      *
**************************************************************************************************************************************/
uint8 Power(uint8 Copy_uint8BaseValue,uint8 Copy_uint8PowerValue);



#endif /*TWI_INTRFACE_H*/
