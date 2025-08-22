/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:11 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/22 16:52:28 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	run_routine(t_philosopher *philosopher);
int	eat_routine(t_philosopher *philosopher);
int	sleep_routine(t_philosopher *philosopher);
int	think_routine(t_philosopher *philosopher);

/* 
	- Delegates starting philosophers
	- Runs the philosophers routines
	- Writes the error and error code if an error occurs
*/

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
	{
		if (think_routine(philosopher) == -1)
			return ((void *)-1);
		usleep(1000);
	}
	while (i < philosopher->check_whiteboard_ptr->times_to_eat
		&& philosopher->check_whiteboard_ptr->is_dead == FALSE)
	{
		if (run_routine(philosopher) == -1)
			return ((void *)-1);
		i++;
	}
	return (NULL);
}

int	run_routine(t_philosopher *philosopher)
{
	if (eat_routine(philosopher) != 0)
		return (-1);
	if (philosopher->nbr_meals_eaten == philosopher->check_whiteboard_ptr->times_to_eat)
		return (0);
	if (sleep_routine(philosopher) == -1)
		return (-1);
	if (think_routine(philosopher) == -1)
		return (-1);
	return (0);
}

//To do: 
int	eat_routine(t_philosopher *philosopher)
{
	if (pick_up_forks(philosopher) == -1)
		return (-1);
	if (print_action(philosopher, "is eating") == -1)
		return (-1);
	philosopher->nbr_meals_eaten++;
	usleep(philosopher->check_whiteboard_ptr->time_to_eat * 1000);
	gettimeofday(&philosopher->time_last_ate, NULL);
	if (pthread_mutex_unlock(philosopher->left_fork_ptr) != 0)
		return (write_error("Left fork failed to unlock", 7), -1);
	if (pthread_mutex_unlock(philosopher->right_fork_ptr) != 0)
		return (write_error("Right fork failed to unlock", 7), -1);
	return (0);
}

int	sleep_routine(t_philosopher *philosopher)
{
	// if (check_if_dead(philosopher, philosopher->check_whiteboard_ptr->time_to_sleep) == TRUE)
	// 	return (-1);
	if (print_action(philosopher, "is sleeping") == -1)
		return (-1);
	usleep((unsigned int)(philosopher->check_whiteboard_ptr->time_to_sleep * 1000));
	return (0);
}


int	think_routine(t_philosopher *philosopher)
{
	if (print_action(philosopher, "is thinking") == -1)
		return (-1);
	return (0);
}
