/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 14:54:14 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/06 15:08:35 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strchr(const char *str, int chr)
{
	while (*str && *str != chr)
		str++;
	if (*str && *str == chr)
		return ((char *)str);
	return (NULL);
}
