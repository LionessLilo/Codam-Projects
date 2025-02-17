/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output_and_cmd2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 17:24:29 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/17 17:56:29 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	output_and_cmd2(char *cmd2, char *output_file, int pipe_fd[2])
{
	int	fd_output_file;

	fd_output_file = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_output_file, STDOUT_FILENO);
}
