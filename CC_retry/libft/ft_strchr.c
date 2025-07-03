/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 14:54:14 by llourens      #+#    #+#                 */
/*   Updated: 2025/07/03 13:52:41 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

/* Returns a pointer to the first occurance of the character in the string */

char	*ft_strchr(const char *str,
					int chr)
{
	while (*str >= '\0' && (unsigned char)*str != (unsigned char)chr)
		str++;
	if (*str >= '\0' && (unsigned char)*str == (unsigned char)chr)
		return ((char *)str);
	
	return (NULL);
}
