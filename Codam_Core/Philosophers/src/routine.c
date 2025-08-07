/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:11 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/07 13:56:40 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_error	run_routine(t_philosopher *philosopher);
t_error	eat_routine(t_philosopher *philosopher);
t_error	sleep_routine(t_philosopher *philosopher);
t_error	think_routine(t_philosopher *philosopher);

/* 
	- Delegates starting philosophers
	- Runs the philosophers routines
	- Writes the error and error code if an error occurs
*/

void	*philosopher_routine(void *thread_arg)
{
	t_philosopher	*philosopher;
	t_whiteboard	*whiteboard;
	t_error			error_code;
	int				i;

	i = 0;
	philosopher = (t_philosopher *)thread_arg;
	whiteboard = philosopher->check_whiteboard_ptr;
	while (whiteboard->event_start == FALSE)
		usleep(200);
	if (philosopher->id % 2 != 0)
		think_routine(philosopher);
	while (i < philosopher->check_whiteboard_ptr->times_to_eat
		|| philosopher->check_whiteboard_ptr->is_dead == FALSE)
	{
		error_code = run_routine(philosopher);
		if (error_code != SUCCESS)
		{
			write_error_code(error_code);
			return (NULL);
		}
		i++;
	}
	return (NULL);
}

t_error	run_routine(t_philosopher *philosopher)
{
	t_error	error_code;

	error_code = eat_routine(philosopher);
	if (error_code != SUCCESS)
	{
		write(2, "Eat routine error with error code: ", 36);
		return (error_code);
	}
	error_code = sleep_routine(philosopher);
	if (error_code != SUCCESS)
	{
		write(2, "Sleep routine error with error code: ", 38);
		return (error_code);
	}
	error_code = think_routine(philosopher);
	if (error_code != SUCCESS)
	{
		write(2, "Thinking routine error with error code: ", 41);
		write(2, ft_itoa(error_code), 2);
		return (error_code);
	}
	return (SUCCESS);
}

//To do: 
t_error	eat_routine(t_philosopher *philosopher)
{
	t_error	error_code;

	if (pthread_mutex_lock(philosopher->left_fork_ptr) != SUCCESS)
		return (MUTEX_LOCK_ERROR);
	error_code = print_action(philosopher, "has taken a fork");
	if (error_code != SUCCESS)
		return (error_code);
	if (pthread_mutex_lock(philosopher->right_fork_ptr) != SUCCESS)
		return (MUTEX_LOCK_ERROR);
	error_code = print_action(philosopher, "has taken a fork");
	if (error_code != SUCCESS)
		return (error_code);
	error_code = print_action(philosopher, "is eating");
	if (error_code != SUCCESS)
		return (error_code);
	usleep(philosopher->check_whiteboard_ptr->time_to_eat * 1000);
	philosopher->time_last_ate = gettimeofday(&time, NULL);
	if (pthread_mutex_unlock(philosopher->left_fork_ptr) != SUCCESS)
		return (MUTEX_UNLOCK_ERROR);
	if (pthread_mutex_unlock(philosopher->right_fork_ptr) != SUCCESS)
		return (MUTEX_UNLOCK_ERROR);
	return (SUCCESS);
}

t_error	sleep_routine(t_philosopher *philosopher)
{
	t_error	error_code;

	if (check_if_dead(philosopher, philosopher->check_whiteboard_ptr->time_to_sleep) == TRUE)
		return (SUCCESS);
	error_code = print_action(philosopher, "is sleeping");
	if (error_code != SUCCESS)
		return (error_code);
	usleep((unsigned int)(philosopher->check_whiteboard_ptr->time_to_sleep * 1000));
	return (SUCCESS);
}


t_error	think_routine(t_philosopher *philosopher)
{
	t_error	error_code;

	error_code = print_action(philosopher, "is thinking");
	if (error_code != SUCCESS)
		return (error_code);
	return (SUCCESS);
}
