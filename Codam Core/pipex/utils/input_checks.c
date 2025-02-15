/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 20:19:01 by root          #+#    #+#                 */
/*   Updated: 2025/02/15 23:55:25 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	input_checks(int argc, char **argv)
{
	if (argc < 5)
		error_message_and_exit("pipex: error: too few arguments");
	if (argc > 5)
		error_message_and_exit("pipex: error: too many arguments");
	while (*argv != NULL)
	{
		if (**argv == '\0')
			error_message_and_exit("pipex: error: argument is an empty string");
		argv++;
	}
}
