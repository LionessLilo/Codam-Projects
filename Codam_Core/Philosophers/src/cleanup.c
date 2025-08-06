/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/17 12:29:45 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/06 12:22:50 by lilo          ########   odam.nl         */
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
	free_and_null((void *)&(*whiteboard));
}

/* Writes the error code and cleans up the itoa. */
void	write_error_code(t_error error_code)
{
	char	*error_message;
	write(2, "An error occurred with error code: ", 35);
	error_message = ft_itoa(error_code);
	write(2, error_message, ft_strlen(error_message));
	write(2, "\n", 1);
	free_and_null((void *)&error_code);
}