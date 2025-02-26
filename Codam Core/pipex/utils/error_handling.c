/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 22:12:17 by root          #+#    #+#                 */
/*   Updated: 2025/02/26 15:21:31 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	usage_error_message(char *message)
{
	ft_putendl_fd(message, 2);
	ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
	exit (2);
}

void	perror_and_exit(char *message)
{
	perror(message);
	exit (1);
}

void	custom_error_and_exit(char *message, int exit_code)
{
	ft_putendl_fd(message, 2);
	exit (exit_code);
}
