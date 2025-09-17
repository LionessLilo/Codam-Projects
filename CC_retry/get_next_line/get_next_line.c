/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:26:21 by llourens      #+#    #+#                 */
/*   Updated: 2025/09/17 14:37:09 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_buffer	*create_node(int fd);
t_buffer	*read_and_fill(int fd);
char		*get_line(t_buffer *fetched_list);

char	*get_next_line(int fd)
{
	static t_buffer	*existing_list;
	t_buffer		*fetched_list;
	char			*return_line;
	char			*fetched_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fetched_list = read_and_fill(fd);
	if (!fetched_list)
		return (NULL);
	fetched_line = get_line(fetched_list);
	if (existing_list->contents)
		return_line = ft_strjoin(existing_list->contents, fetched_line);
	else
		return_line = fetched_line;
	
	
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
	new_node->contents[0] = '\0';
	new_node->next = NULL;
	return (new_node);
}

t_buffer	*read_and_fill(int fd)
{
	t_buffer	*new_node;
	t_buffer	*list_start;
	int			chars_read;

	new_node = create_node(fd);
	if (!new_node)
		return (NULL);
	list_start = new_node;
	chars_read = 1;
	while (chars_read > 0 && !ft_strchr(new_node->contents, '\n'))
	{
		chars_read = read(fd, new_node->contents, BUFFER_SIZE);
		if (chars_read == -1)
			return (free(new_node->contents), free(new_node), NULL);
		new_node->contents[chars_read] = '\0';
		if (!ft_strchr(new_node->contents, '\n') && chars_read > 0)
		{
			new_node->next = create_node(fd);
			new_node = new_node->next;
		}
	}
	return (list_start);
}

char	*get_line(t_buffer *fetched_list)
{
	int		i_returnline;
	int		i_node;
	char	*return_line;

	i_returnline = 0;
	i_node = 0;
	while(fetched_list->next)
	{
		while (fetched_list->contents[i_node] && fetched_list->contents[i_node] != '\n')
		{
			return_line[i_returnline] = fetched_list->contents[i_node];
			i_returnline++;
			i_node++;
		}
		fetched_list = fetched_list->next;
		i_node = 0;
	}
	return_line[i_returnline] = '\0';
	return (return_line);
}
