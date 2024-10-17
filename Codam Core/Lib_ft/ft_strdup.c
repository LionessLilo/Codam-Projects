/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 11:13:55 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/15 12:48:37 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_s;
	int		len_s;

	len_s = ft_strlen((char *)s);
	new_s = (char *) malloc(8 * len_s);
	if (new_s == NULL)
	{
		return (NULL);
	}
	ft_memcpy(new_s, s, len_s);
	return (new_s);
}
