#include <stdio.h>
#include <unistd.h>
#include "config.h"

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
	if (load_config(&config) < 0)
		return 1;
	close(config.serial_fd);
	return 0;
}