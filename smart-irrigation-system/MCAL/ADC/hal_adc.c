/*
 * hal_adc.c
 *
 * Created: 17/07/2023 11:17:57 pm
 *  Author: Loay
 */ 

#include "hal_adc.h"

STD_ReturnType ADC_Init(adc_prescaler_t clock, voltage_ref_t v_ref)
{
	STD_ReturnType ret = E_OK;
	
	//Enable ADC
	SET_BIT(ADCSRA, ADEN);
	
	switch (v_ref) {
	case AREF_INDEX:
		CLEAR_BIT(ADMUX, REFS0);
		CLEAR_BIT(ADMUX, REFS1);
		break;
	case AVCC_INDEX:
		SET_BIT(ADMUX, REFS0);
		CLEAR_BIT(ADMUX, REFS1);
		break;
	case INTERNAL_INDEX:
		SET_BIT(ADMUX, REFS0);
		SET_BIT(ADMUX, REFS1);
		break;
	default:
		ret = E_NOT_OK;
	}
	switch (clock) {
	case DIV_2:
		CLEAR_BIT(ADCSRA, ADPS2);
		CLEAR_BIT(ADCSRA, ADPS1);
	break;
	case DIV_4:
		CLEAR_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		CLEAR_BIT(ADCSRA, ADPS0);
		break;
	case DIV_8:
		CLEAR_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS0);
		break;
	case DIV_16:
		SET_BIT(ADCSRA, ADPS2);
		CLEAR_BIT(ADCSRA, ADPS1);
		CLEAR_BIT(ADCSRA, ADPS0);
		break;
	case DIV_32:
		SET_BIT(ADCSRA, ADPS2);
		CLEAR_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS0);
		break;
	case DIV_64:
		SET_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		CLEAR_BIT(ADCSRA, ADPS0);
		break;
	case DIV_128:
		SET_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS0);
		break;
	default:
		return E_NOT_OK;
	}
	
	return (ret);
}



STD_ReturnType ADC_ReadChannel(adc_channel_t channel, u16 *adc_value)
{
	STD_ReturnType ret = E_OK;
	if (adc_value == NULL)
	{
		return E_NOT_OK;
	}
	/* single conversion mode */
	switch (channel) {
		case ADC0_INDEX:
		CLEAR_BIT(ADMUX, MUX0);
		CLEAR_BIT(ADMUX, MUX1);
		CLEAR_BIT(ADMUX, MUX2);
		break;
		case ADC1_INDEX:
		SET_BIT(ADMUX, MUX0);
		CLEAR_BIT(ADMUX, MUX1);
		CLEAR_BIT(ADMUX, MUX2);
		break;
		case ADC2_INDEX:
		CLEAR_BIT(ADMUX, MUX0);
		SET_BIT(ADMUX, MUX1);
		CLEAR_BIT(ADMUX, MUX2);
		break;
		case ADC3_INDEX:
		SET_BIT(ADMUX, MUX0);
		SET_BIT(ADMUX, MUX1);
		CLEAR_BIT(ADMUX, MUX2);
		break;
		case ADC4_INDEX:
		CLEAR_BIT(ADMUX, MUX0);
		CLEAR_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX2);
		break;
		case ADC5_INDEX:
		SET_BIT(ADMUX, MUX0);
		CLEAR_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX2);
		break;
		default:
		ret = E_NOT_OK;
	}
	
	SET_BIT(ADCSRA, ADSC);
	
	while(READ_BIT(ADCSRA, ADSC));
	
	*adc_value = ADC;
	return (ret);
}