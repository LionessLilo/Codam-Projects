/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_number.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:30:11 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/03 14:40:51 by lilo          ########   odam.nl         */
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
	return (count);
}
