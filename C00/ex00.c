/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ex00.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/10 14:42:16 by lilo          #+#    #+#                 */
/*   Updated: 2024/09/10 15:13:36 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
	write (1, "\n", 1);
}

int	main(void)
{
	char	c;

	c = 'A';
	ft_putchar(c);
	return (0);
}
