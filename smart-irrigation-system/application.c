/*
 * smart-irrigation-system.c
 *
 * Created: 21/07/2023 9:26:37 am
 * Author : Loay
 */ 

#include "application.h"

/* Pin Configurations */
pin_config_t pump = {
	.port = PORTB_INDEX,
	.pin = PIN0_INDEX,
	.logic = LOW,
	.direction = OUTPUT
};

/*pin_config_t level_switch = {
	.port = PORTD_INDEX,
	.pin = PIN2_INDEX,
	.logic = HIGH,
	.direction = INPUT_PLUP
};*/

pin_config_t sensor_power = {
	.port = PORTC_INDEX,
	.pin = PIN5_INDEX,
	.logic = HIGH,
	.direction = OUTPUT
};

pin_config_t moisture_sensor = {
	.port = PORTC_INDEX,
	.pin = PIN3_INDEX,
	.logic = LOW,
	.direction = INPUT
};

led_config_t dry_indicator = {
	.port = PORTD_INDEX,
	.pin = PIN3_INDEX,
	.led_status = OFF
};

/* Initialization */
void APP_Init(void)
{
	GPIO_InitPin(&pump);
	//GPIO_InitPin(&level_switch);
	GPIO_InitPin(&moisture_sensor);
	/* Turn on moisture sensor */
	GPIO_InitPin(&sensor_power);
	ADC_Init(DIV_8, AVCC_INDEX);
	LED_Initialize(&dry_indicator);
}

/* Entry point */
int main(void)
{
	logic_t tank_value;
	STD_ReturnType ret;
	u16 moisture_reading;
	
	APP_Init();
    while (1) 
    {
		//ret = GPIO_ReadPinValue(&level_switch, &tank_value);
		tank_value = HIGH;
		/* Reading moisture sensor value */
		ret = ADC_ReadChannel(ADC3_INDEX, &moisture_reading);
		//ret = UART_PrintString("Soil Moisture Reading is: \n");
		//ret = UART_PrintNumber(moisture_reading);
		//ret = UART_TransmitByte('\n');
		ret = GPIO_WritePinValue(&sensor_power, HIGH);
		
		if (tank_value == HIGH)
		{
			if (moisture_reading > 435 && moisture_reading <= 560)
			{
				//ret = UART_PrintString("Soil is dry\n");
				ret = GPIO_WritePinValue(&pump, HIGH);
				ret = LED_TurnOn(&dry_indicator);
			}
			else if (moisture_reading > 315 && moisture_reading <= 435)
			{
				ret = GPIO_WritePinValue(&pump, LOW);
				//ret = UART_PrintString("Soil is wet\n");
				ret = LED_TurnOff(&dry_indicator);
			}
			else if (moisture_reading >= 195 && moisture_reading <= 315)
			{
				ret = GPIO_WritePinValue(&pump, LOW);
				//ret = UART_PrintString("Soil is very wet\n");
				ret = LED_TurnOff(&dry_indicator);
			}
			else 
			{
				ret = LED_TurnOff(&dry_indicator);
				ret = GPIO_WritePinValue(&pump, LOW);
			}
		}
		else 
		{
			ret = GPIO_WritePinValue(&sensor_power, LOW);
			ret = GPIO_WritePinValue(&pump, LOW);
			//ret = UART_PrintString("Tank is empty\n");
			ret = LED_TurnOn(&dry_indicator);
		}
		_delay_ms(500);
    }
	return (ret);
}

