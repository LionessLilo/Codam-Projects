/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:45 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/12 12:59:18 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/* Cleans up the argv list and sets the pointer to NULL */

void	cleanup_list(char **list)
{
	char	**list_start;

	list_start = list;
	while (*list)
	{
		free_and_null(&(*list));
		list++;
	}
	free_and_null(&(*list_start));
}

/*
	Cleans the heap memory of the whiteboard and philosophers.
	Sets the pointers to NULL
*/
void	clean_whiteboard(t_whiteboard **whiteboard)
{
	if (!whiteboard || !*whiteboard)
		return ;
	if ((*whiteboard)->protect_forks_ptr)
		clean_forks(whiteboard);
	pthread_mutex_destroy(&(*whiteboard)->protect_print);
	pthread_mutex_destroy(&(*whiteboard)->protect_door);
	pthread_mutex_destroy(&(*whiteboard)->protect_dead);
	if ((*whiteboard)->philosophers)
		free((*whiteboard)->philosophers);
	free_and_null((void *)&(*whiteboard));
}

void	write_error(char *message, int error_code)
{
	char	*error_to_write;

	write(2, "Error ", 7);
	error_to_write = ft_itoa(error_code);
	write(2, error_to_write, ft_strlen(error_to_write));
	write(2, ": ", 2);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	free(error_to_write);
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
		usleep((unsigned int)(((time_last_ate_ms + whiteboard->time_to_die) - current_time_ms)
			* 1000));
	pthread_mutex_lock(&whiteboard->protect_dead);
	if (whiteboard->is_dead == FALSE)
	{
		print_action(philosopher, "died");
		whiteboard->is_dead = TRUE;
	}
	pthread_mutex_unlock(&whiteboard->protect_dead);
}
