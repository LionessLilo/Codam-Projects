/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 09:29:12 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/10 10:38:56 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	ft_free(char **memory)
{
	free(*memory);
	*memory = (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == uc)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (uc == '\0')
	{
		while (s[i] != '\0')
		{
			i++;
		}
		return ((char *)s + i);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!ptr)
		return (NULL);
	s3 = ptr;
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	*s3 = '\0';
	return (ptr);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*pntr;
	size_t	i;

	pntr = malloc(num * size);
	if (pntr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < num * size)
	{
		((unsigned char *)pntr)[i] = '\0';
		i++;
	}
	return (pntr);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
