/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_error_handling.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 13:54:36 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/06 15:35:37 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/* Checks if it a pid and return false if it is a pid */
static int	is_not_pid(int long pid)
{
	if (pid <= 0)
		return (1);
	else if (pid > 32768)
		return (1);
	else
		return (0);
}

/* Checks if there is a syntax error and returns true or false */
static int	is_syntax_error(char *number)
{
	int		i;

	i = 0;
	while (number[i])
	{
		if (ft_isdigit(number[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

/* Checks if there is an input error and returns true or false */
int	input_errors(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc != 3 || argv[1][0] || argv[2][0])
		return (1);
	if (is_syntax_error(argv[1]) == 1)
		return (1);
	pid = ft_atol(argv[1]);
	if (is_not_pid == 0)
		return (1);
	return (0);
}
