/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/05 12:19:06 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/22 16:50:54 by lilo          ########   odam.nl         */
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

int	pick_up_forks(t_philosopher *philosopher)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philosopher->id % 2 == 0)
	{
		first_fork = philosopher->left_fork_ptr;
		second_fork = philosopher->right_fork_ptr;
	}
	else
	{
		first_fork = philosopher->right_fork_ptr;
		second_fork = philosopher->left_fork_ptr;	
	}
	if (pthread_mutex_lock(first_fork) != 0)
		return (write_error("Failed to lock first fork.", 7), -1);
	if (print_action(philosopher, "has taken a fork") == -1)
		return (-1);
	if (pthread_mutex_lock(second_fork) != 0)
		return (write_error("Failed to lock second fork", 7), -1);
	if (print_action(philosopher, "has taken a fork") == -1)
		return (-1);
	return (0);
}
