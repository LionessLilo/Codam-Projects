/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 14:32:50 by lilo          #+#    #+#                 */
/*   Updated: 2025/05/27 14:38:10 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
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
		dest[dest_i] = src[src_i];
		src_i++;
		dest_i++;
	}
	dest[dest_i] = '\0';
}
