/*
 * GccApplication1.c
 *
 * Created: 12/2/2023 1:00:25 AM
 * Author : Mahmoud Khaled
 */ 

/*********************************************** Include Section *****************************************/
#include "SPI_Master.h"

	
/******************************************** Global declaration *****************************************/
extern u8 flag;

int main(void)
{
	/* Master */
	APP_Init();
	
	while(1)
	{
		if (!flag)
		{
			APP_UponRequestMode();
		}
		else
		{
			APP_FreeRunningMode();
		}
	}
}







