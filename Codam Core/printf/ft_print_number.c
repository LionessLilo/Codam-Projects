/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_number.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:30:11 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/01 13:06:19 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

int	ft_print_number(int nbr)
{
	char	*str_to_print;
	int		count;

	str_to_print = ft_itoa(nbr);
	count = ft_printstr(str_to_print);
	printf("print_number count: %d");
	return (count);
}

