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
#include <stdlib.h>
#include <unistd.h>

int	is_min_int(int nm)
{
	if (nm == -2147483648)
	{
		write(1, "-2147483648", 11);
		exit(0);
	}
	if (nm < 0)
	{
		nm = -nm;
		write(1, "-", 1);
	}
	return (nm);
}

void	write_array(int i, char add_to_array[i])
{
	while (i >= 0)
	{
		write(1, &add_to_array[i], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	int		remainder;
	char	print_number;
	char	add_to_array[10];
	int		i;

	nb = is_min_int(nb);
	i = 0;
	while (nb / 10)
	{
		remainder = nb % 10;
		print_number = remainder + '0';
		add_to_array[i] = print_number;
		i++;
		nb = nb / 10;
	}
	remainder = nb % 10;
	print_number = remainder + '0';
	add_to_array[i] = print_number;
	write_array(i, add_to_array);
}

int	main(void)
{
	ft_putnbr(2147483647);
	return (0);
}
