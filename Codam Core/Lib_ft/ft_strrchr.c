/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 11:53:28 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/11 12:06:22 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i != 0)
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i--;
	}
	if (c == '\0')
	{
		return ((char *)s + i);
	}
	return (NULL);
}
