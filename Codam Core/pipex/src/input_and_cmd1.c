/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_and_cmd1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 14:48:11 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/20 09:31:47 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	input_and_cmd1(char *message, int pipe_fd_write, int pipe_fd_read)
{
	close(pipe_fd_read);
	write(pipe_fd_write, message, (ft_strlen(message) + 1));
	close(pipe_fd_write);
}

