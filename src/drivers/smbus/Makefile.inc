ifeq ($(CONFIG_CONSOLE_I2C_SMBUS),y)
bootblock-y += i2c_smbus_console.c
romstage-y += i2c_smbus_console.c
ramstage-y += i2c_smbus_console.c
endif