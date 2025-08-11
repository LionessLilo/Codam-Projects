/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:45 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/11 17:18:23 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/* Cleans up the argv list and sets the pointer to NULL */

void	cleanup_list(char **list)
{
	char	**list_start;

	list_start = list;
	while (*list)
	{
		free_and_null(&(*list));
		list++;
	}
	free_and_null(&(*list_start));
}

/* Cleans the heap memory of the whiteboard and philosophers. Sets the pointers to NULL */
void	clean_whiteboard(t_whiteboard **whiteboard)
{
	if (!whiteboard || !*whiteboard)
		return ;
	if ((*whiteboard)->protect_forks_ptr)
		clean_forks(whiteboard);
	pthread_mutex_destroy(&(*whiteboard)->protect_print);
	pthread_mutex_destroy(&(*whiteboard)->protect_door);
	pthread_mutex_destroy(&(*whiteboard)->protect_dead);
	free_and_null((void *)&(*whiteboard));
}

void	write_error(char *message, int error_code)
{
	char	*error_to_write;

	write(2, "Error ", 8);
	error_to_write = ft_itoa(error_code);
	write(2, &error_to_write, ft_strlen(error_to_write));
	write(2, ": ", 1);
	write(2, &message, ft_strlen(message));
}