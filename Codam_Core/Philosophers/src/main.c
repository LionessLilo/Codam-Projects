/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:47:54 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/29 09:32:37 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
	- Checks input
	- @whiteboard is a struct where the shared resources that 
	the philosophers can see
	- Initialises whiteboard struct
	- Starts the project
	- Handles bubbled up errors
	- Cleans up
*/

char	**create_argv(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_whiteboard	*whiteboard;
	int				error_check;
	char			**input_list;

	if (input_checks(argc, argv) == -1)
		return (41);
	input_list = create_argv(argc, argv);
	if (!input_list)
		return (write_error("Failed to create_argv", -1), -1);
	if (init_whiteboard(&whiteboard, input_list, argc) != 0)
	{
		cleanup_list(input_list);
		return (write_error("Failed to initiate whiteboard", -1), -1);
	}
	error_check = start_event(whiteboard);
	monitor_death(whiteboard);
	clean_whiteboard(&whiteboard);
	if (argc == 2)
		cleanup_list(input_list);
	return (error_check);
}

char	**create_argv(int argc, char **argv)
{
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv)
		return (NULL);
	return (argv);
}

void	monitor_death(t_whiteboard *whiteboard)
{
	pthread_t	monitor_thread;

	pthread_create(&monitor_thread, NULL, monitor_thread, whiteboard);
	pthread_join(&monitor_thread, NULL);
}

void	*monitor_thread(void *thread_arg)
{
	t_whiteboard	*whiteboard;
	int				i;
	t_time			current_time;
	unsigned int	current_time_ms;
	unsigned int	time_dead;

	i = 0;
	whiteboard = (t_whiteboard *)thread_arg;
	while (1)
	{
		while (i < whiteboard->nbr_philosophers)
		{
			if (whiteboard->is_dead == TRUE)
				return ;
			gettimeofday(&current_time, NULL);
			current_time_ms = (current_time.tv_sec * 1000)
				+ (current_time.tv_usec / 1000);
			time_dead = (whiteboard->philosophers[i].time_last_ate.tv_sec
					* 1000) + (whiteboard->philosophers[i].time_last_ate
					.tv_usec * 1000) + whiteboard->time_to_die;
			if (current_time_ms >= time_dead)
				return ;
		}
		usleep(10000 * 1000)
	}
}