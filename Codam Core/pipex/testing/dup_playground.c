/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dup_playground.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/13 19:36:56 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/13 20:01:03 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		dup_fd1;
	int		fd2;
	int		amount_read;
	int		dup_amount_read;
	char	buffer[10];

	fd1 = open("./testing/read.txt", O_RDONLY);
	fd2 = open("./testing/write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup_fd1 = dup(fd1);
	printf("fd1: %d\n", fd1);
	printf("fd2: %d\n", fd2);
	printf("dup_fd1: %d\n", dup_fd1);

	amount_read = read(fd1, buffer, 10);
	dup_amount_read = read(dup_fd1, buffer, 10);

	printf("Straight read: %s\n", buffer);
	printf("Duplicated fd read: %s\n", buffer);

	close(fd1);
	close(fd2);
	return (0);
}
