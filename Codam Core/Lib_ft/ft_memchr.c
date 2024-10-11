/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 17:30:25 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/11 18:11:24 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ns;
	size_t	i;

	ns = (char *)s;
	i = 0;
	while (i < n)
	{
		if (ns[i] == c)
		{
			return (ns + i);
		}
		i++;
	}
	return (NULL);
}
