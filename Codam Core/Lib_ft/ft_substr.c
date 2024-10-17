/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 13:42:38 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/17 09:30:53 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
	{
		return (0);
	}
	if (ft_strlen(s) < start)
	{
		len = 0;
	}
	if (ft_strlen(s + start) < len)
	{
		len = ft_strlen(s + start);
	}
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
	{
		return (0);
	}
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
