/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:45 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/26 11:19:46 by lilo          ########   odam.nl         */
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
	long			last_ate_ms;
	long			time_dead_ms;
	t_time			now_time;
	long			current_time_ms;
	t_whiteboard	*whiteboard;

	whiteboard = philosopher->check_whiteboard_ptr;
	last_ate_ms = (philosopher->time_last_ate.tv_sec * 1000)
		+ (philosopher->time_last_ate.tv_usec / 1000);
	time_dead_ms = last_ate_ms + whiteboard->time_to_die;
	gettimeofday(&now_time, NULL);
	current_time_ms = (now_time.tv_sec * 1000) + (now_time.tv_usec / 1000);
	pthread_mutex_lock(&whiteboard->protect_dead);
	if (whiteboard->is_dead)
		return (pthread_mutex_unlock(&whiteboard->protect_dead), (void)0);
	pthread_mutex_unlock(&whiteboard->protect_dead);
	if (time_dead_ms > current_time_ms)
		usleep((unsigned)(time_dead_ms - current_time_ms) * 1000);
	pthread_mutex_lock(&whiteboard->protect_dead);
	if (!whiteboard->is_dead)
	{
		print_action(philosopher, "died");
		whiteboard->is_dead = TRUE;
	}
	pthread_mutex_unlock(&whiteboard->protect_dead);
}
