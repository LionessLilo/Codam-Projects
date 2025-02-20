/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output_and_cmd2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 17:24:29 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/20 09:36:18 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	output_and_cmd2(int pipe_fd_write, int pipe_fd_read)
{
	char	buffer[128];
	int		bytes_read;

	close(pipe_fd_write);
	bytes_read = read(pipe_fd_read, buffer, 12);
	write(1, &buffer, 12);
	buffer[bytes_read] = '\0';
	close(pipe_fd_read);
}
