/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:45 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/18 14:55:36 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	cleanup_list(char **list)
{
	char **list_start;

	list_start = list;
	while (*list)
	{
		free (*list);
		list++;
	}
	free (list_start);
}

// void	clean_whiteboard(t_whiteboard *s_whiteboard)
// {
	
// }
