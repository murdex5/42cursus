#include "so_long.h"


int	open_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Couldn't open the file\n");
		perror("So long");
		exit(1);
	}
	return (fd);
}

int	read_file(char *file, unsigned char *buffer)
{
	int fd;
	int read_bytes;

	fd = open_file(file);
	if (fd == -1)
		return (-1);
	read_bytes = read(fd, buffer, sizeof(buffer));
	if (read_bytes == -1)
	{
		close(fd);
		ft_printf("Couldn't read the file\n");
		perror("So long");
		exit(1);
	}
	close(fd);
	return (read_bytes);
}
