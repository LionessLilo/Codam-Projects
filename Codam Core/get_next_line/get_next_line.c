/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 13:05:32 by lilo          #+#    #+#                 */
/*   Updated: 2024/11/14 14:45:02 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

static char	*read_file(int fd)
{
	char	chars_read;
	char	*cup_buffer;

	cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	chars_read = read(fd, cup_buffer, BUFFER_SIZE);
	if (chars_read <= 0)
	{
		free (cup_buffer);
		return (NULL);
	}
	return (cup_buffer);
}

char	*get_next_line(int fd)
{
	char	*tank_buffer;

	tank_buffer = read_file(fd);
	return (tank_buffer);
}

int	main(void)
{
	int		fd;
	char	*next_line;
	int		count;

	count = 0;
	fd = open("read_file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Could not open file");
		return (1);
	}
	while (1)
	{
		next_line = get_next_line(fd);
		if (!next_line)
			return (1);
		count++;
		printf("[%d]:%s\n", count, next_line);
		free (next_line);
		next_line = NULL;
	}
	close(fd);
	return (0);
}
