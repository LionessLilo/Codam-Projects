/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 13:20:53 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/29 14:13:15 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_error	spawn_guests(t_whiteboard *whiteboard);

t_error	start_event(t_whiteboard *whiteboard)
{
	size_t	i;
	t_error	error_code;

	i = 0;
	error_code = spawn_guests(whiteboard);
	if (error_code != SUCCESS)
		return (error_code);
	whiteboard->event_start = TRUE;
	//To do: set event start time
	if (pthread_mutex_unlock(&whiteboard->protect_door) != 0)
		return (MUTEX_UNLOCK_ERROR);
	while (i < whiteboard->nbr_philosophers)
	{
		pthread_join(whiteboard->philosophers[i].thread, NULL);
		i++;
	}
	return (SUCCESS);
}

t_error	spawn_guests(t_whiteboard *whiteboard)
{
	size_t	i;

	i = 0;
	if (pthread_mutex_lock(&whiteboard->protect_door) != 0)
		return (MUTEX_LOCK_ERROR);
	whiteboard->event_start = FALSE;
	while (i < whiteboard->nbr_philosophers)
	{
		if (pthread_create(&whiteboard->philosophers[i].thread, NULL,
				philosopher_routine, (void *)&whiteboard->philosophers[i]) != 0)
			return (THREAD_INIT_ERROR);
		usleep(100);
		i++;
	}
	return (SUCCESS);
}
