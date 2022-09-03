ifeq ($(CONFIG_SC16IS750_INIT),y)
bootblock-y += sc16is750_init.c
romstage-y += sc16is750_init.c
endif

ifeq ($(CONFIG_CONSOLE_I2C_SMBUS),y)
bootblock-y += i2c_smbus_console.c
romstage-y += i2c_smbus_console.c
ramstage-y += i2c_smbus_console.c
endif