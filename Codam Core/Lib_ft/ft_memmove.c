/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 12:15:26 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/10 17:05:30 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(n);
	while (i < n)
	{
		temp[i] = ((unsigned char *)src)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = temp[i];
		i++;
	}
	free(temp);
	return (dest);
}
