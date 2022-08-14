 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Kirollos Medhat
 *
 *******************************************************************************/
#include "adc.h"
#include <avr/io.h>

/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/


/*
 * Description: Initializing the ADC
 */

void ADC_init(const ADC_ConfigType * Config_Ptr){
	/*ADMUX Description:
	 * 1.ADMUX Bits 7:6 Masked into the structure configurable
	 * reference volt
	 * 2.ADLAR5 = 0 Disable ADC Left Adjust Result
	 * 3.MUX4:0 0 To work on ADC0 channel PORTA PIN0
	 */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<REFS0);

	/* ADCSRA Description: ADEN    = 1 Enable ADC
	 * 					   ADPS BITS 2:0 Masked to choose
	 * 					   clock pre-scaler
	 */
	SET_BIT(ADCSRA,ADEN);
	ADCSRA = (ADCSRA & 0xF8) | ((Config_Ptr->prescaler)&0x07);
}

/*
 * Description: ADC_readChannel which read the channel input
 * 				and process the conversion
 * 				returning the result saved on ADC register
 */
uint16 ADC_readChannel(uint8 a_channelNumber){
	/*
	 * ADMUX masking to select MUX4:0 to insert
	 * channel number of single sided input
	 * ADSC = 1 start conversion
	 * wait until ADIF is 1 for the end of conversion flag
	 * ADIF =1 clearing the flag again to re_process
	 * return the resulted process in ADC value
	 */
	ADMUX = (ADMUX & 0xE0) | (a_channelNumber & 0x07);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
