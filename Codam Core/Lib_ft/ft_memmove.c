/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 12:15:26 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/14 15:34:34 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*char_dest;
	const char	*char_src;
	size_t		i;

	char_dest = (char *)dest;
	char_src = (const char *)src;
	if (char_dest > char_src && char_dest < char_src + n)
	{
		i = n;
		while (i > 0)
		{
			i--;
			char_dest[i] = char_src[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			char_dest[i] = char_src[i];
			i++;
		}
	}
	return (dest);
}
