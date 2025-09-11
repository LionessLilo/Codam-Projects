/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/10 14:12:09 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/10 15:23:48 by lilo          ########   odam.nl         */
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