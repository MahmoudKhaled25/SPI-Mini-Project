/*
 * SPI_Service.c
 *
 *  Author: Mahmoud Khaled
 */ 

#include "SPI_Service.h"

static u16 num16;

static void SPI_TX(void);

void SPI_ServiceInit(void)
{
	SPI_Init();
	SPI_STC_InterruptEnable();
	SPI_STC_SetCallBack(SPI_TX);
	return;
}

void SPI_SendU16(u16 num)
{
	num16=num;
}

static void SPI_TX(void)
{
	static u16 num=0;
	static u8 counter=0, flag=1;
	u8 *ptr=(u8 *)(&num);

	if (flag)
	{
		if (0==counter)
		{
			num=num16;
		}
		SPI_SendNoBlock(ptr[counter++]);
		if (2==counter)
		{
			counter=0;
			flag=0;
		}
	}
	else
	{
		flag=1;
	}
}

