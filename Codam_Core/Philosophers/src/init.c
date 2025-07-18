/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:28:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/18 16:22:47 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_whiteboard	*input_to_whiteboard(t_whiteboard *s_whiteboard, char **input_list);
t_whiteboard	*init_whiteboard_mutexes(t_whiteboard *whiteboard);

t_whiteboard	*init_whiteboard(char **input_list)
{
	// int				i;
	t_whiteboard	*whiteboard;

	whiteboard = malloc(sizeof(t_whiteboard));
	if (!whiteboard)
		return (NULL);
	whiteboard->error_code = 0;
	whiteboard = input_to_whiteboard(whiteboard, input_list);
	// whiteboard = init_whiteboard_mutexes(whiteboard);
	// if (whiteboard->error_code != 0)
	// {
	// 	// clean_whiteboard(whiteboard);
	// 	return (whiteboard);
	// }
	return (whiteboard);
}

t_whiteboard	*input_to_whiteboard(t_whiteboard *whiteboard, char **input_list)
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
	return (whiteboard);
}

// t_whiteboard	*init_whiteboard_mutexes(t_whiteboard *whiteboard)
// {
// 	int				i;
	
// 	i = 0;
// 	whiteboard->protect_forks_ptr = malloc(sizeof(pthread_mutex_t)
// 		* whiteboard->nbr_philosophers);
// 	while (i < whiteboard->nbr_philosophers)
// 	{
// 		whiteboard->error_code = pthread_mutex_init(&whiteboard->protect_forks_ptr[i], NULL);
// 		if (whiteboard->error_code != 0)
// 		{
// 			whiteboard->error_code = 7303;
// 			return (whiteboard);
// 		}
// 		i++;
// 	}
// 	whiteboard->error_code = pthread_mutex_init(&whiteboard->protect_print, NULL);
// 	if (whiteboard->error_code != 0)
// 		whiteboard->error_code = 7304;
// 	whiteboard->error_code = pthread_mutex_init(&whiteboard->protect_dead, NULL);
// 	if (whiteboard->error_code != 0)
// 		whiteboard->error_code = 7305;
// 	return (whiteboard);
// }
