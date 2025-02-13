/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   playground.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 18:04:06 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/13 14:37:26 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("pid before fork: %d\n", pid);
	pid = fork();
	printf("first pid after fork: %d\n", pid);

	return (2);
}

