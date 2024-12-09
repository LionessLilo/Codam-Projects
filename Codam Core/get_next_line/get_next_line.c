/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 13:30:40 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/09 13:53:40 by llourens      ########   odam.nl         */
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
		if (!*stash && *stash != '\n')
			break ;
		while (stash[i] && stash[i] != '\n')
			i++;
		if (stash[i] == '\n')
			break ;
		next_stash = read_file(fd);
		if (next_stash == NULL)
			break ;
		if (!next_stash)
			break ;
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
	if (!*stash)
		return (NULL);
	local_stash = fill_stash(fd, *stash);
	line = ft_calloc(ft_strlen(local_stash) + 1, sizeof(char));
	if (!line)
	{
		free(local_stash);
		return (NULL);
	}
	while (local_stash[i] && local_stash[i] != '\n')
	{
		line[i] = local_stash[i];
		i++;
	}
	if (local_stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
		j = i;
		new_stash = ft_calloc(((ft_strlen(local_stash) - j) + 1), sizeof(char));
		if (!new_stash)
			return (free(local_stash), free(line), NULL);
		while (local_stash[i])
		{
			new_stash[i - j] = local_stash[i];
			i++;
		}
		new_stash[i - 1] = '\0';
		*stash = new_stash;
		free(local_stash);
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
		return (NULL);
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(cup_buffer);
		return (NULL);
	}
	return_cup_buffer = ft_strdup(cup_buffer);
	free(cup_buffer);
	return (return_cup_buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*line_from_file;
	static char		*stash;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	line_from_file = read_file(fd);
	if (!line_from_file)
		return (NULL);
	if (line_from_file)
	{
		temp = ft_strjoin(stash, line_from_file);
		free(stash);
		free(line_from_file);
		stash = temp;
	}
	line = line_from_stash(fd, &stash);
	if (!line && stash)
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}

// int main() 
// {
//     int fd;
//     char *line;

//     fd = open("read_file.txt", O_RDONLY);
//     if (fd == -1) {
//         perror("Error opening file");
//         return 1;
//     }

//     // Loop to read and print lines until the end of the file
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("%s", line);
//         free(line);  // Don't forget to free the memory after each line
//     }

//     // Close the file descriptor after finishing reading
//     close(fd);

//     return 0;
// }

// Think of if there is no new line in the first call. 
// Only need to free stash when there is EOF so can get away with less mallocs. 
