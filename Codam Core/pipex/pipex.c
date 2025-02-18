/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 19:17:46 by root          #+#    #+#                 */
/*   Updated: 2025/02/18 21:12:43 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		perror_and_exit("Pipe creation failed: "); 
	pid1 = fork();
	input_and_cmd1(argv[1], argv[2], pipe_fd[1]);
	pid2 = fork();
	output_and_cmd2(argv[3], argv[4], pipe_fd[0]);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
