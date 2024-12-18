/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 15:53:46 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/18 16:59:50 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int main() 
{
    int fd;
    char *line;

    fd = open("read_file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line); 
    }

    // Close the file descriptor after finishing reading
    close(fd);

    return 0;
}