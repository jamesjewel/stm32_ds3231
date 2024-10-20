/*
 * ds3231.h
 *
 *  Created on: Sep 4, 2024
 *      Author: Jewel James
 */

#ifndef INC_DS3231_H_
#define INC_DS3231_H_

#include "main.h"

#define DS3231_I2C_ADDR 	0x68

#define DS3231_REG_SECOND 	0x00
#define DS3231_REG_MINUTE 	0x01
#define DS3231_REG_HOUR  	0x02
#define DS3231_REG_DOW    	0x03

#define DS3231_REG_DATE   	0x04
#define DS3231_REG_MONTH  	0x05
#define DS3231_CENTURY 		7
#define DS3231_REG_YEAR   	0x06

#define DS3231_TEMP_MSB		0x11
#define DS3231_TEMP_LSB		0x12

#define DS3231_TIMEOUT		2000

typedef struct DateTime {
	uint8_t day;
	uint8_t month;
	uint8_t dow;
	uint8_t year;
	uint8_t hr;
	uint8_t min;
	uint8_t sec;
} DateTime;

/**
 * @defgroup	DS3231_USER_FUNCTIONS
 * @brief		Functions for the user to define
 * @{
 */
void ds3231_i2c_tx(uint8_t* buff, uint8_t size);
void ds3231_i2c_rx(uint8_t* buff, uint8_t size);
/**
 * }
 */

/**
 * @defgroup	DS3231_LIB_FUNCTIONS
 * @brief		Main library functions
 * @{
 */
void ds3231_init();
void ds3231_settime(DateTime* dt);
void ds3231_gettime(DateTime* dt);
float ds3231_gettemp();
/**
 * }
 */

#endif /* INC_DS3231_H_ */
