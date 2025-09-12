/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:45 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/12 18:15:25 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	clean_whiteboard(t_whiteboard **whiteboard);
void	write_error(char *message, int error_code);

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

/*
	Cleans the heap memory of the whiteboard and philosophers.
	Sets the pointers to NULL
*/
void	clean_whiteboard(t_whiteboard **whiteboard)
{
	if (!whiteboard || !*whiteboard)
		return ;
	if ((*whiteboard)->protect_forks_ptr)
		clean_forks(whiteboard);
	pthread_mutex_destroy(&(*whiteboard)->protect_print);
	pthread_mutex_destroy(&(*whiteboard)->protect_door);
	pthread_mutex_destroy(&(*whiteboard)->protect_dead);
	if ((*whiteboard)->philosophers)
		free((*whiteboard)->philosophers);
	free_and_null((void *)&(*whiteboard));
}

void	write_error(char *message, int error_code)
{
	char	*error_to_write;

	write(2, "Error ", 7);
	error_to_write = ft_itoa(error_code);
	write(2, error_to_write, ft_strlen(error_to_write));
	write(2, ": ", 2);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	free(error_to_write);
}
