/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/19 13:02:27 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/25 19:37:43 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*add_to_line_buffer(int fd, char *stash, int i)
{
	char	*new_stash;
	char	*temp;

	while (!stash[i])
	{
		new_stash = read_file(fd);
		while (new_stash)
		{
			stash = ft_strjoin(stash, new_stash);
			if (!stash)
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
	return (NULL);
}

char	*fill_line_buffer(int fd, char *stash)
{
	int		i;
	char	*line_buffer;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line_buffer = ft_calloc(i + 2, sizeof(char));
	if (!line_buffer)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
	{
		line_buffer[i] = stash[i];
		i++;
	}
	if (stash[i] == '\0')
		line_buffer = add_to_line_buffer(fd, stash, i); 
	return (line_buffer);
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
		return (free(cup_buffer), NULL);
	return (cup_buffer);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;
	char		*line_buffer;
	char		*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		printf("fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0");
		return (NULL);
	}
	if (!stash)
		stash = read_file(fd);
	line_buffer = fill_line_buffer(fd, stash);
}

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
