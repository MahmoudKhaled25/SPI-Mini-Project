/*
 * SPI_cfg.c
 *
 * Created: 5/12/2024 5:59:08 PM
 *  Author: Blu-Ray
 */ 

#include "SPI_cfg.h"

const SPI_cfg_type SPI_cfg = {
	.mode		=	SPI_MASTER,
	.order	    =	SPI_MSB_FIRST,
	.polarity	=	SPI_RISING_FALLING,
	.phase		=	SPI_SETUP_SAMPLE,
	.scaler		=	SPI_SCALER_4,
};