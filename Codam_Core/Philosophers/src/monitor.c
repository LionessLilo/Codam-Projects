/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:27 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/12 17:51:03 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	will_die(t_philosopher *philosopher, unsigned int routine_time)
{
	t_whiteboard	*whiteboard;
	long			current_time_ms;
	long			time_dead_ms;
	long			time_last_ate_ms;

	whiteboard = philosopher->check_whiteboard_ptr;
	if (!philosopher->time_last_ate.tv_sec
		&& !philosopher->time_last_ate.tv_usec)
		philosopher->time_last_ate = whiteboard->event_start_time;
	time_last_ate_ms = get_time_last_ate(philosopher);
	time_dead_ms = time_last_ate_ms + whiteboard->time_to_die;
	current_time_ms = get_time_in_ms();
	if (time_dead_ms <= (current_time_ms + routine_time))
		return (TRUE);
	return (FALSE);
}

void	*death_monitor(void *arg)
{
	t_whiteboard	*whiteboard;
	t_philosopher	*philosopher;
	int				i;
	long			current_time_ms;
	long			time_last_ate_ms;

	whiteboard = (t_whiteboard *)arg;
	while (whiteboard->event_start == FALSE)
		usleep(1000);
	while (whiteboard->is_dead == FALSE)
	{
		i = 0;
		while (i < whiteboard->nbr_philosophers && whiteboard->is_dead == FALSE)
		{
			philosopher = &whiteboard->philosophers[i];
			current_time_ms = get_time_in_ms();
			time_last_ate_ms = get_time_last_ate(philosopher);
			if (current_time_ms >= time_last_ate_ms + whiteboard->time_to_die)
			{
				if (pthread_mutex_lock(&whiteboard->protect_dead) != 0)
					return (write_error("Death mutex failed to lock", 7), NULL);
				whiteboard->is_dead = TRUE;
				if (pthread_mutex_unlock(&whiteboard->protect_dead) != 0)
					return (write_error("Death mutex failed to unlock", 7),
						NULL);
				print_action(philosopher, "died");
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

void	handle_death(t_philosopher *philosopher)
{
	t_whiteboard	*whiteboard;
	long			current_time_ms;
	long			time_last_ate_ms;

	whiteboard = philosopher->check_whiteboard_ptr;
	current_time_ms = get_time_in_ms();
	time_last_ate_ms = get_time_last_ate(philosopher);
	if (current_time_ms < (time_last_ate_ms + whiteboard->time_to_die))
		usleep((unsigned int)(((time_last_ate_ms + whiteboard->time_to_die)
					- current_time_ms) * 1000));
	pthread_mutex_lock(&whiteboard->protect_dead);
	if (whiteboard->is_dead == FALSE)
	{
		print_action(philosopher, "died");
		whiteboard->is_dead = TRUE;
	}
	pthread_mutex_unlock(&whiteboard->protect_dead);
}
