/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 09:29:12 by llourens      #+#    #+#                 */
/*   Updated: 2025/09/05 15:53:42 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *str1,
					char const *str2)
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

char	*ft_strdup(const char *string)
{
	size_t	str_len;
	char	*str_duplicated;
	char	*end;

	str_len = ft_strlen(string);
	str_duplicated = malloc(str_len + 1 * sizeof(char));
	if (!str_duplicated)
		return (NULL);
	ft_memcpy(str_duplicated, string, (str_len + 1));
	end = str_duplicated + str_len;
	*end = '\0';
	return (str_duplicated);
}

char	*ft_strchr(const char *str,
					int chr)
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

void	*ft_memset(void *memory,
					int filler,
					size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (memory);
	while (i < size)
	{
		((unsigned char *)memory)[i] = (unsigned char)filler;
		i++;
	}
	return (memory);
}
