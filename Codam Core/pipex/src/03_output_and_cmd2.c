/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   03_output_and_cmd2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/25 16:28:50 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/05 19:15:19 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	output_and_cmd2(t_pipex pipe_data, char *orig_cmd2)
{
	char	**cmd_with_flags;

	close(pipe_data.pipe_write);
	dup2(pipe_data.pipe_read, STDIN_FILENO);
	dup2(pipe_data.fd_output_file, STDOUT_FILENO);
	cmd_with_flags = ft_split(orig_cmd2, ' ');

	if (execve(pipe_data.cmd2, cmd_with_flags, pipe_data.environment) == -1)
	{
		close(pipe_data.fd_output_file);
		close(pipe_data.pipe_read);
		perror("Failed execve for cmd2");
		free_split(cmd_with_flags);
	}
}
