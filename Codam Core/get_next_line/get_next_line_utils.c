/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/21 09:26:50 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/21 09:28:29 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static void	ft_bzero(void *s, size_t n)
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