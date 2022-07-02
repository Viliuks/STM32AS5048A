/*
 * AS5048A.h
 *
 *  Created on: Jun 1, 2022
 *      Author: Vilius
 */

#ifndef INC_AS5048A_H_
#define INC_AS5048A_H_

#include "stm32g0xx_hal.h"
#include "math.h"

#define CS_ON() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET) // change pins
#define CS_OFF() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET) // change pins

#define AS5048A_Read_NOP 0xc000
#define AS5048A_Read_Clear_Error_Flag 0x4001
#define AS5048A_Read_Angle 0xffff
#define AS5048A_CPR 16384

void AS5048A_Init(SPI_HandleTypeDef *handle);
float AS5048A_GetAngle();
float AS5048A_GetAngleDeg();
uint16_t AS5048A_GetRaw();
uint16_t AS5048A_GetRotation();

#endif /* INC_AS5048A_H_ */
