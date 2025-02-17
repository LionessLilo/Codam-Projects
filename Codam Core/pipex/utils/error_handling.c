/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 22:12:17 by root          #+#    #+#                 */
/*   Updated: 2025/02/17 15:33:59 by llourens      ########   odam.nl         */
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
	exit (EXIT_FAILURE);
}
