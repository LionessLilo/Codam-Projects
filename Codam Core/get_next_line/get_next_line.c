/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/08 13:05:32 by lilo          #+#    #+#                 */
/*   Updated: 2024/11/10 15:57:37 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#define BUFFER_SIZE 10

char	*get_next_line(int fd)
{
	char	chars_read;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (buffer == NULL)
		return (NULL);
}

int	main(void)
{
	int		fd = open("read_file.txt", O_RDWR);
	char	buffer[256];
	char	chars_read;
	int		count;

	count = 0;
	while(chars_read = read(fd, buffer, 10))
	{
		buffer[chars_read] = '\0';
		count++;
		printf("%d. %s\n", count, buffer);
	}
	return (0);
}