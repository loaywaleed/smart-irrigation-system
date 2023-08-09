/*
 * haL_uart.c
 *
 * Created: 26/07/2023 12:19:44 am
 *  Author: Loay
 */ 

#include "hal_uart.h"

STD_ReturnType UART_Init(void)
{
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	

	/* double speed mode */
	#if USE_2X
	SET_BIT(UCSR0A, U2X0);
	#else
	CLEAR_BIT(UCSR0A, U2X0);
	#endif
	
	SET_BIT(UCSR0B, TXEN0);
	SET_BIT(UCSR0B, RXEN0);
	
	SET_BIT(UCSR0C, UCSZ01);
	SET_BIT(UCSR0C, UCSZ00);
	return (E_OK);
}


STD_ReturnType UART_TransmitByte(u8 byte)
{
	while(!READ_BIT(UCSR0A, UDRE0));
	UDR0 = byte;
	return (E_OK);
}
STD_ReturnType UART_ReceiveByte(u8 *byte_value)
{
	while(!READ_BIT(UCSR0A, RXC0));
	*byte_value = UDR0;
	return (E_OK);
}
STD_ReturnType UART_PrintString(const char *str)
{
	u8 i = 0;
	
	while (str[i])
	{
		UART_TransmitByte(str[i]);
		i++;
	}
	return (E_OK);
}

STD_ReturnType UART_PrintNumber(u16 number)
{
	char str[7];
		
	itoa(number, str, 10);
	UART_PrintString(str);
	UART_TransmitByte('\n');
	return (E_OK);
}