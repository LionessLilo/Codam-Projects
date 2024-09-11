/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex01.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/10 15:14:28 by lilo          #+#    #+#                 */
/*   Updated: 2024/09/10 15:58:16 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	ft_print_alphabet();
	return (0);
}
