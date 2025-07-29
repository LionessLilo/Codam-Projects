/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:11 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/29 10:32:23 by lionesslilo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_error	wait_at_door(t_philosopher *philosopher);

void	*philosopher_routine(void *thread_arg)
{
	t_philosopher	*philosopher;
	t_whiteboard	*whiteboard;
	int				i;

	i = 0;
	philosopher = (t_philosopher *)thread_arg;
	whiteboard = philosopher->check_whiteboard_ptr;
	if (wait_at_door(philosopher) != SUCCESS)
		return (NULL);
	//To do:start routine
	while (i < 4)
	{
		pthread_mutex_lock(&whiteboard->protect_print);
		printf("Philosopher %ld is eating\n", philosopher->id);
		pthread_mutex_unlock(&whiteboard->protect_print);
		pthread_mutex_lock(&whiteboard->protect_print);
		printf("Philosopher %ld is sleeping\n", philosopher->id);
		pthread_mutex_unlock(&whiteboard->protect_print);
		pthread_mutex_lock(&whiteboard->protect_print);
		printf("Philosopher %ld is thinking\n", philosopher->id);
		pthread_mutex_unlock(&whiteboard->protect_print);
		i++;
	}
	return (NULL);
}

t_error	wait_at_door(t_philosopher *philosopher)
{
	t_whiteboard	*whiteboard;
	pthread_mutex_t	*door_mutex;

	whiteboard = philosopher->check_whiteboard_ptr;
	door_mutex = &whiteboard->protect_door;
	while (1)
	{
		if (pthread_mutex_lock(&(*door_mutex)) != 0)
			return (MUTEX_LOCK_ERROR);
		if (whiteboard->event_start == TRUE)
		{
			if (pthread_mutex_unlock(&(*door_mutex)) != 0)
				return (MUTEX_UNLOCK_ERROR);
			break ;
		}
		else
			if (pthread_mutex_unlock(&(*door_mutex)) != 0)
				return (MUTEX_UNLOCK_ERROR);
		usleep(100);
	}
	return (SUCCESS);
}
