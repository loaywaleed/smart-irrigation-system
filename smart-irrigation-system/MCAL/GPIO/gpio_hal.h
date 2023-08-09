/*
 * gpio_hal.h
 *
 * Created: 14/06/2023 11:22:59 pm
 *  Author: Loay
 */ 

#ifndef GPIO_HAL_H_
#define GPIO_HAL_H_

/* Includes */
#include "../../LIB/std_types.h"

/* Macros */
#define MAX_PORT_NUMBER			7
#define MAX_PIN_NUMBER			7

/* Types declarations */
typedef enum
{
	OUTPUT=0,
	INPUT,
	INPUT_PLUP,
} direction_t;

typedef enum
{
	LOW=0,
	HIGH
} logic_t;

typedef enum
{
	PORTB_INDEX = 0,
	PORTC_INDEX = 1,
	PORTD_INDEX = 2
} port_index_t;

typedef enum
{
	PIN0_INDEX = 0,
	PIN1_INDEX,
	PIN2_INDEX,
	PIN3_INDEX,
	PIN4_INDEX,
	PIN5_INDEX,
	PIN6_INDEX,
	PIN7_INDEX
} pin_index_t;
	
typedef struct pin_config
{
	u8 port : 2;
	u8 pin : 3;
	u8 logic : 1;
	u8 direction : 2;
} pin_config_t;

/* Function prototypes */
STD_ReturnType GPIO_SetPinDirection(pin_config_t *_pin_config, direction_t direction);
STD_ReturnType GPIO_InitPin(pin_config_t *_pin_config);
STD_ReturnType GPIO_WritePinValue(pin_config_t *_pin_config, logic_t logic_value);
STD_ReturnType GPIO_ReadPinValue(pin_config_t *_pin_config, logic_t *logic);
STD_ReturnType GPIO_TogglePinValue(pin_config_t *_pin_config);

STD_ReturnType GPIO_SetPortDirection(port_index_t port, direction_t direction);
STD_ReturnType GPIO_WritePortValue(port_index_t port, logic_t value);
STD_ReturnType GPIO_ReadPortValue(port_index_t port, logic_t *value);
STD_ReturnType GPIO_TogglePortValue(port_index_t port);

#endif /* GPIO_HAL_H_ */