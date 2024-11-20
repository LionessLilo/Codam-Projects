/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 13:05:32 by lilo          #+#    #+#                 */
/*   Updated: 2024/11/20 10:01:58 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

	fd = open("read_file.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Could not open file");
		return (-1);
	}
	next_line = get_next_line(fd);
	printf("%s", next_line);
	return (0);
}
