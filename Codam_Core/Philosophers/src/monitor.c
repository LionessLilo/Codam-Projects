/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:27 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/26 11:24:37 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	will_die(t_philosopher *philosopher, unsigned int routine_time)
{
	t_whiteboard	*whiteboard;
	t_time			current_time;
	long			current_time_ms;
	long			time_dead_ms;
	long			time_last_ate_ms;

	whiteboard = philosopher->check_whiteboard_ptr;
	time_last_ate_ms = (philosopher->time_last_ate.tv_sec * 1000)
		+ (philosopher->time_last_ate.tv_usec / 1000);
	time_dead_ms = time_last_ate_ms + whiteboard->time_to_die;
	gettimeofday(&current_time, NULL);
	current_time_ms = (current_time.tv_sec * 1000)
		+ (current_time.tv_usec / 1000);
	if (time_dead_ms <= (current_time_ms + routine_time))
		return (TRUE);
	return (FALSE);
}
