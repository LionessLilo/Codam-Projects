/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   playground.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 18:04:06 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/13 18:46:12 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t	pid;
	int		fd[2];

	pid = getpid();
	printf("pid before fork: %d\n", pid);
	pid = fork();
	printf("first pid after fork: %d\n", pid);

	if (pid == 0)
		printf("This is the child\n");

	else
	{
		wait(NULL);
		printf("This is the parent\n");
	}

	return (2);
}

