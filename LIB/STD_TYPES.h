/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						2 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Library                                                        							                          *
* ! File Name	: STD_TYPES.h                                                     							                          *
* ! Description : This file has the Defines of all standard types needed				       							              *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: LIB                  						                                         							      *
**************************************************************************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

#define NULL (void*)0						  /*           NULL PTR             */	

typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           sint8;          /*        -128 .. +127            */

typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          sint16;         /*      -32768 .. +32767          */

typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           sint32;         /* -2147483648 .. +2147483647     */

typedef unsigned long long    uint64;         /*       0..18446744073709551615  */
typedef signed long long      sint64;

typedef float                 float32;
typedef double                float64;

#endif /* STD_TYPES_H */
