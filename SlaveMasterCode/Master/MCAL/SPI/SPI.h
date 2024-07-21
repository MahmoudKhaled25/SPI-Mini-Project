/*
 * SPI.h
 *
 * Created: 5/12/2024 5:55:25 PM
 *  Author: Blu-Ray
 */ 


#ifndef SPI_H_
#define SPI_H_
/************************************************** Include section **********************************************************/
#include "StdTypes.h"
#include "MemoryMap.h"
#include "Utilities.h"
#include "SPI_cfg.h"

/************************************************ Function declaration *******************************************************/
void SPI_Init(void);
Error_return SPI_SendReceive(u8 data, u8 *Pdata, u16 time_us);
Error_return SPI_ReceivePeriodic(u8 *Pdata);
void SPI_SendNoBlock(u8 data);
u8 SPI_ReceiveNoBlock(void);

void SPI_STC_InterruptEnable(void);
void SPI_STC_InterruptDisable(void);
void SPI_STC_SetCallBack(CallBackPtr_type LocalPtr);
#endif /* SPI_H_ */