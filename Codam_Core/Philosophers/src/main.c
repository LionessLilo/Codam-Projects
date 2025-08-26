/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:47:54 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/26 09:28:25 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	- Checks input
	- @whiteboard is a struct where the shared resources that the philosophers can see
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
	char			**input_list;

	if (input_checks(argc, argv) == -1)
		return (41);
	input_list = create_argv(argc, argv);
	if (!input_list)
		return (write_error("Failed to create_argv", -1), -1);
	if (init_whiteboard(&whiteboard, input_list, argc) != 0)
	{
		cleanup_list(input_list);
		return (write_error("Failed to initiate whiteboard", -1), -1);
	}
	error_check = start_event(whiteboard);
	clean_whiteboard(&whiteboard);
	if (argc == 2)
		cleanup_list(input_list);
	return (error_check);
}

char	**create_argv(int argc, char **argv)
{
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv)
		return (NULL);
	return (argv);
}
