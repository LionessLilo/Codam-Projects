/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_and_cmd1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/17 14:48:11 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/17 17:53:05 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	input_and_cmd1(char *input_file, char *cmd1, int pipe_fd[0])
{
	int	input_file_fd;

	input_file_fd = open(input_file, O_RDONLY);
	dup2(input_file_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
}

