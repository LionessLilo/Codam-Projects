/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/18 16:07:45 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/19 12:09:49 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int chr);
size_t	ft_strlen(const char *string);
void	free_list(t_buffer *list);
char	*ft_strjoin(char const *str1, char const *str2);

/* Creates an empty string */

char	*empty_string(void)
{
	char	*empty_str;

	empty_str = malloc(sizeof(char *));
	if (!empty_str)
		return (NULL);
	empty_str = "";
	return (empty_str);
}

/* Returns a pointer to the first occurance of the character in the string */

char	*ft_strchr(const char *str, int chr)
{
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)chr)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)chr == '\0')
		return ((char *)str);
	return (NULL);
}

/* Frees the linked list and its contents */

void	free_list(t_buffer *list)
{
	t_buffer	*temp;

	if (!list)
		return ;
	while (list)
	{
		temp = (list)->next;
		free(list->buffer);
		free(list);
		list = temp;
	}
}

/*
	Creates a new string and joins the two strings in the new string.
	You will need to free the resulting string when you call the function.
*/

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*new_string;
	char	*start_newstr;

	if (!str1 || !str2)
		return (NULL);
	new_string = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_string)
		return (NULL);
	start_newstr = new_string;
	while (*str1)
	{
		*new_string = *str1;
		new_string++;
		str1++;
	}
	while (*str2)
	{
		*new_string = *str2;
		new_string++;
		str2++;
	}
	*new_string = '\0';
	return (start_newstr);
}

size_t	ft_strlen(const char *string)
{
	size_t	length;

	length = 0;
	while (string[length])
		length++;
	return (length);
}
