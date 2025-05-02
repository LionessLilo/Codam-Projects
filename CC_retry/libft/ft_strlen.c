/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 12:32:02 by llourens      #+#    #+#                 */
/*   Updated: 2025/05/02 17:28:08 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(const char *string)
{
	int	length;


	length = 0;
	while (string[length])
		length++;
	return (length);
}
