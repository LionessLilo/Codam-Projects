/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/19 13:02:27 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/19 15:24:33 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = readandfill_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
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
