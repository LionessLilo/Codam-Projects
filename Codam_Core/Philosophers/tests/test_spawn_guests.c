/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_spawn_guests.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/31 11:32:51 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/18 11:36:32 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_spawn_guests(void)
{
	t_whiteboard	*whiteboard;
	int			error;

	whiteboard = malloc(sizeof(t_whiteboard));
	if (!whiteboard)
		exit (-1);
	whiteboard->nbr_philosophers = 3;
	whiteboard->time_to_die = 200;
	whiteboard->protect_forks_ptr = malloc(sizeof(pthread_mutex_t)
			* whiteboard->nbr_philosophers);
	if (!whiteboard->protect_forks_ptr)
		log_error(ft_itoa(-1));
	init_forks(whiteboard);
	error = init_philosophers(whiteboard);
	if (error != 0)
		log_error("Issue with init philosophers");
	pthread_mutex_init(&whiteboard->protect_door, NULL);
	error = spawn_guests(whiteboard);
	log_test(error == 0, ft_itoa(error));
	log_test(whiteboard->philosophers[0].id == 1
		&& whiteboard->philosophers[1].id == 2
		&& whiteboard->philosophers[2].id == 3,
		"Philosopher not inistialising with correct information");
	log_test(whiteboard->philosophers[0].check_whiteboard_ptr->time_to_die
		== 200
		&& whiteboard->philosophers[1].check_whiteboard_ptr->time_to_die == 200
		&& whiteboard->philosophers[2].check_whiteboard_ptr->time_to_die == 200,
		"Philosophers not initialised to check the whiteboard correctly");
}
