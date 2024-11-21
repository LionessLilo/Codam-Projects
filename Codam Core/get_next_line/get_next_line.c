/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/19 13:02:27 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/21 10:56:51 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*read_file(int fd)
{
	char	*cup_buffer;
	int		bytes_read;

	cup_buffer = ft_calloc(BUFFER_SIZE +1, sizeof(char));
	if (!cup_buffer)
	{
		printf("could not malloc cup_buffer");
		return (free(cup_buffer), NULL);
	}
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		printf("could not read file");
		return (free(cup_buffer), NULL);
	}
	return (cup_buffer);
}

static char	*get_next_line(int fd)
{
	static char	*buffer;
	// char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd);
	if (!buffer)
		return (NULL);
	return (buffer);
}

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("read_file.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Could not open file");
		return ((long int) NULL);
	}
	next_line = get_next_line(fd);
	printf("%s", next_line);
	return (0);
}
