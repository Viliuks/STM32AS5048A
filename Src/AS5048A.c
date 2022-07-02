/*
 * AS5048A.c
 *
 *  Created on: Jun 1, 2022
 *      Author: Vilius
 */

#include "AS5048A.h"
#define PI 3.1415926535897932384626433832795
#define _2PI 6.28318530718

SPI_HandleTypeDef *spiDef;
uint16_t TX[4] = { 0 };
uint16_t RX[4] = { 0 };
uint16_t post_process_value;

void AS5048A_Init(SPI_HandleTypeDef *handle) {
	spiDef = handle;
}

/**
 * Gets the current angle in radians
 */
float AS5048A_GetAngle() {
	return ((float) AS5048A_GetRaw()) / (float) AS5048A_CPR * 2.0f * PI;
}

/**
 * Gets the current angle in degrees
 */
float AS5048A_GetAngleDeg() {
	return AS5048A_GetRaw() * ((float) 360 / AS5048A_CPR);
}

/**
 * Gets RAW data from sensor
 */
uint16_t AS5048A_GetRaw() {
	CS_ON();
	uint16_t command1[1] = { AS5048A_Read_Angle };
	uint16_t result[1] = { 0 };
	HAL_StatusTypeDef status1 = HAL_SPI_TransmitReceive(spiDef, command1,
			result, 1, 10);
	CS_OFF();
	HAL_Delay(1);
	CS_ON();
	uint16_t command2[1] = { AS5048A_Read_NOP };
	HAL_StatusTypeDef status2 = HAL_SPI_TransmitReceive(spiDef, command2,
			result, 1, 10);
	CS_OFF();
	return result[0] & 0x3fff;
}
