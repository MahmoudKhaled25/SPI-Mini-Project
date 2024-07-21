/*
 * UART_cfg.h
 *
 * Created: 4/29/2024 11:03:14 PM
 *  Author: Blu-Ray
 */ 


#ifndef UART_CFG_H_
#define UART_CFG_H_

/************************************************** Include section **********************************************************/
#include "StdTypes.h"

/*************************************************** Macros section **********************************************************/
#define F_CPU 8E6

/************************************************** Typedef section **********************************************************/
typedef enum {
	UART_FiveDataBits,
	UART_SixDataBits,
	UART_SevenDataBits,
	UART_EightDataBits,
	UART_NineDataBits
	}UART_DataBits_type;
	
typedef enum {
	UART_DisableParity,
	UART_EvenParity,
	UART_OddParity
	}UART_Parity_type;

typedef enum {
	UART_OneStopBit,
	UART_TwoStopBits
	}UART_StopBits_type;
	
typedef enum {
	UART_NormalSpeed,
	UART_DoubleSpeed
	}UART_SpeedMode_type;

typedef u32 UART_BaudRate_type;

typedef struct {
	UART_DataBits_type	DataBits;
	UART_Parity_type	ParityBits;
	UART_StopBits_type	StopBits;
	UART_SpeedMode_type SpeedMode;
	UART_BaudRate_type	BaudRate;
	}UART_cfg_type;




#endif /* UART_CFG_H_ */