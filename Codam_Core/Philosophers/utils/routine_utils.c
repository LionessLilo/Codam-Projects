/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/05 12:19:06 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/05 16:06:30 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_error	print_action(t_philosopher *philosopher, char *action)
{
	if (pthread_mutex_lock(&philosopher->check_whiteboard_ptr->protect_print) != 0)
		return (MUTEX_LOCK_ERROR);
	printf("%ld %s\n", philosopher->id, action);
	if (pthread_mutex_unlock(&philosopher->check_whiteboard_ptr->protect_print) != 0)
		return (MUTEX_UNLOCK_ERROR);
	return (SUCCESS);
}
