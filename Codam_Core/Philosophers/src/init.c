/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:28:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/17 18:12:59 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


t_whiteboard	*init_whiteboard(char **input_list)
{
	t_whiteboard	whiteboard;

	whiteboard.nbr_philosophers = input_list[1];
	whiteboard.time_to_die = input_list[2];
	whiteboard.time_to_eat = input_list[3];
	whiteboard.time_to_sleep = input_list[4];
	whiteboard.times_to_eat = input_list[5];

	return (0);
}
