/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex04.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/10 16:30:07 by lilo          #+#    #+#                 */
/*   Updated: 2024/09/10 16:38:08 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write(1, "N", 1);
	}

	else
	{
		write(1, "P", 1);
	}
	write(1, "\n", 1);
}

int	main(void)
{
	int	n;

	n = 0;
	ft_is_negative(n);
	return (0);
}
