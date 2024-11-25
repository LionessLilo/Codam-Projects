/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/19 13:02:27 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/25 10:11:09 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*find_line(int fd, char *stash)
{
	int		i;
	char	*temp;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	temp = ft_calloc(i + 2, sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		temp[i] = stash[i];
		i++;
	}
	while (!stash[i])
	{
		new_stash = read_file(fd);
		while (new_stash)
		{
			stash = ft_strjoin(stash, new_stash);
			if (!new_stash)
				return (free(new_stash), NULL);
			i = 0;
			while (stash[i] && stash[i] != '\n')
			{
				temp[i] = stash[i];
				i++;
			}
			if (stash[i] == '\n')
			{
				temp[i++] = '\n';
				temp[i] = '\0';
				return (temp);
			}
			new_stash = read_file(fd);
		}
	}
	return (temp);
}

static char	*get_next_line(int fd)
{
	static char	*stash;
	static char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
        stash = read_file(fd);
	line = find_line(fd, stash);
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
