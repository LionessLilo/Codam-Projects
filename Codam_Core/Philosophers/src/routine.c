/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:11 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/04 17:30:43 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


void	*philosopher_routine(void *thread_arg)
{
	t_philosopher	*philosopher;
	t_whiteboard	*whiteboard;
	int				i;

	i = 0;
	philosopher = (t_philosopher *)thread_arg;
	whiteboard = philosopher->check_whiteboard_ptr;
	while (whiteboard->event_start == FALSE)
		usleep(200);
	if (philosopher->id % 2 != 0)
		sleep_routine(philosopher);
	while (i < 4)
	{
		eat_routine(philosopher);
		sleep_routine(philosopher);
		think_routine(philosopher);
	}
	return (NULL);
}
t_error	eat_routine(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->left_fork_ptr)
}

t_error	sleep_routine(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->check_whiteboard_ptr->protect_print);
	//get the time
	printf("Philosopher %ld is sleeping\n");
	pthread_mutex_unlock(&philosopher->check_whiteboard_ptr->protect_print);
}


t_error	think_routine(t_philosopher *philosopher)
{
	
}
