/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   playground.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/30 17:00:58 by root          #+#    #+#                 */
/*   Updated: 2025/01/30 17:23:13 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int		pipefd[2]; // 0 = read && 1 = write
	char	*buffer[255] = { 0 };

	pipe(pipefd);
	write(pipefd[1], "msg", 3);
	if (fork() >  0) // parent will continue writing and child will continue  from this line
		return (0);
	else 
		read(pipefd[0], buffer, 3);

		printf("Got from pipe: %s\n", buffer);

	return (0);
}
