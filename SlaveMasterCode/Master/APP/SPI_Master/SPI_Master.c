/*
 * SPI_Comm.c
 *
 * Created: 7/12/2024 9:08:16 PM
 *  Author: Blu-Ray
 */ 

#include "SPI_Master.h"

u16 rec, recOld;
volatile u8 flag;

static void f(void);

void APP_Init(void)
{
	DIO_INIT();
	SPI_ServiceInit();
	LCD_INIT();
	EXI_Init();
	EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT0, EXI_FALLING_EDGE);
	EXI_SetCallBack(EX_INT0, f);
	SEI();
}

void APP_FreeRunningMode(void)
{
	rec=SPI_ReceiveU16();
	if(rec!=recOld)
	{
		LCD_CLR();
		LCD_WRITE_NUM(rec/10);
		LCD_WRITE_CHAR('.');
		LCD_WRITE_NUM(rec%10);
		recOld=rec;
	}
}

void APP_UponRequestMode(void)
{
	if (DIO_ReadPin(BUTTON)==LOW)
	{
		rec=SPI_ReceiveU16();
		LCD_CLR();
		LCD_WRITE_NUM(rec/10);
		LCD_WRITE_CHAR('.');
		LCD_WRITE_NUM(rec%10);
		while(DIO_ReadPin(BUTTON)==LOW);
	}
}

static void f(void)
{
	flag=!flag;
}
