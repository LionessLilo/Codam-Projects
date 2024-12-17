/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:26:21 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/17 13:16:16 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	ft_free(char **memory)
{
	if (*memory)
	{
		free(*memory);
		*memory = NULL;
	}
}

char	*leftover_stash(char *stash)
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
	line = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!line)
		return (ft_free(&stash), NULL);
	i++;
	while (stash[i] != '\0')
		line[j++] = stash[i++];
	line[j] = '\0';
	free(stash);
	return (line);
}

char	*get_line_from_buffer(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(ft_strlen(stash) + 2);
	if (!line)
		return (ft_free(&stash), NULL);
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_and_fill_buffer(int fd, char *stash)
{
	char	*cup_buffer;
	char	*temp;
	int		chars_read;

	cup_buffer = NULL;
	cup_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!cup_buffer)
		return (ft_free(&stash), ft_free(&cup_buffer), NULL);
	ft_memset(cup_buffer, 0, BUFFER_SIZE + 1);
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
		return (ft_free(&stash), NULL);
	if (!stash)
		stash = ft_strdup("");
	stash = read_and_fill_buffer(fd, stash);
	if (!stash)
		return (NULL);
	if (*stash == '\0')
		return (ft_free(&stash), NULL);
	line = get_line_from_buffer(stash);
	if (!line)
		return (ft_free(&stash), NULL);
	stash = leftover_stash(stash);
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