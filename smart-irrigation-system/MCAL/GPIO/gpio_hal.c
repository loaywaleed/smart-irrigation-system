/*
 * gpio_hal.c
 *
 * Created: 14/06/2023 11:22:06 pm
 * Author: Loay
 */ 


#include "gpio_hal.h"

volatile u8 *ddr_registers[] = {&DDRB, &DDRC, &DDRD};	
volatile u8 *port_registers[] = {&PORTB, &PORTC, &PORTD};
volatile u8 *pin_registers[] = {&PINB, &PINC, &PIND};

STD_ReturnType GPIO_SetPinDirection(pin_config_t *_pin_config, direction_t direction)
{
	STD_ReturnType ret = E_OK;
	
	if (_pin_config == NULL || _pin_config->pin > MAX_PIN_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(direction) {
			case INPUT:
				CLEAR_BIT(*ddr_registers[_pin_config->port], _pin_config->pin);
				break;
			case OUTPUT:
				SET_BIT(*ddr_registers[_pin_config->port], _pin_config->pin);
				break;
			case INPUT_PLUP:
				CLEAR_BIT(*ddr_registers[_pin_config->port], _pin_config->pin);
				SET_BIT(*port_registers[_pin_config->port], _pin_config->pin);
				break;
			default:
				ret = E_NOT_OK;
		}
	}
	
	return (ret);
}

STD_ReturnType GPIO_InitPin(pin_config_t *_pin_config)
{
	STD_ReturnType ret = E_OK;
		
	if (_pin_config == NULL || _pin_config->pin > MAX_PIN_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(_pin_config->direction) {
			case INPUT:
				CLEAR_BIT(*ddr_registers[_pin_config->port], _pin_config->pin);
				GPIO_WritePinValue(_pin_config, _pin_config->logic);
			break;
			case OUTPUT:
				SET_BIT(*ddr_registers[_pin_config->port], _pin_config->pin);
				GPIO_WritePinValue(_pin_config, _pin_config->logic);
				break;
			case INPUT_PLUP:
				CLEAR_BIT(*ddr_registers[_pin_config->port], _pin_config->pin);
				GPIO_WritePinValue(_pin_config, HIGH);
				break;
			default:
				ret = E_NOT_OK;
		}
	}
	
	return (ret);
}

STD_ReturnType GPIO_WritePinValue(pin_config_t *_pin_config, logic_t logic)
{
	STD_ReturnType ret = E_OK;
	
	if (_pin_config == NULL || _pin_config->pin > MAX_PIN_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(logic) {
		case LOW:
			CLEAR_BIT(*port_registers[_pin_config->port], _pin_config->pin);
			break;
		case HIGH:
			SET_BIT(*port_registers[_pin_config->port], _pin_config->pin);
			break;
		default:
			ret = E_NOT_OK;
		}
	}
	
	return (ret);
}

STD_ReturnType GPIO_ReadPinValue(pin_config_t *_pin_config, logic_t *logic)
{
	STD_ReturnType ret = E_OK;
	
	if (_pin_config == NULL || logic == NULL)
	{
		ret = E_NOT_OK;  
	}
	else
	{
		*logic = READ_BIT(*pin_registers[_pin_config->port], _pin_config->pin);
	}
	
	return (ret);
}

STD_ReturnType GPIO_TogglePinValue(pin_config_t *_pin_config)
{
	STD_ReturnType ret = E_OK;
	
	if (_pin_config == NULL || _pin_config->pin > MAX_PIN_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		TOGGLE_BIT(*pin_registers[_pin_config->port], _pin_config->pin);
	}
	
	return (ret);
}

STD_ReturnType GPIO_SetPortDirection(port_index_t port, direction_t direction)
{
	STD_ReturnType ret = E_OK;
	
	if (port > MAX_PORT_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(direction) {
			case INPUT:
			case INPUT_PLUP:
				*ddr_registers[port] = 0x00;
				break;
			case OUTPUT:
				*ddr_registers[port] = 0xff;
				break;
			default:
				ret = E_NOT_OK;
		}
	}
	
	return (ret);
}

STD_ReturnType GPIO_WritePortValue(port_index_t port, logic_t value)
{
	STD_ReturnType ret = E_OK;
	
	if (port > MAX_PORT_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*port_registers[port] = value;	
	}

	return (ret);
}

STD_ReturnType GPIO_ReadPortValue(port_index_t port, logic_t *value)
{
	STD_ReturnType ret = E_OK;
	
	if (port > MAX_PORT_NUMBER || value == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*value = *port_registers[port];
	}
	
	return (ret);
}

STD_ReturnType GPIO_TogglePortValue(port_index_t port)
{
	STD_ReturnType ret = E_OK;
		
	if (port > MAX_PORT_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*port_registers[port] ^= 0xff;			
	}
		
	return (ret);
}





/************************************************************************/
/* todo: check for port and pin numbers                                 */
/* add else statements                                                  */
/************************************************************************/