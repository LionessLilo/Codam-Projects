/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:47:54 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/05 16:39:36 by lilo          ########   odam.nl         */
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
	t_error			error_check;

	error_check = input_checks(argc, argv);
	if (error_check != SUCCESS)
		return (error_check);
	argv = create_argv(argc, argv);
	if (!argv)
		return (FUNCT_ERROR);
	error_check = init_whiteboard(&whiteboard, argv);
	if (error_check != SUCCESS)
	{
		cleanup_list(argv);
		return (error_check);
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
	return (argv + 1);
}
