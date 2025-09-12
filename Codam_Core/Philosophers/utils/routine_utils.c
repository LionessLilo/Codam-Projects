/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/05 12:19:06 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/12 13:25:38 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long	calculate_timestamp(t_philosopher *philosopher)
{
	t_time			current_time;
	long			timestamp;
	t_whiteboard	*whiteboard;

	whiteboard = philosopher->check_whiteboard_ptr;
	gettimeofday(&current_time, NULL);
	timestamp = (current_time.tv_sec
			- whiteboard->event_start_time.tv_sec) * 1000
		+ (current_time.tv_usec
			- whiteboard->event_start_time.tv_usec) / 1000;
	return (timestamp);
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

long	get_time_in_ms(void)
{
	t_time	time;
	long	time_ms;

	gettimeofday(&time, NULL);
	time_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_ms);
}

long	get_time_last_ate(t_philosopher *philosopher)
{
	long			time_last_ate_ms;

	time_last_ate_ms = (philosopher->time_last_ate.tv_sec * 1000) +
		(philosopher->time_last_ate.tv_usec / 1000);
	return (time_last_ate_ms);
}
