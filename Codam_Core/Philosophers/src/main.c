/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:47:54 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/18 15:50:46 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	int				result_check;
	t_whiteboard	*whiteboard;
	
	result_check = input_checks(argc, argv);
	if (result_check != 0)
	{
		report_error(result_check);
		return (result_check);
	}
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (-1302);
	}
	else
		argv = argv + 1;
	whiteboard = init_whiteboard(argv);
	if (whiteboard->error_code != 0)
		return (whiteboard->error_code); // Will need to clean struct
	//Start logic
	//Handle bubbled up errors. 
	return (0);
}
