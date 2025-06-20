/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 12:32:02 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/20 11:12:33 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Finds the length of a string */

size_t	ft_strlen(const char *string)
{
	int	length;

	length = 0;
	while (string[length])
		length++;
	return (length);
}
