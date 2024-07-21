/*
 * SPI_Slave.h
 *
 * Created: 7/12/2024 9:23:22 PM
 *  Author: Blu-Ray
 */ 


#ifndef SPI_SLAVE_H_
#define SPI_SLAVE_H_

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
#include "Sensors.h"
#include "LCD_Interface.h"
#include "SPI_Service.h"

#define TRIG PINA0

void APP_Init(void);
void APP_MeasureSend(void);
void APP_ThresholdTrigger(void);

#endif /* SPI_SLAVE_H_ */