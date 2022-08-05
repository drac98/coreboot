/* SPDX-License-Identifier: GPL-2.0-only */

#include <console/i2c_smbus.h>
#include <device/i2c.h>
#include <device/smbus_host.h>

void i2c_smbus_console_init(void)
{
	// i2c_init();
}

void i2c_smbus_console_tx_byte(unsigned char c)
{
	smbus_write_byte(0x48, 0x0, c);
}
