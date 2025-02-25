/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output_and_cmd2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/25 16:28:50 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/25 16:51:44 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	output_and_cmd2(t_pipex pipe_data)
{
	char	*line_to_write;

	close(pipe_data.pipe_write);
	line_to_write = get_next_line(pipe_data.pipe_read);
	if (!line_to_write)
		perror_and_exit("Failed to read from pipe");
	write(pipe_data.fd_output_file, line_to_write, ft_strlen(line_to_write));
	close(pipe_data.fd_output_file);
	close(pipe_data.pipe_read);
}
