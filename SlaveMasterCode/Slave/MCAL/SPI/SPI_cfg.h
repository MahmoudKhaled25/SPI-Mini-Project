/*
 * SPI_cfg.h
 *
 * Created: 5/12/2024 5:59:24 PM
 *  Author: Blu-Ray
 */ 


#ifndef SPI_CFG_H_
#define SPI_CFG_H_


/************************************************** Include section **********************************************************/
#include "StdTypes.h"

/*************************************************** Macro section ***********************************************************/
#define SPI_DUMMY '@'

/************************************************** Typedef section **********************************************************/
typedef enum {
	SPI_SLAVE,
	SPI_MASTER
}SPI_Mode_type;

typedef enum {
	SPI_MSB_FIRST,
	SPI_LSB_FIRST
}SPI_DataOrder_type;

typedef enum {
	SPI_RISING_FALLING,
	SPI_FALLING_RISING
}SPI_ClockPolarity_type;

typedef enum {
	SPI_SAMPLE_SETUP,
	SPI_SETUP_SAMPLE
}SPI_ClockPhase_type;

typedef enum {
	SPI_SCALER_4,
	SPI_SCALER_16,
	SPI_SCALER_64,
	SPI_SCALER_128,
	SPI_SCALER2X_2,
	SPI_SCALER2X_8,
	SPI_SCALER2X_32,
	SPI_SCALER2X_64
}SPI_Scaler_type;

typedef struct {
	SPI_Mode_type			mode;
	SPI_DataOrder_type		order;
	SPI_ClockPolarity_type  polarity;
	SPI_ClockPhase_type		phase;
	SPI_Scaler_type			scaler;
}SPI_cfg_type;

#endif /* SPI_CFG_H_ */