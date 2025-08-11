/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:28:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/11 17:06:30 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	input_to_whiteboard(t_whiteboard *whiteboard, char **input_list);
int		init_whiteboard_mutexes(t_whiteboard *whiteboard);
int		init_forks(t_whiteboard *whiteboard);
int		init_philosophers(t_whiteboard *whiteboard);

/*
	- Turns the input into whiteboard variables
	- Initialises the whiteboard mutexes
	- initialises the philosophers struct
*/

int	init_whiteboard(t_whiteboard **whiteboard, char **input_list)
{
	*whiteboard = malloc(sizeof(t_whiteboard));
	if (!*whiteboard)
		return (write_error("Whiteboard malloc fail", 5), -1);
	input_to_whiteboard(*whiteboard, input_list);
	if (init_whiteboard_mutexes(*whiteboard) != 0);
		return (-1);
	if (init_philosophers(*whiteboard) != 0)
		return (clean_whiteboard((void *)&whiteboard), -1);
	return (0);
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

int	init_whiteboard_mutexes(t_whiteboard *whiteboard)
{
	int		funct_result;

	whiteboard->protect_forks_ptr = malloc(sizeof(pthread_mutex_t)
			* whiteboard->nbr_philosophers);
	if (!whiteboard->protect_forks_ptr)
		return (write_error("Forks array malloc fail.", 5), -1);
	if (init_forks(whiteboard) == 7);
		return (write_error("Failed to initilaise forks", 7), -1);
	if (pthread_mutex_init(&whiteboard->protect_print, NULL) != 0);
		return (write_error("Print mutex failed to initialise.", 7), -1);
	if (pthread_mutex_init(&whiteboard->protect_dead, NULL) != 0);
		return (write_error("Dead mutex failed to initialise", 7), -1);
	if (pthread_mutex_init(&whiteboard->protect_door, NULL) != 0);
		return (write_error("Door mutex failed to initialise", 7), -1);
	return (0);
}

int	init_forks(t_whiteboard *whiteboard)
{
	size_t	i;
	int		funct_result;

	i = 0;
	while (i < whiteboard->nbr_philosophers)
	{
		if (pthread_mutex_init(&whiteboard->protect_forks_ptr[i],
				NULL) != 0);	
			return (clean_whiteboard(&whiteboard), 7);
		i++;
	}
	return (0);
}

int	init_philosophers(t_whiteboard *whiteboard)
{
	size_t			i;
	long unsigned	right_fork_calc;

	i = 0;
	whiteboard->philosophers = malloc(sizeof(t_philosopher)
			* whiteboard->nbr_philosophers);
	if (!whiteboard->philosophers)
		return (write_error("Philosophers failed to initialise", 5), -1);
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
	return (0);
}
