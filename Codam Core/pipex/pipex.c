/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 19:17:46 by root          #+#    #+#                 */
/*   Updated: 2025/02/16 01:46:55 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		fd[2];

	input_checks(argc, argv);
	pid = fork();
	if (pid == 0)
	{
		//To Do: child process
	}
	else
	{
		//To Do: parent process
	}

	return (0);
}
