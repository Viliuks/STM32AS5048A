# Simple AS5048A SPI library for the STM32G0

This is a simple AS5048A library written in C, which uses STM32G0 HAL to communicate with the sensor via SPI.

When using this library please change the CS pins in the header file.
## Example usage
```C
SPI_HandleTypeDef hspi2;

AS5048A_Init(&hspi2);
float angleRads = AS5048A_GetAngle();
float angleDeg = AS5048A_GetAngleDeg();
```