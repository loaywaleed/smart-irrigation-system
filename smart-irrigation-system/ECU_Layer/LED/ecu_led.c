/*
 * ecu_led.c
 *
 * Created: 31/07/2023 10:18:00 am
 *  Author: Loay
 */ 
#include "ecu_led.h"

STD_ReturnType LED_Initialize(const led_config_t *led_config)
{
	STD_ReturnType ret = E_OK;
	pin_config_t pin_obj = { .port = led_config->port, .pin = led_config->pin, .direction = OUTPUT,
							 .logic = led_config->led_status };

	if (led_config == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		GPIO_InitPin(&pin_obj);
	}
	return (ret);
}

STD_ReturnType LED_TurnOn(const led_config_t *led_config)
{
	STD_ReturnType ret = E_OK;
	pin_config_t pin_obj = { .port = led_config->port, .pin = led_config->pin, .direction = OUTPUT,
	.logic = led_config->led_status };

	if (led_config == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		GPIO_WritePinValue(&pin_obj, HIGH);
	}
	return (ret);	
}

STD_ReturnType LED_TurnOff(const led_config_t *led_config)
{
	STD_ReturnType ret = E_OK;
	pin_config_t pin_obj = { .port = led_config->port, .pin = led_config->pin, .direction = OUTPUT,
	.logic = led_config->led_status };
	if (led_config == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		GPIO_WritePinValue(&pin_obj, LOW);
	}
	return (ret);		
}

STD_ReturnType LED_Toggle(const led_config_t *led_config)
{
	STD_ReturnType ret = E_OK;
	pin_config_t pin_obj = { .port = led_config->port, .pin = led_config->pin, .direction = OUTPUT,
	.logic = led_config->led_status };
	if (led_config == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		GPIO_TogglePinValue(&pin_obj);
	}
	return (ret);	
}
