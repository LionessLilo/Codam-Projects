/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 13:30:40 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/03 16:56:54 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*fill_stash(int fd, char *stash)
{
	char	*next_stash;
	char	*temp;
	int		i;

	while (1)
	{
		i = 0;
		while (stash[i] && stash[i] != '\n')
			i++;
		if (stash[i] == '\n')
		{
			printf("found new line");
			break ;
		}
		next_stash = read_file(fd);
		if (!next_stash)
		{
			if (!stash)
				return (NULL);
			printf("EOF / nothing to return");
			break ;
		}
		temp = stash;
		stash = ft_strjoin(stash, next_stash);
		free(temp);
		free(next_stash);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*line_from_stash(int fd, char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
	{
		printf("found a NULL terminator at the start of line_from_stash");
		return (NULL);
	}
	stash = fill_stash(fd, stash);
	line = ft_calloc(ft_strlen(stash) + 1, sizeof(char));
	if (!line)
	{
		printf("Could not calloc line");
		return (NULL);
	}
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i++] = '\n';
		return (line);
	}
	return (line);
}

char	*read_file(int fd)
{
	char	*cup_buffer;
	int		bytes_read;
	char	*return_cup_buffer;

	cup_buffer = ft_calloc(BUFFER_SIZE +1, sizeof(char));
	if (!cup_buffer)
	{
		printf("could not malloc cup_buffer");
		return (NULL);
	}
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		if (bytes_read < 0)
		{
			printf("could not read file or is EOF");
			return (free(cup_buffer), NULL);
		}
		return (free(cup_buffer), NULL);
	}
	return_cup_buffer = ft_strdup(cup_buffer);
	return (free(cup_buffer), return_cup_buffer);
}

static char	*get_next_line(int fd)
{
	char			*line;
	static char		*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		printf("fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0");
		return (NULL);
	}
	if (!stash)
		stash = read_file(fd);
	line = line_from_stash(fd, stash);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("read_file.txt", O_RDONLY);
	if (fd < 0)
	{
		return ((long int) NULL);
	}
	next_line = get_next_line(fd);
	printf("%s", next_line);
	return (0);
}
