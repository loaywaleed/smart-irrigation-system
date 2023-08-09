/*
 * application.h
 *
 * Created: 21/07/2023 9:31:19 am
 *  Author: Loay
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "MCAL/GPIO/gpio_hal.h"
#include "MCAL/ADC/hal_adc.h"
#include "ECU_Layer/LED/ecu_led.h"
#include "MCAL/UART/hal_uart.h"

void APP_Init(void);

#endif /* APPLICATION_H_ */