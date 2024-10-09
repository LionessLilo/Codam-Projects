/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 17:00:10 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/09 17:03:00 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int	main(void)
{
	char	*s = "Hello";

	printf("%d", ft_strlen(s));
	return (0);
}
