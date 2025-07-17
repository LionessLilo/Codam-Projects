/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:47:54 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/17 18:09:50 by lilo          ########   odam.nl         */
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
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	whiteboard = init_whiteboard(argv);
	//Start logic
	//Handle bubbled up errors. 
	return (0);
}
