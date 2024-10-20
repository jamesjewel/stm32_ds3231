/*
 * ds3231.c
 *
 *  Created on: Sep 4, 2024
 *      Author: Jewel James
 */

I2C_HandleTypeDef *_ds3231_hi2c;

/* Internal funcs */
uint8_t _ds3231_decodeBCD(uint8_t bcd);
uint8_t _ds3231_encodeBCD(uint8_t dec);
void _ds3231_setreg(uint8_t addr, uint8_t val);
uint8_t _ds3231_getreg(uint8_t addr);

/**
 * @brief Set the byte in the designated DS3231 register to value.
 * @param addr Register address to write.
 * @param val Value to set, 0 to 255.
 */
void _ds3231_setreg(uint8_t addr, uint8_t val) {
	uint8_t bytes[2] = { addr, val };
	HAL_I2C_Master_Transmit(_ds3231_ui2c, DS3231_I2C_ADDR << 1, bytes, 2, DS3231_TIMEOUT);
}

/**
 * @brief Gets the byte in the designated DS3231 register.
 * @param addr Register address to read.
 * @return Value stored in the register, 0 to 255.
 */
uint8_t _ds3231_getreg(uint8_t addr) {
	uint8_t val;
	HAL_I2C_Master_Transmit(_ds3231_ui2c, DS3231_I2C_ADDR << 1, &addr, 1, DS3231_TIMEOUT);
	HAL_I2C_Master_Receive(_ds3231_ui2c, DS3231_I2C_ADDR << 1, &val, 1, DS3231_TIMEOUT);
	return val;
}

/**
 * @brief Decodes the raw binary value stored in registers to decimal format.
 * @param bin Binary-coded decimal value retrieved from register, 0 to 255.
 * @return Decoded decimal value.
 */
uint8_t _ds3231_decodeBCD(uint8_t bcd) {
	return (((bcd & 0xf0) >> 4) * 10) + (bcd & 0x0f);
}

/**
 * @brief Encodes a decimal number to binaty-coded decimal for storage in registers.
 * @param dec Decimal number to encode.
 * @return Encoded binary-coded decimal value.
 */
uint8_t _ds3231_encodeBCD(uint8_t dec) {
	return (dec % 10 + ((dec / 10) << 4));
}

void ds3231_gettime(DateTime *dt) {
	DateTime* d = &dt;
	d.day =

}
