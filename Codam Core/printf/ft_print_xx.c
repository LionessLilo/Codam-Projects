/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_xx.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:03:31 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/12 15:14:34 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

static int	ft_putnbr(unsigned int n, int fd)
{
	char	str;
	int		count;

	count = 0;
	if (n >= 10)
	{
		ft_putnbr(n / 10, fd);
		str = '0' + n % 10;
	}
	else
		str = '0' + n;
	count += write(fd, &str, 1);
	return (count);
}

int	ft_print_xx(unsigned long int nb, char specifier)
{
	char	number;
	int		count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_print_xx(nb / 16, specifier);
		count += ft_print_xx((nb % 16), specifier);
		return (count);
	}
	if (nb <= 9)
		return (count + ft_putnbr(nb, 1));
	number = nb + 55;
	if (specifier == 'x')
		number = nb + 87;
	count += write(1, &number, 1);
	return (count);
}
// 	int main(void)
// {
// 	int	count = 0;
// 	// Hex
// 	printf("\nhex: %x\n", 6);
// 	ft_print_xx(6, 'x');

// 	printf("\nhex: %x\n", 10);
// 	ft_print_xx(10, 'x');

// 	printf("\nhex: %x\n", 13);
// 	ft_print_xx(13, 'x');

// 	printf("\nhex: %x\n", 20);
// 	ft_print_xx(20, 'x');

// 	printf("\nhex: %x\n", 255);
// 	ft_print_xx(255, 'x');

// 	printf("\nhex: %X\n", 255);
// 	count = ft_print_xx(255, 'X');
// 	printf("\n%d", count);

// 	printf("\nhex: %X\n", 2147483647);
// 	count = ft_print_xx(2147483647, 'X');
//     return (0);
// }