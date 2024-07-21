/*
 * SPI.c
 *
 * Created: 5/12/2024 5:55:43 PM
 *  Author: Blu-Ray
 */ 

#define F_CPU 8E6
#include <util/delay.h>
#include "SPI.h"

extern SPI_cfg_type SPI_cfg;

CallBackPtr_type SPI_STC_FPtr = NULLPTR;


void SPI_Init(void)
{
	SPCR = ((SPI_cfg.mode & 0x01) << MSTR) | ((SPI_cfg.order & 0x01) << DORD) | ((SPI_cfg.polarity & 0x01) << CPOL) | ((SPI_cfg.phase & 0x01) << CPHA);
	SPCR |= 0x03 & SPI_cfg.scaler;
	SPSR |= 0x01 & (SPI_cfg.scaler >> 2);
	SET_BIT(SPCR, SPE);
}

Error_return SPI_SendReceive(u8 data, u8 *Pdata, u16 time_us)
{
	Error_return ret=NOK;
	
	SPDR = data;
	while (!READ_BIT(SPSR, SPIF) && time_us)
	{
		time_us--;
		_delay_us(1);
	}
	
	if (time_us)
	{
		ret = OK;
		*Pdata = SPDR;
	}
	
	return ret;
}

Error_return SPI_ReceivePeriodic(u8 *Pdata)
{
	Error_return ret=NOK;
	
	if(READ_BIT(SPSR, SPIF))
	{
		*Pdata=SPDR;
		ret = OK;
	}
	
	return ret;
}

void SPI_SendNoBlock(u8 data)
{
	SPDR = data;
}

u8 SPI_ReceiveNoBlock(void)
{
	return SPDR;
}

void SPI_STC_InterruptEnable(void)
{
	SET_BIT(SPCR, SPIE);
}

void SPI_STC_InterruptDisable(void)
{
	CLR_BIT(SPCR, SPIE);
}

void SPI_STC_SetCallBack(CallBackPtr_type LocalPtr)
{
	SPI_STC_FPtr = LocalPtr;
}

ISR(SPI_STC_vect)
{
	if (SPI_STC_FPtr)
		SPI_STC_FPtr();
}