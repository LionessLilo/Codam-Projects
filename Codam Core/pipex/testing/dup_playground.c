/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dup_playground.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/13 19:36:56 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/14 18:49:42 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../printf/libft/libft.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*new_line;

	// if (argc < 2)
	// {
	// 	printf("Please provide some text\n");
	// 	return (1);
	// }
	fd = open("./testing/read.txt", O_RDONLY);
	fd3 = open("./testing/read_2.txt", O_RDONLY);
	new_line = get_next_line(fd2);
	printf("Before dup2: %s\n", new_line);

	// fd2 = dup2(fd3, fd);

	printf("fd: %d\n", fd2);
	new_line = get_next_line(fd2);
	printf("After dup2: %s\n", new_line);
	return (0);
}
