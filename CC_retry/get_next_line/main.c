#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;

	fd = open("./text1.txt", O_RDONLY);
	if (fd < 0)
		return (printf("Could not open file"), -1);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}