/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/25 11:47:32 by lilo          #+#    #+#                 */
/*   Updated: 2024/09/25 17:51:36 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		number;
	int		remainder;
	char	print_number;

	number = nb;
	while (number / 10)
	{
		remainder = number % 10;
		print_number = remainder + '0';
		write(1, &print_number, 1);
		number = number / 10;
		// printf("dbug: %d\n", number);
	}
}

int	main(void)
{
	ft_putnbr(321);
	return (0);
}
