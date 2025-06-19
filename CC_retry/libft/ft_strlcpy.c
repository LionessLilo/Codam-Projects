/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 15:34:57 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/19 15:03:47 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_strlcpy(char *dst,
				const char *src,
				size_t size)
{
	size_t	src_i;
	size_t	dest_i;
	size_t	src_len;

	src_i = 0;
	dest_i = 0;
	src = (char *)src;
	src_len = ft_strlen(src);
	if (src_len == 0)
		return (src_len);
	while (src[src_i] && src_i < (size - 1))
	{
		dst[dest_i] = src[src_i];
		src_i++;
		dest_i++;
	}
	dst[dest_i] = '\0';

	return (src_len);
}
