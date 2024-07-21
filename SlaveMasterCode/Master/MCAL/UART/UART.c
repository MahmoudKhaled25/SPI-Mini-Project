/*
 * UART.c
 *
 * Created: 4/29/2024 10:56:40 PM
 *  Author: Blu-Ray
 */ 

#include "UART.h"
#include "MemoryMap.h"
#include "Utilities.h"

extern UART_cfg_type UART_cfg;

static CallBackPtr_type UART_RX_FPtr	= NULLPTR;
static CallBackPtr_type UART_UDRE_FPtr	= NULLPTR;
static CallBackPtr_type UART_TX_FPtr	= NULLPTR;

void UART_Init()
{
	u8 ucsrc=0;
	u16 ubrr=0;
	
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB, TXEN);
	CLR_BIT(ucsrc, UMSEL); // Asynchronous Mode
	SET_BIT(ucsrc, URSEL); // To write to UCSRC
	
	switch(UART_cfg.DataBits)
	{
		case UART_FiveDataBits:
		CLR_BIT(ucsrc, UCSZ0);
		CLR_BIT(ucsrc, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);
		break;
		
		case UART_SixDataBits:
		SET_BIT(ucsrc, UCSZ0);
		CLR_BIT(ucsrc, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);
		break;
		
		case UART_SevenDataBits:
		CLR_BIT(ucsrc, UCSZ0);
		SET_BIT(ucsrc, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);
		break;
		
		case UART_EightDataBits:
		SET_BIT(ucsrc, UCSZ0);
		SET_BIT(ucsrc, UCSZ1);
		CLR_BIT(UCSRB, UCSZ2);
		break;
		
		case UART_NineDataBits:
		SET_BIT(ucsrc, UCSZ0);
		SET_BIT(ucsrc, UCSZ1);
		SET_BIT(UCSRB, UCSZ2);
		break;
		
		default:
		break;
	}
	
	switch(UART_cfg.ParityBits)
	{
		case UART_DisableParity:
		CLR_BIT(ucsrc, UPM0);
		CLR_BIT(ucsrc, UPM1);
		break;
		
		case UART_EvenParity:
		CLR_BIT(ucsrc, UPM0);
		SET_BIT(ucsrc, UPM1);
		break;
		
		case UART_OddParity:
		SET_BIT(ucsrc, UPM0);
		SET_BIT(ucsrc, UPM1);
		break;
		
		default:
		break;
	}
	
	switch(UART_cfg.StopBits)
	{
		case UART_OneStopBit:
		CLR_BIT(ucsrc, USBS);
		break;
		
		case UART_TwoStopBits:
		SET_BIT(ucsrc, USBS);
		break;
		
		default:
		break;
	}
	UCSRC = ucsrc;
	
	switch(UART_cfg.SpeedMode)
	{
		case UART_NormalSpeed:
		CLR_BIT(UCSRA, U2X);
		ubrr = (F_CPU/((u32)16*UART_cfg.BaudRate))-1;
		break;
		
		case UART_DoubleSpeed:
		SET_BIT(UCSRA, U2X);
		ubrr = (F_CPU/((u32)8*UART_cfg.BaudRate))-1;
		break;
		
		default:
		break;
	}
	
	
	// Baud rate Initialization
	UBRRL = (u8)(ubrr & 0x00FF);
	UBRRH = (u8)((ubrr>>8) & 0x000F);
}

void UART_SendData(u16 data)
{
	while(!READ_BIT(UCSRA, UDRE));
	if (READ_BIT(data, 8))
		SET_BIT(UCSRB, TXB8);
	else
		CLR_BIT(UCSRB, TXB8);
	UDR = (u8)(data & 0x00FF);
}

u16	 UART_ReceiveData()
{
	u16 data = 0;
	
	while (!READ_BIT(UCSRA, RXC));
	if (READ_BIT(UCSRB, RXB8))
		SET_BIT(data, 8);
	else
		CLR_BIT(data, 8);
	data |= UDR;
	
	return data;
}

void UART_SendNoBlock(u16 data)
{
	if (READ_BIT(data, 8))
		SET_BIT(UCSRB, TXB8);
	else
		CLR_BIT(UCSRB, TXB8);
	UDR = (u8)(data & 0x00FF);
}

u16	 UART_ReceiveNoBlock()
{
	u16 data = 0;
	
	if (READ_BIT(UCSRB, RXB8))
		SET_BIT(data, 8);
	else
		CLR_BIT(data, 8);
	data |= UDR;
	
	return data; 
}


void UART_TX_InterruptEnable()
{
	SET_BIT(UCSRB, TXCIE);	
}

void UART_TX_InterruptDisable()
{
	CLR_BIT(UCSRB, TXCIE);
}

void UART_TX_SetCallBack(CallBackPtr_type LocalPtr)
{
	UART_TX_FPtr = LocalPtr;
}

void UART_RX_InterruptEnable()
{
	SET_BIT(UCSRB, RXCIE);
}

void UART_RX_InterruptDisable()
{
	CLR_BIT(UCSRB, RXCIE);
}

void UART_RX_SetCallBack(CallBackPtr_type LocalPtr)
{
	UART_RX_FPtr = LocalPtr;
}

void UART_UDRE_InterruptEnable()
{
	SET_BIT(UCSRB, UDRIE);
}

void UART_UDRE_InterruptDisable()
{
	CLR_BIT(UCSRB, UDRIE);
}

void UART_UDRE_SetCallBack(CallBackPtr_type LocalPtr)
{
	UART_UDRE_FPtr = LocalPtr;
}

ISR(USART_RX_vect)
{
	if (UART_RX_FPtr)
		UART_RX_FPtr();
}

ISR(USART_UDRE_vect)
{
	if (UART_UDRE_FPtr)
		UART_UDRE_FPtr();
}

ISR(USART_TX_vect)
{
	if (UART_TX_FPtr)
		UART_TX_FPtr();
}