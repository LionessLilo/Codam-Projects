/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_and_cmd1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/25 15:09:58 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/25 18:24:57 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	input_and_cmd1(t_pipex pipe_data)
{
	close(pipe_data.pipe_read);
	dup2(pipe_data.fd_input_file, STDIN_FILENO);
	dup2(pipe_data.pipe_write, STDOUT_FILENO);
	close(pipe_data.fd_input_file);
	close(pipe_data.pipe_write);
}
