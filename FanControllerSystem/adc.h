/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Kirollos Medhat
 *
 *******************************************************************************/
#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
#include "common_macros.h"
/*******************************************************************************
 *                          Definitions                              *
 *******************************************************************************/
#define ADC_CHANNEL_ZERO 0
#define ADC_CHANNEL_ONE 1
#define ADC_CHANNEL_TWO 2
#define ADC_CHANNEL_THREE 3
#define ADC_CHANNEL_FOUR 4
#define ADC_CHANNEL_FIVE 5
#define ADC_CHANNEL_SIX 6
#define ADC_CHANNEL_SEVEN 7
#define ADC_VREF 5
#define ADC_Internal_VREF 2.56
#define ADC_MAX_BITS 1023

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	F_CPU_2=1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

typedef enum{
	AREF,AVCC,RESERVED,INTERNAL_VREF
}ADC_ReferenceVolatge;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;
/*******************************************************************************
 *                          Functions Decelerations                              *
 *******************************************************************************/

/*
 * Description:
 * Initializing the ADC
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description:
 * ADC_readChannel which read the channel input
 * and process the conversion
 * returning the result saved on ADC register
 *
 */
uint16 ADC_readChannel(uint8 a_channelNumber);

#endif /* ADC_H_ */
