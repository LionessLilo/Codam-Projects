/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 20:19:01 by root          #+#    #+#                 */
/*   Updated: 2025/02/16 01:43:26 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	input_checks(int argc, char **argv)
{
	if (argc < 5)
		usage_error_message("pipex: error: too few arguments");
	if (argc > 5)
		usage_error_message("pipex: error: too many arguments");
	if (!access(argv[1], F_OK) || !access(argv[4], F_OK)) // To Do: Test Read and write access of the files
		usage_error_message("pipex: error: A file does not exist");
	if (!access(argv[1], R_OK))
		usage_error_message("pipex: error: cannot read from file1");
	if (!access(argv[4], W_OK)) //To Do: check if dir has write permissions
		usage_error_message("pipex: error: cannot write to file2");
	while (*argv != NULL)
	{
		if (**argv == '\0')
			usage_error_message
				("pipex: error: one of the arguments is an empty string");
		argv++;
	}
}
