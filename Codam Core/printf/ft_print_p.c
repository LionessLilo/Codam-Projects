/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_p.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/06 10:42:27 by lilo          #+#    #+#                 */
/*   Updated: 2024/11/06 12:50:04 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

int	ft_print_p(void *nbr)
{
	int	count;

	count = write(1, "0x", 2);
	count += ft_print_xx((uintptr_t)nbr, 'x');
	return (count);
}
