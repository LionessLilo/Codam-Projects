/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:27 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/18 13:07:23 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// int	check_if_dead(t_philosopher *philosopher, int routine_time)
// {
// 	int		time_dead;
// 	t_time	time;

// 	pthread_mutex_lock(&philosopher->check_whiteboard_ptr->protect_dead);
// 	gettimeofday(&time, NULL);
// 	time_dead = time.tv_usec + (philosopher->check_whiteboard_ptr->time_to_die * 1000);
// 	if (philosopher->time_last_ate + routine_time >= time_dead)
// 	{
// 		gettimeofday(&time, NULL);
// 		usleep (time_dead - time.tv_usec);
// 		pthread_mutex_lock(&(philosopher->check_whiteboard_ptr->protect_print));
// 	}
	
// }
