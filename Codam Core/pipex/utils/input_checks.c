/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/15 20:19:01 by root          #+#    #+#                 */
/*   Updated: 2025/03/05 20:13:12 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	input_checks(t_pipex *pipe_data, int argc, char **argv, char **env)
{
	pipe_data->fd_output_file = open(argv[4],
			O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (argc < 5)
		usage_error_message("Pipex: error: too few arguments");
	if (argc > 5 && argc != 2)
		usage_error_message("Pipex: error: too many arguments");
	if ((access(argv[1], F_OK) != 0) || (access(argv[4], F_OK) != 0))
		usage_error_message("Pipex: error: A file does not exist");
	if (access(argv[1], R_OK) != 0)
		usage_error_message("Pipex: error: cannot read from file1");
	if ((access(argv[4], W_OK) != 0) || (access(".", W_OK) != 0))
		usage_error_message("Pipex: error: cannot write to file2");
	if (!env)
		perror_and_exit("env is NULL");
	while (*argv != NULL)
	{
		if (**argv == '\0')
			usage_error_message
				("Pipex: error: one of the arguments is an empty string");
		argv++;
	}
}
