/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 16:09:42 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/21 17:30:57 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ns;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	ns = malloc(sizeof(char) * (ft_strlen((char *)s)));
	if (!ns)
		return (NULL);
	while (s[i] != '\0')
	{
		ns[i] = f(i, s[i]);
		i++;
	}
	ns[i] = '\0';
	return (ns);
	free(ns);
}
