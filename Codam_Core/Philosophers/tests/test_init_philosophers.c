/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_init_philosophers.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 18:18:02 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/24 19:21:42 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include "./tests.h"

void	test_init_philosophers(void)
{
	t_whiteboard	*whiteboard;
	t_error			error;

	whiteboard = malloc(sizeof(t_whiteboard));
	if (!whiteboard)
		exit (MALLOC_FAIL);
	whiteboard->nbr_philosophers = 5;
	whiteboard->protect_forks_ptr = malloc(sizeof(pthread_mutex_t)
			* whiteboard->nbr_philosophers);
	if (!whiteboard->protect_forks_ptr)
		log_error(ft_itoa(MALLOC_FAIL));
	init_forks(whiteboard);
	error = init_philosophers(whiteboard);
	log_test(error == SUCCESS, ft_itoa(error));
}
