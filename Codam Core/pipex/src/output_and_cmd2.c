/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output_and_cmd2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 17:24:29 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/21 17:25:49 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	output_and_cmd2(int pipe_fd_write, int pipe_fd_read)
{
	char	buffer[128];
	int		bytes_read;
	int		fd_output_file;

	close(pipe_fd_write);
	fd_output_file = open("./output_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_output_file < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	bytes_read = read(pipe_fd_read, buffer, 12);
	dup2(STDIN_FILENO, fd_output_file);
	write(fd_output_file, &buffer, 12);
	buffer[bytes_read] = '\0';
	close(pipe_fd_read);
}
