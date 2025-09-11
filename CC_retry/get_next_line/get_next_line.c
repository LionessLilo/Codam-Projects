/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:26:21 by llourens      #+#    #+#                 */
/*   Updated: 2025/09/10 17:57:07 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_buffer	*create_node(int fd);
t_buffer	*read_and_fill(t_buffer *list);

char	*get_next_line(int fd)
{
	static t_buffer	*existing_list;
	t_buffer		*fetched_list;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!existing_list)
	{
		existing_list = create_node(fd);
		if (!existing_list)
			return (NULL);
	}
	fetched_list = read_and_fill(existing_list);
	if (!fetched_list)
		return (NULL);
}

t_buffer	*create_node(int fd)
{
	t_buffer	*new_node;

	new_node = malloc(sizeof(t_buffer));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->contents = malloc(BUFFER_SIZE + 1);
	if (!new_node->contents)
		return (free(new_node), NULL);
	new_node->contents = "";
	new_node->next = NULL;
	return (new_node);
}

t_buffer	*read_and_fill(t_buffer *list)
{
	t_buffer	*list_start;
	int			bytes_read;

	list_start = list
}
