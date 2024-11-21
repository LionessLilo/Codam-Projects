/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/21 10:46:11 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/21 19:40:01 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ns;
	size_t			i;

	i = 0;
	ns = (unsigned char *)s;
	while (i < n)
	{
		ns[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*pntr;

	pntr = malloc(num * size);
	if (pntr == NULL)
	{
		return (NULL);
	}
	ft_bzero(pntr, num * size);
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

char	*read_file(int fd)
{
	char	*cup_buffer;
	int		bytes_read;

	cup_buffer = ft_calloc(BUFFER_SIZE +1, sizeof(char));
	if (!cup_buffer)
	{
		printf("could not malloc cup_buffer");
		return (free(cup_buffer), NULL);
	}
	bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		if (bytes_read < 0)
		{
			printf("could not read file or is EOF");
			return (free(cup_buffer), NULL);
		}
		return (free(cup_buffer), NULL);
	}
	return (cup_buffer);
}
