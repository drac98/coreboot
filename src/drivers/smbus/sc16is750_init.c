/* SPDX-License-Identifier: GPL-2.0-only */

#include "sc16is750_init.h"

void sc16is750_write_byte(uint8_t reg, unsigned char c)
{
	do_smbus_write_byte(CONFIG_FIXED_SMBUS_IO_BASE, \
		CONFIG_CONSOLE_I2C_SMBUS_SLAVE_ADDRESS, \
		reg, c);
}

// no parity, 1 stop bit, 8 bit word length, enable special register set
// Divisor values are set for 115200 baud rate
void sc16is750_init(void)
{
	// Enable special register set
	sc16is750_write_byte(REG_LCR << 3, 0b10000011);

	sc16is750_write_byte(REG_DLL << 3, 0x08);
	sc16is750_write_byte(REG_DLH << 3, 0x00);

	// Disable special register set
	sc16is750_write_byte(REG_LCR << 3, 0b00000011);
}
