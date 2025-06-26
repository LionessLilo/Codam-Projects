/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/20 11:24:33 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/26 12:00:16 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* Converts a string to in integer */

int	ft_atoi(const char *str)
{
	int	sign;
	int	nbr;
	int	is_digit;

	sign = 1;
	nbr = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r')
			str++;
		is_digit = ft_isdigit(*(str + 1));
		if (*str == '-' && is_digit == 1)
			sign = -1;
		if ((*str == '+' || *str == '-') && is_digit == 0)
			return (0);
		while (ft_isdigit(*str) == 1)
		{
			nbr = nbr * 10 + (*str - '0');
			str++;
		}
		str++;
	}
	return (sign * nbr);
}
