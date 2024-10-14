/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/14 15:46:54 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/14 16:15:09 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	atoi(const char *nptr)
{
	int		i;
	int		is_printable;
	int		isa_digit;
	char	os;

	while (i != 0)
	{
		is_printable = ft_isprint(nptr);
		if (is_printable != 0)
		{
			if (nptr[i] == '+' || nptr[i] == '-')
			{
				os = nptr[i];
				write(1, os, 1);
				i++;
			}
			isa_digit = ft_isdigit(nptr);
			if (isa_digit != 0)
			{
				
			}
		}
		i++;
	}
	return ();
}
