/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 18:22:28 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/06 19:15:21 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_strncmp(const char *str_1, const char *str_2, size_t size)
{
	size_t	i;

	i = 0;
	while ((str_1[i] && str_2[i]) && i < size)
	{
		if (str_1[i] < str_2[i])
			return (str_1[i] - str_2[i]);
		if (str_1[i] > str_2[i])
			return (str_1[i] - str_2[i]);
		i++;
	}
	return (i);
}
