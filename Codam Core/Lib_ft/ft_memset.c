/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 17:07:55 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/09 18:01:50 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// memset(memory, value, bytes)
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	*memset(void *s, int c, size_t n);
{
	int	i;

	i = 0;
	while (i <= n)
	{
		s[i] = c;
		printf("%d", s[i]);
		i++;
	}
}

int	main(void)
{
	int	*s = 'd';
	int		c = 'A';
	size_t	n = 4;

	ft_memset(s, c, n);
	return (0);
}
