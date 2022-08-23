/* SPDX-License-Identifier: GPL-2.0-only */

#include <console/i2c_smbus.h>
#include <device/i2c.h>
#include <device/smbus_host.h>
#include <southbridge/intel/bd82x6x/pch.h>

void i2c_smbus_console_init(void)
{
#if (CONFIG(CONSOLE_SERIAL) && ENV_ROMSTAGE)
	early_pch_init();
#endif
}

void i2c_smbus_console_tx_byte(unsigned char c)
{
#if (CONFIG(CONSOLE_SERIAL) && ENV_ROMSTAGE)
	smbus_write_byte(0x48, 0x0, c);
#endif

#if (CONFIG(CONSOLE_SERIAL) && ENV_RAMSTAGE)
	do_smbus_write_byte(CONFIG_FIXED_SMBUS_IO_BASE, 0x48, 0x0, c);
#endif

}
