/**************************************************************************************************************************************
* LOG:                                                                   							   								  *
* VERSION					AUTHOR           					DATE 						DESCRIPTION 		   					  *
* 1.0.0 					Kareem Hassaan						2 DEC,2021					- Initial Creation						  *
**************************************************************************************************************************************/
/**************************************************************************************************************************************
* ! Title      	: Library                                                        							                          *
* ! File Name	: BIT_MATH.h                                                     							                          *
* ! Description : This file has the Defines of all Operations on Bit needed				       							              *
* ! Compiler  	: GNU AVR cross Compiler                                            							                      *
* ! Target 	  	: Atmega32 Micro-Controller                                         							                      *
* ! Layer 	  	: LIB                  						                                         							      *
**************************************************************************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT_NUM) 								REG |=  (0x01<<BIT_NUM)
#define CLR_BIT(REG,BIT_NUM)								REG &= ~(0x01<<BIT_NUM)
#define TOG_BIT(REG,BIT_NUM) 								REG ^=  (0x01<<BIT_NUM)
#define GET_BIT(REG,BIT_NUM)   						  		  ((REG>>BIT_NUM)&0x01)

#define SET_SPECIFIC_REG_BITS_VALUE(REG,MASK,VALUE) 					REG = ((REG & MASK)|VALUE)


#endif /* BIT_MATH_H */
