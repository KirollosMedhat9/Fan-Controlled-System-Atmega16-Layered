 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: LM35_sensor.h
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Kirollos Medhat
 *
 *******************************************************************************/


#include "LM35_sensor.h"
#include <avr/io.h>
#include "adc.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/*
 * Description: Calculate the value of ADC at any temperature
	ASSUMPTION made that LM35 in Simulation is 0-150 degree Range
 */

uint8 LM35_getTemperature(void){
	uint16 a_adcValue =0;
	uint8 a_tempValue=0;
	/*
	 * Read The channel which Sensor is connected
	 */
	a_adcValue = ADC_readChannel(LM35_Sensor_CHANNEL_ID);

	/*
	 * Calculate the Temperature according the ADC value
	 */

	a_tempValue = (uint8)(((uint32)a_adcValue*ADC_Internal_VREF*LM35_Sensor_MAX_TEMPERATURE)/(LM35_Sensor_MAX_VOLT*ADC_MAX_BITS));
	return a_tempValue;
}

