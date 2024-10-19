/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/20 00:38:11 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/20 00:50:44 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		number;
	int		remainder;
	char	*num_to_str_tens;
	char	unit;
	char	*num_to_str_units;

	number = nb;
	while (number / 10)
	{
		remainder = number % 10;
		num_to_str_tens = remainder + '0';
		number = number / 10;
	}
	unit = number % 10;
	num_to_str_units = unit + '0';
}
