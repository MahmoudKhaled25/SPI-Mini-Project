/*
 * SPI_Slave.c
 *
 * Created: 7/12/2024 9:23:38 PM
 *  Author: Blu-Ray
 */ 
#include "SPI_Slave.h"

static u8 flag;
static u16 T, oldT;

void APP_Init(void)
{
	DIO_INIT();
	SPI_ServiceInit();
	LCD_INIT();
	ADC_Init(VREF_AVCC, ADC_SCALER_64);
	DIO_WritePin(TRIG, LOW);
	SEI();
}
void APP_MeasureSend(void)
{
	T=sensor_ReadTemp_LM35();
	SPI_SendU16(T);
	if (T!=oldT)
	{
		
		LCD_CLR();
		LCD_WRITE_NUM(T/10);
		LCD_WRITE_CHAR('.');
		LCD_WRITE_NUM(T%10);
		oldT=T;
	}
}
void APP_ThresholdTrigger(void)
{
	if (0==flag && T>=500)
	{
		DIO_WritePin(TRIG, HIGH);
		_delay_us(50);
		DIO_WritePin(TRIG, LOW);
		flag=1;
	}
	else if (1==flag && T < 500)
	{
		DIO_WritePin(TRIG, HIGH);
		_delay_us(50);
		DIO_WritePin(TRIG, LOW);
		flag=0;
	}
}