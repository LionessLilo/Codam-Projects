/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_di.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:30:11 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/06 07:50:20 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_print_di(int nbr)
{
    char	*str_to_print;
    int		count;

    str_to_print = ft_itoa(nbr);
    if (!str_to_print)
        return (0);
    count = ft_print_str(str_to_print);
    free(str_to_print);
    return (count);
}

// int	main(void)
// {
// 	int	nbr = 10;

// 	printf("printf: %d\n", nbr);
// 	ft_print_di(10);
// }
