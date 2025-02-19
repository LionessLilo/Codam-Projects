/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 19:17:46 by root          #+#    #+#                 */
/*   Updated: 2025/02/19 19:19:56 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int		pipe_fd[2];
	pid_t	pid_fork1;
	pid_t	pid_fork2;
	char	*message = "Hello World!";

	if (pipe(pipe_fd) < 0)
		perror_and_exit("Pipe failed: ");
	pid_fork1 = fork();
	if (pid_fork1 < 0)
		perror_and_exit("Fork1 failed: ");
	if (pid_fork1 == 0)
		input_and_cmd1(message, pipe_fd[1], pipe_fd[0]);
	pid_fork2 = fork();
	if (pid_fork2 < 0)
		perror_and_exit("Fork2 failed: ");
	if (pid_fork2 == 0)
		output_and_cmd2(pipe_fd[1], pipe_fd[0]);
	else
	{
		waitpid(pid_fork1, NULL, 0);
		waitpid(pid_fork2, NULL, 0);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		return (0);
	}
}
