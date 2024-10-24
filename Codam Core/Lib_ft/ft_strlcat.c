/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/24 14:59:39 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/24 15:44:06 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size_of_src;
	size_t	size_of_dst;

	size_of_src = ft_strlen(src);
	size_of_dst = ft_strlen(dst);
	if (!dst || !src)
		return (NULL);
	while (size_of_dst < dstsize)
	{
		
	}

}
