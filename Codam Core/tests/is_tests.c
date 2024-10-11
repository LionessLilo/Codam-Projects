/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_tests.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 17:00:10 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/11 10:48:47 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int	main(void)
{
	int	c = 'H';

	printf("%c", ft_toupper(c));
	return (0);
}
