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
#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_
#include "adc.h"

/*******************************************************************************
 *                          Definitions                              *
 *******************************************************************************/
#define LM35_Sensor_MAX_TEMPERATURE 150
#define LM35_Sensor_MAX_VOLT 1.5
#define LM35_Sensor_CHANNEL_ID ADC_CHANNEL_TWO

/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

/*
 * Description:
 * Calculate the value of ADC at any temperature
 */
uint8 LM35_getTemperature(void);


#endif /* LM35_SENSOR_H_ */
