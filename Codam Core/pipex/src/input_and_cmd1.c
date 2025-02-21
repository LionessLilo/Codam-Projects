/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_and_cmd1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 14:48:11 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/21 15:20:54 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	input_and_cmd1(int pipe_fd_write, int pipe_fd_read)
{
	int		input_file_fd;
	char	*fetched_input;

	close(pipe_fd_read);
	input_file_fd = open("./input_file.txt", O_RDONLY);
	if (input_file_fd < 0)
		perror_and_exit("Could not open file1");
	fetched_input = get_next_line(input_file_fd);
	if (fetched_input == NULL)
		perror_and_exit("Failed to read from file1");
	write(pipe_fd_write, fetched_input, (ft_strlen(fetched_input) + 1));
	close(pipe_fd_write);
	close(input_file_fd);
}

