/*
 * UART_cfg.c
 *
 * Created: 4/29/2024 11:03:27 PM
 *  Author: Mahmoud Khaled
 */ 

#include "UART_cfg.h"

const UART_cfg_type UART_cfg = {
	.DataBits	=	UART_EightDataBits,
	.ParityBits	=	UART_DisableParity,
	.StopBits	=	UART_OneStopBit,
	.SpeedMode	=	UART_NormalSpeed,
	.BaudRate	=	9600
};