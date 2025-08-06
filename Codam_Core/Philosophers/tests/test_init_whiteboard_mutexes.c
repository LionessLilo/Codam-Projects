/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_init_whiteboard_mutexes.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lionesslilo <lionesslilo@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/23 16:15:05 by lionesslilo   #+#    #+#                 */
/*   Updated: 2025/08/06 17:22:07 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include "tests.h"

void	test_init_whiteboard_mutexes(void)
{
	t_error			error_check;
	int				funct_return;
	t_whiteboard    *whiteboard;
	size_t				i;

	whiteboard = malloc(sizeof(t_whiteboard));
	whiteboard->nbr_philosophers = 5;
	error_check = init_whiteboard_mutexes(whiteboard);
	log_test(error_check == SUCCESS, ft_itoa(error_check));

	i = 0;
	while (i < whiteboard->nbr_philosophers)
	{
		funct_return = pthread_mutex_lock(&whiteboard->protect_forks_ptr[i]);
		if (funct_return != 0)
			log_error(ft_itoa(MUTEX_LOCK_ERROR));
		funct_return = pthread_mutex_unlock(&whiteboard->protect_forks_ptr[i]);
		if (funct_return != 0)
			log_error(ft_itoa(MUTEX_UNLOCK_ERROR));
		i++;
	}
	log_tick();

	funct_return = pthread_mutex_lock(&whiteboard->protect_print);
	if (funct_return != 0)
			log_error(ft_itoa(MUTEX_LOCK_ERROR));
	funct_return = pthread_mutex_unlock(&whiteboard->protect_print);
	if (funct_return != 0)
			log_error(ft_itoa(MUTEX_UNLOCK_ERROR));
	log_tick();

	funct_return = pthread_mutex_lock(&whiteboard->protect_dead);
	if (funct_return != 0)
			log_error(ft_itoa(MUTEX_LOCK_ERROR));
	funct_return = pthread_mutex_unlock(&whiteboard->protect_dead);
	if (funct_return != 0)
			log_error(ft_itoa(MUTEX_UNLOCK_ERROR));
	log_tick();

	funct_return = pthread_mutex_lock(&whiteboard->protect_door);
	if (funct_return != 0)
			log_error(ft_itoa(MUTEX_LOCK_ERROR));
	funct_return = pthread_mutex_unlock(&whiteboard->protect_door);
	if (funct_return != 0)
			log_error(ft_itoa(MUTEX_UNLOCK_ERROR));
	log_tick();
	clean_whiteboard(&whiteboard);
}
