/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_c.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 08:25:24 by lilo          #+#    #+#                 */
/*   Updated: 2024/11/04 09:00:25 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_c(int c)
{
	return (write(1, &c, 1));
}
