/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 17:53:31 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/25 16:49:19 by llourens      ########   odam.nl         */
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
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		pipe_read;
	int		pipe_write;
	int		fd_input_file;
	int		fd_output_file;
}				t_pipex;

/* Error handling */
void	input_checks(int argc, char **argv);
void	usage_error_message(char *message);
void	perror_and_exit(char *message);

/* Input and cmd1 */
void	input_and_cmd1(t_pipex pipe_data);
void	output_and_cmd2(t_pipex pipe_data);

#endif