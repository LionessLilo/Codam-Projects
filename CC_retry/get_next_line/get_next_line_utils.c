/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/10 14:12:09 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/17 14:16:37 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **memory)
{
	if (*memory)
	{
		free(*memory);
		*memory = NULL;
	}
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*s3;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	ptr = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!ptr)
	{
		return (NULL);
	}
	s3 = ptr;
	while (*s1)
	{
		*s3++ = *s1++;
	}
	while (*s2)
	{
		*s3++ = *s2++;
	}
	*s3 = '\0';
	return (ptr);
}