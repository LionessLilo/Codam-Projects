/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/25 11:47:32 by lilo          #+#    #+#                 */
/*   Updated: 2024/09/27 11:00:12 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		number;
	int		remainder;
	char	print_number;
	char	unit;
	char	print_unit;

	number = nb;
	while (number / 10)
	{
		remainder = number % 10;
		print_number = remainder + '0';
		write(0, &print_number, 1);
		number = number / 10;
	}
	unit = number % 10;
	print_unit = unit + '0';
	write(0, &print_unit, 1);
}

int	main(void)
{
	ft_putnbr(321);
	return (0);
}
