/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 19:17:46 by root          #+#    #+#                 */
/*   Updated: 2025/02/25 18:19:05 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	populate_pipe_data(t_pipex *pipe_data, int fd_pipe[2],
			char *input_file, char *output_file);

int	main(int argc, char **argv)
{
	int		fd_pipe[2];
	pid_t	pid_fork1;
	t_pipex	pipe_data;

	if (argc < 3)
		exit(0);
	if (pipe(fd_pipe) < 0)
		perror_and_exit("Failed to pipe");
	populate_pipe_data(&pipe_data, fd_pipe, argv[1], argv[2]);
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
		char *input_file, char *output_file)
{
	pipe_data->pipe_read = fd_pipe[0];
	pipe_data->pipe_write = fd_pipe[1];
	pipe_data->fd_input_file = open(input_file, O_RDONLY);
	pipe_data->fd_output_file = open(output_file, O_WRONLY
			| O_CREAT | O_TRUNC, 0664);
}
