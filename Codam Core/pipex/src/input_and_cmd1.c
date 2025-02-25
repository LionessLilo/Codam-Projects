/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_and_cmd1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/25 15:09:58 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/25 16:51:31 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	input_and_cmd1(t_pipex pipe_data)
{
	char	*gnl_line;

	close(pipe_data.pipe_read);
	gnl_line = get_next_line(pipe_data.fd_input_file);
	if (!gnl_line)
		perror_and_exit("Failed to read from input file in input_and_cmd1");
	write(pipe_data.pipe_write, gnl_line, ft_strlen(gnl_line));
	close(pipe_data.fd_input_file);
	close(pipe_data.pipe_write);
}
