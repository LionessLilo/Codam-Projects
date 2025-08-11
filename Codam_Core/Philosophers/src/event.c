/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 13:20:53 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/11 17:01:04 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	spawn_guests(t_whiteboard *whiteboard);

/* 
	 - Acts as the "host" of the event
	 - Waits for the threads to be created
	 - Tells the threads when they can start their routine.
	 - Sets up the start time of the event
*/
int	start_event(t_whiteboard *whiteboard)
{
	size_t	i;

	i = 0;
	if (whiteboard->nbr_philosophers == 1)
	{
		usleep(whiteboard->time_to_die * 1000);
		print_action(&whiteboard->philosophers[0], "died");
		return (0);
	}
	if (spawn_guests(whiteboard) != 0)
		return (-1);
	//To do: set event start time
	whiteboard->event_start = TRUE;
	if (pthread_mutex_unlock(&whiteboard->protect_door) != 0)
		return (write_error("Door mutex failed to unlock", 7), -1);
	while (i < whiteboard->nbr_philosophers)
	{
		if (pthread_join(whiteboard->philosophers[i].thread, NULL) != 0)
			return (write_error("Failed to join threads", 6), -1);
		i++;
	}
	return (0);
}

int	spawn_guests(t_whiteboard *whiteboard)
{
	size_t			i;
	t_philosopher	*philosopher;
	pthread_t		monitor_thread;

	i = 0;
	if (pthread_mutex_lock(&whiteboard->protect_door) != 0)
		return (write_error("Spawn_guests door failed to initialise", 7), -1);
	whiteboard->event_start = FALSE;
	while (i < whiteboard->nbr_philosophers)
	{
		philosopher = &whiteboard->philosophers[i];
		philosopher->id = i + 1;
		if (pthread_create(&philosopher->thread, NULL,
				philosopher_routine, philosopher) != 0)
			return (write_error("Failed to create philosopher thread", 6), -1);
		philosopher->left_fork_ptr
			= &philosopher->check_whiteboard_ptr->protect_forks_ptr[i];
		philosopher->right_fork_ptr = &philosopher->check_whiteboard_ptr
			->protect_forks_ptr[(i + 1) % whiteboard->nbr_philosophers];
		i++;
	}
	return (0);
}
