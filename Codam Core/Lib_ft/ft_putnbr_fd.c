/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 18:28:01 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/21 19:34:21 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		number;
	int		remainder;
	char	print_number;
	char	unit;
	char	print_unit;

	number = n;
	while (number / 10)
	{
		remainder = number % 10;
		print_number = remainder + '0';
		write(fd, &print_number, 1);
		number = number / 10;
	}
	unit = number % 10;
	print_unit = unit + '0';
	write(fd, &print_unit, 1);
}
