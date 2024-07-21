/*
 * SPI_Service.c
 *
 *  Author: Mahmoud Khaled
 */ 

#define F_CPU 8E6
#include <util/delay.h>
#include "SPI_Service.h"

void SPI_ServiceInit(void)
{
	SPI_Init();
	return;
}

u16 SPI_ReceiveU16(void)
{
	u16 num;
	u8 *ptr=(u8 *)(&num);
	
	SPI_SendReceive(SPI_DUMMY, ptr, 200);
	_delay_us(10);
	SPI_SendReceive(SPI_DUMMY, ptr, 200);
	_delay_us(10);
	SPI_SendReceive(SPI_DUMMY, ptr+1, 200);
	
	return num;
}



