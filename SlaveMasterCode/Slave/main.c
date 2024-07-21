/*
 * GccApplication1.c
 *
 * Created: 12/2/2023 1:00:25 AM
 * Author : Mahmoud Khaled
 */ 

/*********************************************** Include Section *****************************************/
#include "SPI_Slave.h"

int main(void)
{
	/* Slave */
	APP_Init();
	
    while (1) 
    {
		APP_MeasureSend();
		APP_ThresholdTrigger();
	}
}