#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "config.h"

int	load_config(t_config *config)
{
	config->serial_fd = open(config->serial_file_name, O_RDWR);
	if (config->serial_fd < 0)
	{
		printf("%s: %s: %s\n", config->argv[0], strerror(errno), config->serial_file_name);
		return -1;
	}
	return 0;
}