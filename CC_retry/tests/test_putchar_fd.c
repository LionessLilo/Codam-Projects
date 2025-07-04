/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_putchar_fd.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/02 14:58:35 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/02 16:35:37 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void test_putchar_fd(void)
{
    char buffer[10];
    int fd;
    size_t bytes_read;

    fd = open("putchar_fd_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        exit (-1);
    ft_putchar_fd('A', fd);
    close(fd);
    fd = open("putchar_fd_output.txt", O_RDONLY);
    if (fd == -1)
        exit (-1);
    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    close(fd);
    buffer[bytes_read] = '\0';
    log_test (strcmp(buffer, "A") == 0,
		"Test failed");
}

