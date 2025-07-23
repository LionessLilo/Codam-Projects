/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:45 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/23 15:20:35 by lionesslilo   ########   odam.nl         */
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

void	clean_whiteboard(t_whiteboard **whiteboard)
{
	int	i;
	
	i = 0;
	if (!whiteboard)
		return ;
	if ((*whiteboard)->protect_forks_ptr)
	{
		while (i < (*whiteboard)->nbr_philosophers)
		{
			pthread_mutex_destroy(&(*whiteboard)->protect_forks_ptr[i]);
			i++;
		}
		free((*whiteboard)->protect_forks_ptr);
	}
}
