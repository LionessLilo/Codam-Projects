/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_testing.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/19 17:56:33 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/19 19:04:54 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_TESTING_H
# define PIPEX_TESTING_H

# include "../../printf/ft_printf.h"
# include "../../printf/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> 
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

/* Error handling */
void	input_checks(int argc, char **argv);
void	usage_error_message(char *message);
void	perror_and_exit(char *message);

/* Input and cmd1 */
void	input_and_cmd1(char *message, int pipe_fd_write, int pipe_fd_read);
void	output_and_cmd2(int pipe_fd_write, int pipe_fd_read);

#endif