/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:03:31 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/03 15:46:21 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <unistd.h>

int	ft_print_hex(unsigned long nb, char specifier)
{
	int		remainder;
	char	number;
	int		count;

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
			count += ft_putnbr_fd(nb, 1);
		else
		{
			number = nb + 55;
			if (specifier == 'x')
				number = nb + 87;
			count += write(1, &number, 1);
		}
	}
	return (count);
}

// int	main(void)
// {
// 	printf("\nhex: %x\n", 6);
// 	ft_print_hex(6, 'x');

// 	printf("\nhex: %x\n", 10);
// 	ft_print_hex(10, 'x');

// 	printf("\nhex: %x\n", 13);
// 	ft_print_hex(13, 'x');

// 	printf("\nhex: %x\n", 20);
// 	ft_print_hex(20, 'x');

// 	printf("\nhex: %x\n", 255);
// 	ft_print_hex(255, 'x');

// 	printf("\nhex: %X\n", 255);
// 	ft_print_hex(255, 'X');
// }