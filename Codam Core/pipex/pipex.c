/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 19:17:46 by root          #+#    #+#                 */
/*   Updated: 2025/02/17 17:49:01 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe_fd[2];

	input_checks(argc, argv);
	if (pipe(pipe_fd) == -1)
		perror_and_exit("Pipe failed:");
	pid1 = fork();
	if (pid1 == -1)
		perror_and_exit("Fork1 failed:");
	if (pid1 == 0)
	{
		close(pipe_fd[0]);
		input_and_cmd1(argv[1], argv[2], pipe_fd[0]);
	}
	pid2 = fork();
	if (pid2 == -1)
		perror_and_exit("Fork2 failed:");
	if (pid2 == 0)
	{
		close(pipe_fd[1]);
		output_and_cmd2(argv[3], argv[4], pipe_fd[1]);
	}
	return (0);
}
