/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 13:42:38 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/23 18:45:41 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	int		str_len;

	if (!s)
	{
		return (0);
	}
	str_len = ft_strlen((char *)s);
	if ((unsigned int)str_len < start)
	{
		len = 0;
	}
	if (len && len > (size_t)ft_strlen((char *)s + start))
	{
		len = ft_strlen((char *)s + start);
	}
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
	{
		return (0);
	}
	if (!len)
		return (ft_calloc(1, sizeof(char)));
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
