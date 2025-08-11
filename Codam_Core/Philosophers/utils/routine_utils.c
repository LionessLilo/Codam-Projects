/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/05 12:19:06 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/11 17:22:11 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	print_action(t_philosopher *philosopher, char *action)
{
	if (pthread_mutex_lock(&philosopher->check_whiteboard_ptr->protect_print) != 0)
		return (write_error("Print mutex failed to lock", 7), -1);
	printf("%ld %s\n", philosopher->id, action);
	if (pthread_mutex_unlock(&philosopher->check_whiteboard_ptr->protect_print) != 0)
		return (write_error("Print mutex failed to unlock", 7), -1);
	return (0);
}