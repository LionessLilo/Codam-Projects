/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 09:29:21 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/10 10:41:57 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*leftover_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (ft_free(&stash), NULL);
	line = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	if (!line)
		return (ft_free(&stash), NULL);
	i++;
	while (stash[i] != '\0')
		line[j++] = stash[i++];
	line[j] = '\0';
	free(stash);
	return (line);
}

char	*get_the_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != 0 && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc((i + 2), sizeof(char));
	else
		line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != 0 && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

int	buffercheck(char **buffer)
{
	if (!*buffer)
	{
		*buffer = ft_calloc(1, 1);
		if (!*buffer)
			return (1);
		return (0);
	}
	return (0);
}

char	*read_file_fill_stash(int fd, char *stash)
{
	char	*cup_buffer;
	char	*temp;
	int		chars_read;

	if (buffercheck(&stash))
		return (NULL);
	cup_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!cup_buffer)
		return (free(stash), NULL);
	chars_read = 1;
	while (chars_read > 0 && !ft_strchr(cup_buffer, '\n'))
	{
		chars_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (chars_read == -1)
			return (free(cup_buffer), free(stash), NULL);
		cup_buffer[chars_read] = 0;
		temp = ft_strjoin(stash, cup_buffer);
		if (!temp)
			return (free(cup_buffer), free(stash), NULL);
		free(stash);
		stash = temp;
	}
	ft_free(&cup_buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_free(&stash);
		return (NULL);
	}
	stash = read_file_fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	if (*stash == '\0')
	{
		ft_free(&stash);
		return (NULL);
	}
	line = get_the_line(stash);
	if (!line)
		return (ft_free(&stash), NULL);
	stash = leftover_line(stash);
	return (line);
}
