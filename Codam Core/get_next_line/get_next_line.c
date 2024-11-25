/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/19 13:02:27 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/25 11:19:55 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i++] = '\n';
		line[i] = '\0';
	}
	return (line);
}

char	*read_and_append(int fd, char **stash)
{
	char	*new_stash;
	char	*temp;

	while (1)
	{
		new_stash = read_file(fd);
		if (!new_stash)
			return (NULL);
		*stash = ft_strjoin(*stash, new_stash);
		if (!*stash)
			return (free(new_stash), NULL);
		free(new_stash);
		temp = extract_line(*stash);
		if (temp && ft_strchr(temp, '\n'))
			return (temp);
	}
}

char	*find_line(int fd, char *stash)
{
	char	*line;
	char	*joined_line;

	line = extract_line(stash);
	if (line && ft_strchr(line, '\n'))
		return (line);
	joined_line = read_and_append(fd, &stash);
	return (joined_line);
}

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
	if (bytes_read <= 0)
	{
		if (bytes_read < 0)
		{
			printf("could not read file or is EOF");
			return (free(cup_buffer), NULL);
		}
		return (free(cup_buffer), NULL);
	}
	return (cup_buffer);
}

static char	*get_next_line(int fd)
{
	static char	*stash;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
		stash = read_file(fd);
	line = find_line(fd, stash);
	return (line);
}

char *get_next_line(int fd);

int main() {
    int fd;
    char *line;

    // Open the file in read-only mode
    fd = open("file 1.txt", O_RDONLY);  // Replace "test.txt" with your file name
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Loop to read and print each line from the file
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);  // Print the line
        free(line);          // Free the memory after printing the line (if your get_next_line allocates memory)
    }

    // Close the file
    close(fd);

    return 0;
}
