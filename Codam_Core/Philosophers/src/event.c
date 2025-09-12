/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 13:20:53 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/12 13:28:58 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	handle_one_philosopher(t_whiteboard *whiteboard);
int		spawn_guests(t_whiteboard *whiteboard);

/* 
	 - Acts as the "host" of the event
	 - Waits for the threads to be created
	 - Tells the threads when they can start their routine.
	 - Sets up the start time of the event
*/
int	start_event(t_whiteboard *whiteboard)
{
	int		i;
	void	*routine_result;

	i = 0;
	if (whiteboard->nbr_philosophers == 1)
		return (handle_one_philosopher(whiteboard), 0);
	if (spawn_guests(whiteboard) != 0)
		return (-1);
	if (pthread_mutex_lock(&whiteboard->protect_door) != 0)
		return (write_error("Spawn_guests door failed to initialise", 7), -1);
	gettimeofday(&whiteboard->event_start_time, NULL);
	whiteboard->event_start = TRUE;
	if (pthread_mutex_unlock(&whiteboard->protect_door) != 0)
		return (write_error("Door mutex failed to unlock", 7), -1);
	while (i < whiteboard->nbr_philosophers)
	{
		if (pthread_join(whiteboard->philosophers[i].thread, &routine_result)
			!= 0 || (routine_result != 0))
			return (-1);
		i++;
	}
	return (0);
}

void	handle_one_philosopher(t_whiteboard *whiteboard)
{
	gettimeofday(&whiteboard->event_start_time, NULL);
	print_action(&whiteboard->philosophers[0], "has taken a fork");
	usleep(whiteboard->time_to_die * 1000);
	print_action(&whiteboard->philosophers[0], "died");
}

int	spawn_guests(t_whiteboard *whiteboard)
{
	int				i;
	t_philosopher	*philosopher;

	i = 0;
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
