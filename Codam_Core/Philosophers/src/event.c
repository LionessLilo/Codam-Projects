/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 13:20:53 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/05 16:07:24 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_error	spawn_guests(t_whiteboard *whiteboard);

/* 
	 - Acts as the "host" of the event
	 - Waits for the threads to be created
	 - Tells the threads when they can start their routine.
	 - Sets up the start time of the event
*/
t_error	start_event(t_whiteboard *whiteboard)
{
	size_t	i;
	t_error	error_code;

	i = 0;
	error_code = spawn_guests(whiteboard);
	if (error_code != SUCCESS)
		return (error_code);
	//To do: set event start time
	whiteboard->event_start = TRUE;
	if (pthread_mutex_unlock(&whiteboard->protect_door) != 0)
		return (MUTEX_UNLOCK_ERROR);
	while (i < whiteboard->nbr_philosophers)
	{
		if (pthread_join(whiteboard->philosophers[i].thread, NULL) != 0)
			return (THREAD_JOIN_ERROR);
		i++;
	}
	return (SUCCESS);
}

t_error	spawn_guests(t_whiteboard *whiteboard)
{
	size_t			i;
	t_philosopher	*philosopher;

	i = 0;
	if (pthread_mutex_lock(&whiteboard->protect_door) != 0)
		return (MUTEX_LOCK_ERROR);
	whiteboard->event_start = FALSE;
	while (i < whiteboard->nbr_philosophers)
	{
		philosopher = &whiteboard->philosophers[i];
		philosopher->id = i + 1;
		if (pthread_create(&philosopher->thread, NULL,
				philosopher_routine, philosopher) != 0)
			return (THREAD_INIT_ERROR);
		philosopher->left_fork_ptr
			= &philosopher->check_whiteboard_ptr->protect_forks_ptr[i];
		philosopher->right_fork_ptr = &philosopher->check_whiteboard_ptr
			->protect_forks_ptr[(i + 1) % whiteboard->nbr_philosophers];
		i++;
	}
	return (SUCCESS);
}
