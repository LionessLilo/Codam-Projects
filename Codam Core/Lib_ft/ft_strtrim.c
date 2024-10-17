/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/16 11:29:12 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/17 09:09:37 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	is_illegal(char c, char const *set)
{
	int		set_index;
	int		len_set;

	set_index = 0;
	len_set = ft_strlen((char *)set);
	while (set_index < len_set)
	{
		if (set[set_index] == c)
		{
			return (1);
		}
		set_index++;
	}
	return (0);
}

static int	start_trim(char const *s1, char const *set,	int length_of_string)
{
	int		current_index;
	int		start_of_where_we_are_copying;

	start_of_where_we_are_copying = 0;
	current_index = 0;
	while (current_index < length_of_string)
	{
		if (is_illegal(s1[current_index], set) == 0)
		{
			start_of_where_we_are_copying = current_index;
			break ;
		}
		current_index++;
	}
	return (start_of_where_we_are_copying);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_cpy;
	int		end_cpy;
	int		len_str;
	int		current_index;
	char	*new_trimmed;

	len_str = ft_strlen((char *)s1);
	start_cpy = start_trim(s1, set, len_str);
	end_cpy = len_str;
	current_index = 0;
	while (current_index < len_str)
	{
		if (is_illegal(s1[len_str - (current_index + 1)], set) == 0)
		{
			end_cpy = len_str - (current_index + 1);
			break ;
		}
		current_index++;
	}
	new_trimmed = malloc(sizeof(char) * (end_cpy - start_cpy + 1));
	ft_strlcpy(new_trimmed, s1 + start_cpy, (size_t)(end_cpy - start_cpy + 1));
	return (new_trimmed);
	free(new_trimmed);
}
