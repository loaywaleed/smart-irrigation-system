/*
 * hal_uart.h
 *
 * Created: 26/07/2023 12:19:21 am
 *  Author: Loay
 */ 


#ifndef HAL_UART_H_
#define HAL_UART_H_

#define BAUD		9600

#include "../GPIO/gpio_hal.h"
#include <util/setbaud.h>


STD_ReturnType UART_Init(void);
STD_ReturnType UART_TransmitByte(u8 byte);
STD_ReturnType UART_ReceiveByte(u8 *byte_value);
STD_ReturnType UART_PrintString(const char str[]);
STD_ReturnType UART_PrintNumber(u16 number);


#endif /* HAL_UART_H_ */