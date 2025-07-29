/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 13:20:53 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/29 10:31:47 by lionesslilo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_error	start_event(t_whiteboard *whiteboard)
{
	size_t	i;

	i = 0;
	printf("Event started\n");
	if (pthread_mutex_lock(&whiteboard->protect_door) != 0)
		return (MUTEX_LOCK_ERROR);
	printf("mutex locked\n");
	whiteboard->event_start = FALSE;
	printf("Event start is: %d\n", whiteboard->event_start);
	while (i < whiteboard->nbr_philosophers)
	{
		if (pthread_create(&whiteboard->philosophers[i].thread, NULL,
				philosopher_routine, (void *)&whiteboard->philosophers[i]) != 0)
			return (THREAD_INIT_ERROR);
		i++;
	}
	whiteboard->event_start = TRUE;
	//To do: set event start time
	if (pthread_mutex_unlock(&whiteboard->protect_door) != 0)
		return (MUTEX_UNLOCK_ERROR);
	i = 0;
	while (i < whiteboard->nbr_philosophers)
	{
		pthread_join(whiteboard->philosophers[i].thread, NULL);
		i++;
	}
	return (SUCCESS);
}
