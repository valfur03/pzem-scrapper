#ifndef CONFIG_H
# define CONFIG_H

typedef struct	s_config
{
	int		argc;
	char	**argv;
	char	*serial_file_name;
	int		serial_fd;
}				t_config;

int	load_config(t_config *config);

#endif