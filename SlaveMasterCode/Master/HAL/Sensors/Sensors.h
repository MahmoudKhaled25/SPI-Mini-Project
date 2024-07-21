/*
 * sensors.h
 *
 * Created: 3/17/2024 3:08:55 AM
 *  Author: Blu-Ray
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_

/*********************************************** Include Section *****************************************/
#include "ADC_Interface.h"
#include "StdTypes.h"

/********************************************* Macros Section ********************************************/
#define SENSOR_LM35_CH       CH_0
#define SENSOR_MPX4115_CH    CH_1
#define SENSOR_MPX4250_CH    CH_2

/*********************************************** Function declaration ************************************/

u16 sensor_ReadTemp_LM35(void);
u16 sensor_ReadPressure_MPX4115(void);
u16 sensor_ReadPressure_MPX4250(void);


#endif /* SENSORS_H_ */