/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:47:54 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/21 16:56:55 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	Exit codes legend:
	- All error id's are greater that 300
	-1301 = function error -1 + error id 301

	-1 = Other process return error
	 0 = Success
	 3 = General error
	 5 = Failed to malloc
	 6 = Thread error
	 7 = Mutex error
	41 = Uer input error
*/

/*
	- Checks input
	- Initialises whiteboard struct
	- Starts the project
	-  Handles bubbled up errors
	- Cleans up
*/

int	main(int argc, char **argv)
{
	int				result_check;
	t_whiteboard	*whiteboard;
	
	result_check = input_checks(argc, argv);
	if (result_check != 0)
		return (result_check);
	argv = create_argv(argc, argv);
	whiteboard = init_whiteboard(argv);
	if (!whiteboard)
		return (5303);
	else if (whiteboard->error_code != 0)
		return (whiteboard->error_code);
	//Start logic
	//Handle bubbled up errors. 
	return (0);
}

static char	**create_argv(int argc, char **argv)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (-1302);
	}
	else
		argv = argv + 1;
	return (argv);
}
