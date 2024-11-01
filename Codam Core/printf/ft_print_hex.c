/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:03:31 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/01 15:23:30 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_hex(unsigned long nb)
{
	int		remainder;
	char *	hex_string;

	if (nb >= 16)
	{
		nb = ft_print_hex(nb / 16);
		remainder = ft_print_hex(nb % 16);
		if (remainder <= 9)
			{
				hex_string = remainder + '0';
			}
	}
	if (nb <= 9)
}
