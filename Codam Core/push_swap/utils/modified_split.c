/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   modified_split.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/09 21:53:35 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/09 22:33:04 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/libft/libft.h"
#include "../includes/push_swap.h"
#include <stdlib.h>

static void	*free_mem(int list_item_index, char **list)
{
	while (list_item_index > 0)
	{
		list_item_index--;
		free(list[list_item_index]);
	}
	free(list);
	return (NULL);
}

static int	add_to_list(const char *s, char **list, char c, size_t *index)
{
	size_t		length;
	const char	*start;

	length = 0;
	start = s;
	while (s[length] && s[length] == c)
		length++;
	start += length;
	length = 0;
	while (s[length] && s[length] != c)
		length++;
	list[*index] = ft_substr(start, 0, length);
	if (!list[*index])
		return (0);
	(*index)++;
	return (1);
}

static size_t	count_words(const char *str, char separator)
{
	int		count;
	bool	is_inside_word;

	count = 0;
	while (*str)
	{
		is_inside_word = false;
		while (*str == separator)
			++str;
		while (*str != separator && *str)
		{
			if (!is_inside_word)
			{
				count++;
				is_inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

char	**ft_split(const char *str, char separator)
{
	char	**list;
	int		word_count;
	int		i;

	i = 0;
	word_count = count_words(str, separator);
	*list = malloc(sizeof(char *) * (word_count + 2));
	if (!*list)
		return (NULL);
	
}