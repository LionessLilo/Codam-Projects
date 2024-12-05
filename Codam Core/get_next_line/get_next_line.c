/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 13:30:40 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/05 15:18:05 by llourens      ########   odam.nl         */
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
	int		i;

	while (1)
	{
		i = 0;
		while (stash[i] && stash[i] != '\n')
			i++;
		if (stash[i] == '\n')
			break ;
		next_stash = read_file(fd);
		if (!next_stash)
		{
			if (!stash)
				return (NULL);
			break ;
		}
		stash = ft_strjoin(stash, next_stash);
		free(next_stash);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*line_from_stash(int fd, char **stash)
{
	char	*line;
	char	*local_stash;
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	if (!stash[i])
		return (NULL);
	local_stash = fill_stash(fd, *stash);
	line = ft_calloc(ft_strlen(local_stash) + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (local_stash[i] && local_stash[i] != '\n')
	{
		line[i] = local_stash[i];
		i++;
	}
	if (local_stash[i] == '\n')
		line[i] = '\n';
	if (local_stash[i] == '\n')
	{
		i++;
		j = i;
		new_stash = ft_calloc(((ft_strlen(local_stash) - j) + 1), sizeof(char));
		while (local_stash[i])
		{
			new_stash[i - j] = local_stash[i];
			i++;
		}
		new_stash[i] = '\0';
		*stash = new_stash;
	}
	else
		*stash = NULL;
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
		return (free(cup_buffer), NULL);
	return_cup_buffer = ft_strdup(cup_buffer);
	return (free(cup_buffer), return_cup_buffer);
}

static char	*get_next_line(int fd)
{
	char			*line;
	char			*line_from_file;
	static char		*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		printf("fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0");
		return (NULL);
	}
	if (!stash)
	{
		stash = NULL;
	}
	line_from_file = read_file(fd);
	if (!line_from_file)
	{
		line_from_file = "";
	}
	stash = ft_strjoin(stash, line_from_file);
	line = line_from_stash(fd, &stash);
	return (line);
}

int main(void)
{
    int fd;
    char *line;

    // Open the file for reading
    fd = open("read_file.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);  // Return error code if file can't be opened
    }

    // Read and print each line until the end of the file
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);  // Print the line
        free(line);  // Free the memory allocated for the line after printing
    }

    // Close the file
    if (close(fd) < 0)
    {
        perror("Error closing file");
        return (1);  // Return error code if file can't be closed
    }

    return (0);  // Return success code
}