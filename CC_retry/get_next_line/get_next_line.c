/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/18 15:34:44 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/18 19:21:59 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char		*fetch_line(int fd, char *leftover);
char		*extract_line(t_buffer *list);
t_buffer	*create_node(void);
char		*leftover_and_clean(char *fetched_line);

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*fetched_line;
	char		*return_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!leftover)
	{
		leftover = empty_string();
		if (!leftover)
			return (NULL);
	}
	fetched_line = fetch_line(fd, leftover);
	if (!fetched_line)
		return (free(leftover), NULL);
	i = 0;
	while (fetched_line[i] && fetched_line[i] != '\n')
	{
		return_line[i] = fetched_line[i];
		i++;
	}
	return_line[i] = '\0';
	leftover = leftover_and_clean(fetched_line);
	return (return_line);
}

char	*fetch_line(int fd, char *leftover)
{
	t_buffer	*buffer_list;
	t_buffer	*new_node;
	int			bytes_read;
	char		*str;
	char		*return_str;

	new_node = create_node();
	buffer_list = new_node;
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(new_node->buffer, '\n'))
	{
		bytes_read = 0;
		bytes_read = read(fd, new_node->buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_list(buffer_list), NULL);
		if (ft_strchr(new_node->buffer, '\n'))
			continue ;
		new_node->next = create_node();
		new_node = new_node->next;
	}
	str = extract_line(buffer_list);
	free_list(buffer_list);
	return_str = ft_strjoin(leftover, str);
	return (return_str);
}

char	*extract_line(t_buffer *list)
{
	char	*str;

	while (list)
	{
		str = ft_strjoin(str, list->buffer);
		list = list->next;
	}
	return (str);
}

/*
	Creates a new linked list node. I need to free the node and contents
	on cleanup.
*/

t_buffer	*create_node(void)
{
	t_buffer	*new_node;

	new_node = malloc(sizeof(t_buffer));
	if (!new_node)
		return (NULL);
	new_node->buffer[0] = '\0';
	new_node->next = NULL;
	return (new_node);
}

char	*leftover_and_clean(char *fetched_line)
{
	int		i;
	int		i_leftover;
	char	*leftover;

	i = 0;
	while (*fetched_line && *fetched_line != '\n')
		fetched_line++;
	if (*fetched_line == '\n')
	{
		fetched_line++;
		leftover = malloc(sizeof(char *) * ft_strlen(fetched_line));
		if (!leftover)
			return (free(fetched_line), NULL);
		while (fetched_line[i])
		{
			leftover[i] = fetched_line[i];
			i_leftover++;
			i++;
		}
		return (leftover);
	}
	return (NULL);
}
