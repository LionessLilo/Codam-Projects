/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   playground.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 18:04:06 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/13 16:39:08 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int	main(void)
{
	pid_t	pid;
	int		fd[2];

	pid = getpid();

	printf("pid before fork: %d\n", pid);
	pid = fork();
	printf("first pid after fork: %d\n", pid);

	if (pid == 0)
		printf("Child pid: %d\n", pid);

	else
		printf("Parent pid: %d\n", pid);

	return (2);
}

