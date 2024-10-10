/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 17:00:10 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/10 07:28:19 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int	main(void)
{
	int	c = '\0';

	printf("%d", ft_isascii(c));
	return (0);
}
