/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/11 17:53:31 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/15 23:29:12 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../printf/ft_printf.h"
# include "../printf/libft/libft.h"
# include <unistd.h> // getpid, ppid, fork etc. 
# include <stdlib.h>
# include <stdio.h> 
# include <sys/types.h> // pid_t
# include <fcntl.h> //file control operations

/* Error handling */
void	input_checks(int argc, char **argv);
void	usage_error_message(char *message);

#endif