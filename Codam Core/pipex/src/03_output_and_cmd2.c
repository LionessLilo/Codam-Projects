/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output_and_cmd2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/25 16:28:50 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/25 18:26:40 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	output_and_cmd2(t_pipex pipe_data)
{

	close(pipe_data.pipe_write);
	dup2(pipe_data.pipe_read, STDIN_FILENO);
	dup2(pipe_data.fd_output_file, STDOUT_FILENO);
	close(pipe_data.fd_output_file);
	close(pipe_data.pipe_read);
}
