/*
 * ecu_led.h
 *
 * Created: 31/07/2023 10:17:46 am
 *  Author: Loay
 */ 


#ifndef ECU_LED_H_
#define ECU_LED_H_

/* Includes */
#include "../../MCAL/GPIO/gpio_hal.h"


/* Macros */


/* Types declaration */
typedef enum {
	OFF=0,
	ON
} led_status_t;

typedef struct {
	u8 port :3;
	u8 pin :3;
	u8 led_status: 1;
} led_config_t;

/* Function prototypes */
STD_ReturnType LED_Initialize(const led_config_t *led_config);
STD_ReturnType LED_TurnOn(const led_config_t *led_config);
STD_ReturnType LED_TurnOff(const led_config_t *led_config);
STD_ReturnType LED_Toggle(const led_config_t *led_config);


#endif /* ECU_LED_H_ */