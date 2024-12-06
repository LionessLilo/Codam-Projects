/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 17:10:26 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/06 17:10:29 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	void			*pntr;
	size_t			i;
	unsigned char	*ns;

	i = 0;
	pntr = malloc(num * size);
	if (pntr == NULL)
		return (NULL);
	ns = (unsigned char *)pntr;
	while (i < num * size)
	{
		ns[i] = '\0';
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*new_s;
	int		len_s;

	len_s = ft_strlen((char *)s);
	new_s = malloc (sizeof(char) * (len_s + 1));
	if (!new_s)
		return (NULL);
	ft_memcpy(new_s, s, len_s);
	new_s[len_s] = '\0';
	return (new_s);
}
