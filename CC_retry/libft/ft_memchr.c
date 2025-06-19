/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 19:32:30 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/19 13:32:25 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *str, 
					int byte, 
					size_t size)
{
	size_t		i;
	const char	*cc_str;

	i = 0;
	if (size == 0)
		return (NULL);
	cc_str = (const char *)str;
	while (i < size)
	{
		if (*cc_str == byte)
			return ((void *)cc_str);
		cc_str++;
		i++;
	}
	return (NULL);
}
