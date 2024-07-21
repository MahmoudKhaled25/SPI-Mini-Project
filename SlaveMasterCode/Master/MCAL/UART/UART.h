/*
 * UART.h
 *
 * Created: 4/29/2024 10:56:30 PM
 *  Author: Blu-Ray
 */ 


#ifndef UART_H_
#define UART_H_

/************************************************** Include section **********************************************************/
#include "StdTypes.h"
#include "UART_cfg.h"

/************************************************ Function declaration *******************************************************/
void UART_Init();
void UART_SendData(u16 data);
u16	 UART_ReceiveData();
void UART_SendNoBlock(u16 data);
u16	 UART_ReceiveNoBlock();

void UART_TX_InterruptEnable();
void UART_TX_InterruptDisable();
void UART_TX_SetCallBack(CallBackPtr_type LocalPtr);

void UART_RX_InterruptEnable();
void UART_RX_InterruptDisable();
void UART_RX_SetCallBack(CallBackPtr_type LocalPtr);

void UART_UDRE_InterruptEnable();
void UART_UDRE_InterruptDisable();
void UART_UDRE_SetCallBack(CallBackPtr_type LocalPtr);

#endif /* UART_H_ */