/* SPDX-License-Identifier: GPL-2.0-only */

#include <console/i2c_smbus.h>
#include <device/i2c.h>
#include <device/smbus_host.h>
#include <southbridge/intel/bd82x6x/pch.h>

void i2c_smbus_console_init(void)
{
#if (CONFIG(CONSOLE_I2C_SMBUS) && (ENV_ROMSTAGE || ENV_BOOTBLOCK))
	early_pch_init();
#endif
}

void i2c_smbus_console_tx_byte(unsigned char c)
{
#if (CONFIG(CONSOLE_I2C_SMBUS) && (ENV_BOOTBLOCK || ENV_ROMSTAGE || ENV_RAMSTAGE))
	do_smbus_write_byte(CONFIG_FIXED_SMBUS_IO_BASE, \
		CONFIG_CONSOLE_I2C_SMBUS_SLAVE_ADDRESS, \
		CONFIG_CONSOLE_I2C_SMBUS_SLAVE_DATA_REGISTER, c);
#endif
}
