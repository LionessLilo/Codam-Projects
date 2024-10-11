/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 17:07:55 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/11 10:42:28 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ns;

	ns = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ns[i] = (unsigned char)c;
		write(1, &ns[i], 1);
		i++;
	}
	return (s);
}