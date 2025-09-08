/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:26:21 by llourens      #+#    #+#                 */
/*   Updated: 2025/09/05 16:46:26 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	ft_free(char **memory)
{
	if (*memory)
	{
		free(*memory);
		*memory = NULL;
	}
}

char	*get_next_line(int fd)
{
	t_retrieved	*buffer_node;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	check_first_node();
	if (!buffer_node)
		new_gnl();
	
	
}

t_retrieved	*new_gnl(void)
{
	t_retrieved	*new_node;

	new_node = malloc(sizeof(t_retrieved));
	if (!new_node)
		return (NULL);
	new_node->buffer = malloc(BUFFER_SIZE + 1);
	if (!new_node->buffer)
	{
		free(new_node);
		return (NULL);
	}
	new_node->size = 0;
	new_node->next = NULL;
	return (new_node);
}
