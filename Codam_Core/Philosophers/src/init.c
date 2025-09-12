/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:28:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/12 12:46:13 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	input_to_whiteboard(t_whiteboard *whiteboard,
			char **input_list, int argc);
int		init_whiteboard_mutexes(t_whiteboard *whiteboard);
int		init_forks(t_whiteboard *whiteboard);
int		init_philosophers(t_whiteboard *whiteboard);

/*
	- Turns the input into whiteboard variables
	- Initialises the whiteboard mutexes
	- initialises the philosophers struct
*/

int	init_whiteboard(t_whiteboard **whiteboard, char **input_list, int argc)
{
	*whiteboard = malloc(sizeof(t_whiteboard));
	if (!*whiteboard)
		return (write_error("Whiteboard malloc fail", 5), -1);
	input_to_whiteboard(*whiteboard, input_list, argc);
	if (init_whiteboard_mutexes(*whiteboard) != 0)
		return (-1);
	if (init_philosophers(*whiteboard) != 0)
		return (clean_whiteboard((void *)&whiteboard), -1);
	return (0);
}

void	input_to_whiteboard(t_whiteboard *whiteboard,
			char **input_list, int argc)
{
	char	**list;

	if (argc == 2)
		list = input_list;
	else
		list = input_list + 1;
	whiteboard->nbr_philosophers = (int)ft_atol(list[0]);
	whiteboard->time_to_die = (unsigned)ft_atol(list[1]);
	whiteboard->time_to_eat = (unsigned)ft_atol(list[2]);
	whiteboard->time_to_sleep = (int)ft_atol(list[3]);
	if (list[4])
		whiteboard->times_to_eat = (int)ft_atol(list[4]);
	else
		whiteboard->times_to_eat = -1;
	whiteboard->is_dead = FALSE;
	whiteboard->event_start = 0;
}

int	init_whiteboard_mutexes(t_whiteboard *whiteboard)
{
	whiteboard->protect_forks_ptr = malloc(sizeof(pthread_mutex_t)
			* (unsigned)whiteboard->nbr_philosophers);
	if (!whiteboard->protect_forks_ptr)
		return (write_error("Forks array malloc fail.", 5), -1);
	if (init_forks(whiteboard) == 7)
		return (write_error("Failed to initilaise forks", 7), -1);
	if (pthread_mutex_init(&whiteboard->protect_print, NULL) != 0)
		return (write_error("Print mutex failed to initialise.", 7), -1);
	if (pthread_mutex_init(&whiteboard->protect_dead, NULL) != 0)
		return (write_error("Dead mutex failed to initialise", 7), -1);
	if (pthread_mutex_init(&whiteboard->protect_door, NULL) != 0)
		return (write_error("Door mutex failed to initialise", 7), -1);
	return (0);
}

int	init_forks(t_whiteboard *whiteboard)
{
	int	i;

	i = 0;
	while (i < whiteboard->nbr_philosophers)
	{
		if (pthread_mutex_init(&whiteboard->protect_forks_ptr[i],
				NULL) != 0)
			return (clean_whiteboard(&whiteboard), 7);
		i++;
	}
	return (0);
}

int	init_philosophers(t_whiteboard *whiteboard)
{
	int	i;
	int	right_fork_calc;

	i = 0;
	whiteboard->philosophers = malloc(sizeof(t_philosopher)
			* (unsigned)whiteboard->nbr_philosophers);
	if (!whiteboard->philosophers)
		return (write_error("Philosophers failed to initialise", 5), -1);
	while (i < whiteboard->nbr_philosophers)
	{
		whiteboard->philosophers[i].id = i + 1;
		whiteboard->philosophers[i].nbr_meals_eaten = 0;
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
