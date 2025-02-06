/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_error_handling.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 13:54:36 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/06 14:43:08 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	is_pid(int long pid, )

// Checks if there is a syntax error and returns true or false
int	is_syntax_error(char *number)
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

// Checks if there is an input error and returns true or false
int	input_errors(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc != 3)
		return (1);
	if (is_syntax_error(argv[1]) == 1)
		return (1);
	pid = ft_atol(argv[1]);
	if (is_pid == 0)
		return (1);

	return (0);
}
