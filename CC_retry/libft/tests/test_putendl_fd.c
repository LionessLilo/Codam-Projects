/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_putendl_fd.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/02 16:58:23 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/02 17:27:43 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_putendl_fd(void)
{
    char buffer[10];
    int fd;
    size_t bytes_read;

    fd = open("putendl_fd_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        exit (-1);
    ft_putendl_fd("World", fd);
    close(fd);
    fd = open("putendl_fd_output.txt", O_RDONLY);
    if (fd == -1)
        exit (-1);
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    close(fd);
    buffer[bytes_read] = '\0';
    log_test (strcmp(buffer, "World\0\n") == 0,
		"Test failed");
}