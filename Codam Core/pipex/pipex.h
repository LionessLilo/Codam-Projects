/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 17:53:31 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/18 16:53:41 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../printf/ft_printf.h"
# include "../printf/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> 
# include <sys/types.h>
# include <fcntl.h>

# define READ 0
# define WRITE 1

/* Error handling */
void	input_checks(int argc, char **argv);
void	usage_error_message(char *message);
void	perror_and_exit(char *message);

/* Input and cmd1 */
void	input_and_cmd1(char *input_file, char *cmd1, int pipe_fd[1]);
void	output_and_cmd2(char *cmd2,char *output_file, int pipe_fd[0]);

#endif