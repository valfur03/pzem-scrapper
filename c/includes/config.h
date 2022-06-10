#ifndef CONFIG_H
# define CONFIG_H

typedef struct	s_config
{
	int				argc;
	char			**argv;
	modbus_t		*mb;
	char			*serial_file_name;
	unsigned int	baudrate;
	char			parity;
	int				data_bit;
	int				stop_bit;
}				t_config;

#endif