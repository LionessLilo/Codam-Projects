/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_and_cmd1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 14:48:11 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/21 18:32:42 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <errno.h>

void	input_and_cmd1(char **input_file, int pipe_fd_write, int pipe_fd_read)
{
	int		input_file_fd;
	char	*fetched_input;

	close(pipe_fd_read);
	input_file_fd = open(*input_file, O_RDONLY);
	fetched_input = get_next_line(input_file_fd);
	if (fetched_input == NULL)
		perror_and_exit("Failed to read from file1");
	write(pipe_fd_write, fetched_input, ft_strlen(fetched_input));
	close(pipe_fd_write);
	close(input_file_fd);
}

