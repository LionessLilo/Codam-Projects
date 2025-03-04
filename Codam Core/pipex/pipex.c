/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 19:17:46 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/04 20:05:41 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	populate_pipe_data(t_pipex *pipe_data, int fd_pipe[2],
			char **argv, char **env);

int	main(int argc, char **argv, char **env)
{
	int		fd_pipe[2];
	pid_t	pid_fork1;
	t_pipex	pipe_data;

	input_checks(argc, argv, env);
	if (pipe(fd_pipe) < 0)
		perror_and_exit("Failed to pipe");
	populate_pipe_data(&pipe_data, fd_pipe, argv, env);
	pid_fork1 = fork();
	if (pid_fork1 < 0)
		perror_and_exit("failed to fork");
	if (pid_fork1 == 0)
		input_and_cmd1(pipe_data);
	else
	{
		output_and_cmd2(pipe_data);
		waitpid(0, NULL, 0);
	}
	return (0);
}

void	populate_pipe_data(t_pipex *pipe_data, int fd_pipe[2],
		char **argv, char **env)
{
	pipe_data->pipe_read = fd_pipe[0];
	pipe_data->pipe_write = fd_pipe[1];
	pipe_data->fd_input_file = open(argv[1], O_RDONLY);
	pipe_data->fd_output_file = open(argv[4], O_WRONLY
			| O_CREAT | O_TRUNC, 0664);
	pipe_data->cmd1 = get_cmd_path(argv[2], env);
	pipe_data->cmd2 = get_cmd_path(argv[3], env);
}
