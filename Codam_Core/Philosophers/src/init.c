/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:28:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/23 17:28:18 by lionesslilo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			input_to_whiteboard(t_whiteboard *s_whiteboard, char **input_list);
t_error			init_whiteboard_mutexes(t_whiteboard **whiteboard);

/*
	- Turns the input into whiteboard variables
	- Initialises the whiteboard mutexes
*/

t_error	init_whiteboard(t_whiteboard **whiteboard, char **input_list)
{
	t_error	error;
	
	*whiteboard = malloc(sizeof(t_whiteboard));
	if (!*whiteboard)
		return (MALLOC_FAIL);
	input_to_whiteboard(*whiteboard, input_list);
	error = init_whiteboard_mutexes(&whiteboard);
	if (error != SUCCESS)
		return (error);
	return (SUCCESS);
}

void	input_to_whiteboard(t_whiteboard *whiteboard, char **input_list)
{
	whiteboard->nbr_philosophers = (int)ft_atol(input_list[0]);
	whiteboard->time_to_die = (int)ft_atol(input_list[1]);
	whiteboard->time_to_eat = (int)ft_atol(input_list[2]);
	whiteboard->time_to_sleep = (int)ft_atol(input_list[3]);
	if (input_list[4])
		whiteboard->times_to_eat = (int)ft_atol(input_list[4]);
	else
		whiteboard->times_to_eat = -1;
	whiteboard->is_dead = 0;
}

t_error	init_whiteboard_mutexes(t_whiteboard **whiteboard)
{
	t_error	error_check;
	int		funct_result;
	
	(*whiteboard)->protect_forks_ptr = malloc(sizeof(pthread_mutex_t)
		* (*whiteboard)->nbr_philosophers);
	if (!(*whiteboard)->protect_forks_ptr)
		return (MALLOC_FAIL);
	error_check = init_forks(&whiteboard);
	if (error_check != SUCCESS)
		return (MUTEX_INIT_ERROR);
	funct_result = pthread_mutex_init(&(*whiteboard)->protect_print, NULL);
	if (funct_result != 0)
		return (MUTEX_INIT_ERROR);
	funct_result = pthread_mutex_init(&(*whiteboard)->protect_dead, NULL);
	if (funct_result != 0)
		return (MUTEX_INIT_ERROR);
	return (SUCCESS);
}
t_error	init_forks(t_whiteboard **whiteboard)
{
	int 	i;
	t_error	error;
	int		funct_result;

	i = 0;
	while (i < (*whiteboard)->nbr_philosophers)	
	{
		funct_result = pthread_mutex_init(&(*whiteboard)->protect_forks_ptr[i], NULL);
		if (funct_result != 0)
		{
			clean_whiteboard(&whiteboard);
			return (MUTEX_INIT_ERROR);
		}
		i++;
	}
	return SUCCESS;
}
