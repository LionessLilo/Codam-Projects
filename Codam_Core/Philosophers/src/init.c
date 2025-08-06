/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:28:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/06 17:28:41 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	input_to_whiteboard(t_whiteboard *whiteboard, char **input_list);
t_error	init_whiteboard_mutexes(t_whiteboard *whiteboard);
t_error	init_forks(t_whiteboard *whiteboard);
t_error	init_philosophers(t_whiteboard *whiteboard);

/*
	- Turns the input into whiteboard variables
	- Initialises the whiteboard mutexes
	- initialises the philosophers struct
*/

t_error	init_whiteboard(t_whiteboard **whiteboard, char **input_list)
{
	t_error	error;

	*whiteboard = malloc(sizeof(t_whiteboard));
	if (!*whiteboard)
		return (MALLOC_FAIL);
	input_to_whiteboard(*whiteboard, input_list);
	error = init_whiteboard_mutexes(*whiteboard);
	if (error != SUCCESS)
		return (error);
	error = init_philosophers(*whiteboard);
	if (error != SUCCESS)
	{
		clean_whiteboard((void *)&whiteboard);
		return (error);
	}
	return (SUCCESS);
}

void	input_to_whiteboard(t_whiteboard *whiteboard, char **input_list)
{
	whiteboard->nbr_philosophers = (long unsigned)ft_atol(input_list[0]);
	whiteboard->time_to_die = (int)ft_atol(input_list[1]);
	whiteboard->time_to_eat = (unsigned)ft_atol(input_list[2]);
	whiteboard->time_to_sleep = (int)ft_atol(input_list[3]);
	if (input_list[4])
		whiteboard->times_to_eat = (int)ft_atol(input_list[4]);
	else
		whiteboard->times_to_eat = -1;
	whiteboard->is_dead = FALSE;
	whiteboard->event_start = 0;
}

t_error	init_whiteboard_mutexes(t_whiteboard *whiteboard)
{
	t_error	error_check;
	int		funct_result;

	whiteboard->protect_forks_ptr = malloc(sizeof(pthread_mutex_t)
			* whiteboard->nbr_philosophers);
	if (!whiteboard->protect_forks_ptr)
		return (MALLOC_FAIL);
	error_check = init_forks(whiteboard);
	if (error_check != SUCCESS)
		return (MUTEX_INIT_ERROR);
	funct_result = pthread_mutex_init(&whiteboard->protect_print, NULL);
	if (funct_result != 0)
		return (MUTEX_INIT_ERROR);
	funct_result = pthread_mutex_init(&whiteboard->protect_dead, NULL);
	if (funct_result != 0)
		return (MUTEX_INIT_ERROR);
	funct_result = pthread_mutex_init(&whiteboard->protect_door, NULL);
	if (funct_result != 0)
		return (MUTEX_INIT_ERROR);
	return (SUCCESS);
}

t_error	init_forks(t_whiteboard *whiteboard)
{
	size_t	i;
	int		funct_result;

	i = 0;
	while (i < whiteboard->nbr_philosophers)
	{
		funct_result = pthread_mutex_init(&whiteboard->protect_forks_ptr[i],
				NULL);
		if (funct_result != 0)
		{
			clean_whiteboard(&whiteboard);
			return (MUTEX_INIT_ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

t_error	init_philosophers(t_whiteboard *whiteboard)
{
	size_t			i;
	long unsigned	right_fork_calc;

	i = 0;
	whiteboard->philosophers = malloc(sizeof(t_philosopher)
			* whiteboard->nbr_philosophers);
	if (!whiteboard->philosophers)
		return (MALLOC_FAIL);
	while (i < whiteboard->nbr_philosophers)
	{
		whiteboard->philosophers[i].id = i;
		whiteboard->philosophers[i].nbr_meals_eaten = 0;
		whiteboard->philosophers[i].time_last_ate = 0;
		whiteboard->philosophers[i].check_whiteboard_ptr = whiteboard;
		whiteboard->philosophers[i].left_fork_ptr
			= &whiteboard->protect_forks_ptr[i];
		right_fork_calc = (i + 1) % whiteboard->nbr_philosophers;
		whiteboard->philosophers[i].right_fork_ptr
			= &whiteboard->protect_forks_ptr[right_fork_calc];
		i++;
	}
	return (SUCCESS);
}
