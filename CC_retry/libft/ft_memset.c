/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 12:48:30 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/02 13:59:34 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *memory, int filler, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)memory)[i] = (unsigned char)filler;
		i++;
	}
	return (memory);
}
