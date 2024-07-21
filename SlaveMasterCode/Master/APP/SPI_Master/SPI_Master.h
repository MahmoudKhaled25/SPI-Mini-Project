/*
 * SPI_Comm.h
 *
 * Created: 7/12/2024 9:08:01 PM
 *  Author: Blu-Ray
 */ 


#ifndef SPI_COMM_H_
#define SPI_COMM_H_

#define F_CPU 8E6
#include <util/delay.h>
#include "MemoryMap.h"
#include "Utilities.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "NVM_Interface.h"
#include "EX_Interrupt.h"
#include "Timer0.h"
#include "Timer1.h"
#include "Timer2.h"
#include "UART.h"
#include "SPI.h"
#include "LCD_Interface.h"
#include "SPI_Service.h"

#define BUTTON PINA0

void APP_Init(void);
void APP_FreeRunningMode(void);
void APP_UponRequestMode(void);




#endif /* SPI_COMM_H_ */