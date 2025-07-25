/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_up_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/24 16:28:04 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/24 17:44:24 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	free_and_null(void *incoming_memory)
{
	void	**memory;

	memory = (void **)incoming_memory;
	if (*memory)
	{
		free(*memory);
		*memory = NULL;
	}
}

void	clean_forks(t_whiteboard **whiteboard)
{
	size_t	i;

	i = 0;
	while (i < (*whiteboard)->nbr_philosophers)
	{
		pthread_mutex_destroy(&(*whiteboard)->protect_forks_ptr[i]);
		i++;
	}
	free_and_null((void **)&(*whiteboard)->protect_forks_ptr);
}
