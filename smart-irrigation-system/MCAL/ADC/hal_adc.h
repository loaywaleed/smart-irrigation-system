/*
 * hal_adc.h
 *
 * Created: 17/07/2023 11:18:09 pm
 *  Author: Loay
 */ 


#ifndef HAL_ADC_H_
#define HAL_ADC_H_

/* Includes */
#include "../GPIO/gpio_hal.h"

/* Macros */

//ADC Multiplexer Selection (ADMUX)
#define		REFS1			7
#define		REFS0			6
#define		ADLAR			5
#define		MUX3			3
#define		MUX2			2
#define		MUX1			1
#define		MUX0			0

//ADC Control and Status Register A
#define		ADEN			7
#define		ADSC			6
#define		ADATE			5
#define		ADIF			4
#define		ADIE			3
#define		ADPS2			2
#define		ADPS1			1
#define		ADPS0			0

//ADC Control and Status Register B
#define		ACME			6
#define		ADTS2			2
#define		ADTS1			1
#define		ADTS0			0

/* Types Declarations */
typedef enum
{
	AREF_INDEX = 0,
	AVCC_INDEX,
	INTERNAL_INDEX
} voltage_ref_t;

typedef enum
{
	DIV_2,
	DIV_4,
	DIV_8,
	DIV_16,
	DIV_32,
	DIV_64,
	DIV_128
} adc_prescaler_t;

typedef enum{
	ADC0_INDEX,
	ADC1_INDEX,
	ADC2_INDEX,
	ADC3_INDEX,
	ADC4_INDEX,
	ADC5_INDEX,
	ADC6_INDEX,
	ADC7_INDEX,
	ADC8_INDEX		/* Temperature Sensor */		
} adc_channel_t;


STD_ReturnType ADC_Init(adc_prescaler_t clock, voltage_ref_t);
STD_ReturnType ADC_ReadChannel(adc_channel_t channel, u16 *adc_value);
#endif /* HAL_ADC_H_ */