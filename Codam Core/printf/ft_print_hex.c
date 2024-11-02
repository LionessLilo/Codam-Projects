/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:03:31 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/02 16:29:18 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_print_hex(unsigned long nb)
{
	int		remainder;
	char	*hex_string;

	if (nb >= 16)
	{
		// nb = ft_print_hex(nb / 16);
		// remainder = ft_print_hex(nb % 16);
	}
	else
	{
		if (nb <= 9)
		{
			printf("%ld", nb);
		}
	}
	// if (remainder <= 9)
	// 	ft_print_number(remainder);
	// if (remainder > 9 && remainder <= 15)

	return (0);
}
int	main(void)
{
	printf("\nhex: %x\n", 6);
	ft_print_hex(6);

	printf("\nhex: %x\n", 10);
	ft_print_hex(10);
}