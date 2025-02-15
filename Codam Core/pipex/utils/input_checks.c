/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 20:19:01 by root          #+#    #+#                 */
/*   Updated: 2025/02/16 00:41:16 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	input_checks(int argc, char **argv)
{
	if (argc < 5)
		usage_error_message("pipex: error: too few arguments");
	if (argc > 5)
		usage_error_message("pipex: error: too many arguments");
	while (*argv != NULL)
	{
		if (**argv == '\0')
			usage_error_message
				("pipex: error: one of the arguments is an empty string");
		argv++;
	}
}
