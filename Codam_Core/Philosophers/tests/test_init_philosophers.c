/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_init_philosophers.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 18:18:02 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/15 10:53:45 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include "./tests.h"

void	test_init_philosophers(void)
{
	t_whiteboard	*whiteboard;
	int				error;
	size_t			i;

	i = 0;
	whiteboard = malloc(sizeof(t_whiteboard));
	if (!whiteboard)
		exit (-1);
	whiteboard->nbr_philosophers = 5;
	whiteboard->protect_forks_ptr = malloc(sizeof(pthread_mutex_t)
			* whiteboard->nbr_philosophers);
	if (!whiteboard->protect_forks_ptr)
		log_error(ft_itoa(-1));
	init_forks(whiteboard);
	error = init_philosophers(whiteboard);
	printf("Runs without fail:\n");
	log_test(error == 0, ft_itoa(error));
	printf("\nInitialises the correct values:\n");
	while (i < whiteboard->nbr_philosophers)
	{
		printf("Philosopher id: %ld\n", whiteboard->philosophers->id);
		log_test(whiteboard->philosophers->time_last_ate == 0,
			"Time last ate is not correct");
		log_test(whiteboard->philosophers->nbr_meals_eaten == 0,
			"Nbr of meals eaten is not correct");
		log_test (pthread_mutex_lock(whiteboard->philosophers->left_fork_ptr)
			== 0, "Left fork did not initialise correctly");
		log_test (pthread_mutex_lock(whiteboard->philosophers->right_fork_ptr)
			== 0, "Right fork did not initialise properly");
		pthread_mutex_unlock(whiteboard->philosophers->left_fork_ptr);
		pthread_mutex_unlock(whiteboard->philosophers->right_fork_ptr);
		log_test(whiteboard->philosophers->check_whiteboard_ptr
			->nbr_philosophers == whiteboard->nbr_philosophers,
			"Check whiteboard does not work");
		printf("\n");
		whiteboard->philosophers++;
		i++;
	}
	clean_whiteboard(&whiteboard);
}
