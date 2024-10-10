/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 09:33:50 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/10 10:07:55 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ns;
	size_t			i;

	i = 0;
	ns = (unsigned char *)s;
	while (i < n)
	{
		ns[i] = '\0';
		write(1, &ns[i], 1);
		i++;
	}
}
