#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <modbus/modbus.h>
#include "config.h"

int	read_and_print_data(t_config *config)
{
	uint16_t	reg[10];

	if (modbus_read_input_registers(config->mb, 0, 10, reg) < 0)
	{
		printf("%s: %s\n", config->argv[0], strerror(errno));
		return -1;
	}
	printf("Voltage: %.1fV\n", reg[0] / 10.0);
	printf("Power: %.1fW\n", (reg[3] + (reg[4] << 16)) / 10.0);
	return 0;
}

int	main(int argc, char **argv)
{
	t_config	config;

	if (argc < 1)
	{
		printf("Not enough arguments...\n");
		return 1;
	}
	config.argc = argc;
	config.argv = argv;
	config.serial_file_name = "/dev/ttyUSB0";
	config.baudrate = 9600;
	config.parity = 'N'; // No parity bit
	config.data_bit = 8;
	config.stop_bit = 1;
	config.mb = modbus_new_rtu(config.serial_file_name, config.baudrate, config.parity, config.data_bit, config.stop_bit);
	if (config.mb == NULL)
	{
		printf("%s: %s\n", config.argv[0], strerror(errno));
		return -1;
	}
	if (modbus_set_slave(config.mb, 1) < 0 || modbus_connect(config.mb) < 0)
	{
		printf("%s: %s\n", config.argv[0], strerror(errno));
		modbus_free(config.mb);
		return -1;
	}

	read_and_print_data(&config);

	modbus_close(config.mb);
	modbus_free(config.mb);
	return 0;
}
