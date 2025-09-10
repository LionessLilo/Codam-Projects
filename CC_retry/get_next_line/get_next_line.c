/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:26:21 by llourens      #+#    #+#                 */
/*   Updated: 2025/09/10 13:54:32 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

t_buffer	*create_list(int fd);

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
	static t_buffer	*existing_list;
	t_buffer		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!existing_list)
	{
		existing_list = create_list(fd);
		if (!existing_list)
			return (NULL);
	}
}

t_buffer	*create_list(int fd)
{
	t_buffer	*new_list;

	new_list = malloc(sizeof(t_buffer));
	if (!new_list)
		return (NULL);
	new_list->fd = fd;
	new_list->next = NULL;
	return (new_list);
}
