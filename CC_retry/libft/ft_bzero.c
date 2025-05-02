/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 14:15:47 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/02 14:35:29 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_bzero(void *memory, size_t size)
{
	size_t			i;
	unsigned char	*uc_buffer;

	i = 0;
	uc_buffer = (unsigned char *)memory;
	while (i < size)
	{
		uc_buffer[i] = '\0';
		i++;
	}
}
