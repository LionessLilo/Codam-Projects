/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_xx.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:03:31 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/04 09:00:37 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_print_xx(unsigned long nb, char specifier)
{
	int		remainder;
	char	number;

	if (nb >= 16)
	{
		remainder = nb % 16;
		nb = nb / 16;
		ft_print_hex(nb, specifier);
		ft_print_hex(remainder, specifier);
	}
	else
	{
		if (nb <= 9)
			ft_putnbr_fd(nb, 1);
		else
		{
			number = nb + 55;
			if (specifier == 'x')
				number = nb + 87;
			write(1, &number, 1);
		}
	}
	return (0);
}

