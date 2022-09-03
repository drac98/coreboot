/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef I2C_TO_UART_H
#define I2C_TO_UART_H

#include <console/i2c_smbus.h>
#include <device/i2c.h>
#include <device/smbus_host.h>
#include <southbridge/intel/bd82x6x/pch.h>

#define REG_THR 0x00
#define REG_LCR 0x03

// Special Register Set is accessible only when LCR[7] is logic 1.
#define REG_DLL 0x00
#define REG_DLH 0x01

#define CLOLK_FREQUENCY 14745600	// 14.7 MHz
#define BAUD 			115200
#define PRESCALER 		1			//  The default value of prescaler after reset is 1.

void sc16is750_write_byte(uint8_t reg, unsigned char c);
void sc16is750_init(void);

#endif /* I2C_TO_UART_H */
