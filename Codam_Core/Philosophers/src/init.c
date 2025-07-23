/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:28:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/23 13:45:09 by lionesslilo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void			input_to_whiteboard(t_whiteboard *s_whiteboard, char **input_list);
t_whiteboard	*init_whiteboard_mutexes(t_whiteboard *whiteboard);

/*
	- Turns the input into whiteboard variables
	- Initialises the whiteboard mutexes
*/

t_error	init_whiteboard(t_whiteboard **whiteboard, char **input_list)
{
	// int				i;

	*whiteboard = malloc(sizeof(t_whiteboard));
	if (!*whiteboard)
		return (MALLOC_FAIL);
	input_to_whiteboard(*whiteboard, input_list);
	// whiteboard = init_whiteboard_mutexes(whiteboard);
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

// t_whiteboard	*init_whiteboard_mutexes(t_whiteboard *whiteboard)
// {
// 	whiteboard->protect_forks_ptr = malloc(sizeof(pthread_mutex_t)
// 		* whiteboard->nbr_philosophers);
// 	if (!whiteboard->protect_forks_ptr)
// 	{
// 		whiteboard->error_code = 5304;
// 		return (whiteboard);
// 	}
// 	whiteboard = init_forks(whiteboard);
// 	if (whiteboard->error_code != 0)
// 		return (whiteboard->error_code);
// 	whiteboard->error_code = pthread_mutex_init(&whiteboard->protect_print, NULL);
// 	if (whiteboard->error_code != 0)
// 		whiteboard->error_code = 7306;
// 	whiteboard->error_code = pthread_mutex_init(&whiteboard->protect_dead, NULL);
// 	if (whiteboard->error_code != 0)
// 		whiteboard->error_code = 7307;
// 	return (whiteboard);
// }

// t_whiteboard	*init_forks(t_whiteboard *whiteboard)
// {
// 	int	i;

// 	i = 0;
// 	while (i < whiteboard->nbr_philosophers)
// 	{
// 		whiteboard->error_code = pthread_mutex_init(&whiteboard->protect_forks_ptr[i], NULL);
// 		if (whiteboard->error_code != 0)
// 		{
// 			whiteboard->error_code = 7305;
// 			return (whiteboard);
// 		}
// 		i++;
// 	}
// 	return (whiteboard);
// }
