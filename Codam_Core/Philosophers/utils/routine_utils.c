/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/05 12:19:06 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/18 13:51:34 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long	calculate_timestamp(t_philosopher *philosopher)
{
	t_time	current_time;
	long	timestamp;

	gettimeofday(&current_time, NULL);
	timestamp = (current_time.tv_sec
			- philosopher->check_whiteboard_ptr->event_start_time.tv_sec) * 1000
			+ (current_time.tv_usec
			- philosopher->check_whiteboard_ptr->event_start_time.tv_usec) / 1000;
	return (timestamp);
}

int	print_action(t_philosopher *philosopher, char *action)
{
	long	get_timestamp;
	
	if (pthread_mutex_lock(&philosopher->check_whiteboard_ptr->protect_print) != 0)
		return (write_error("Print mutex failed to lock", 7), -1);
	get_timestamp = calculate_timestamp(philosopher);
	printf("%ld %ld %s\n", get_timestamp, philosopher->id, action);
	if (pthread_mutex_unlock(&philosopher->check_whiteboard_ptr->protect_print) != 0)
		return (write_error("Print mutex failed to unlock", 7), -1);
	return (0);
}