/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:47:54 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/18 13:06:26 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	- Checks input
	- Initialises whiteboard struct
	- Starts the project
	- Handles bubbled up errors
	- Cleans up
*/

char	**create_argv(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_whiteboard	*whiteboard;
	int				error_check;

	if (input_checks(argc, argv) == -1)
		return (41);
	argv = create_argv(argc, argv);
	if (!argv)
		return (write_error("Failed to create_argv", -1), -1);
	if (init_whiteboard(&whiteboard, argv) != 0)
	{
		cleanup_list(argv);
		return (write_error("Failed to initiate whiteboard", -1), -1);
	}
	error_check = start_event(whiteboard);
	clean_whiteboard(&whiteboard);
	if (argc == 2)
		cleanup_list(argv);
	return (error_check);
}

char	**create_argv(int argc, char **argv)
{
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv)
		return (NULL);
	return (argv + 1);
}
