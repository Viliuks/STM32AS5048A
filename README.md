# Simple AS5048A SPI library for the STM32G0
This is a simple AS5048A High-Resolution Position Sensor library written in C.
It uses STM32G0 HAL to communicate with the sensor via SPI, can be modified to work with other HAL libraries.

When using this library please change the CS pins in the header file.


## Example usage
```C
SPI_HandleTypeDef hspi2;

AS5048A_Init(&hspi2);
float angleRads = AS5048A_GetAngle();
float angleDeg = AS5048A_GetAngleDeg();
```

### SPI settings

| Setting | Value |
| ------------- | ------------------- |
| Frame Format  | Motorola            |
| Data Size     | 16 bits             |
| Prescaler     | 32 (2.0MBits/s baud)|
| CPOL          | Low                 |
| CPHA          | 2 Edge              |
| CRC           | Disabled            |
