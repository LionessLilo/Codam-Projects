/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   02_input_and_cmd1.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/25 15:09:58 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/06 20:17:26 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	input_and_cmd1(t_pipex pipe_data, char *orig_cmd1)
{
	char	**cmd_with_flags;

	close(pipe_data.pipe_read);
	dup2(pipe_data.fd_input_file, STDIN_FILENO);
	dup2(pipe_data.pipe_write, STDOUT_FILENO);
	cmd_with_flags = ft_split(orig_cmd1, ' ');
	if (execve(pipe_data.cmd1, cmd_with_flags, pipe_data.environment) == -1)
	{
		close(pipe_data.fd_input_file);
		close(pipe_data.pipe_write);
		free_split(cmd_with_flags);
	}
}
