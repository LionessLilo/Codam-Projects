/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex05.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/10 16:41:56 by lilo          #+#    #+#                 */
/*   Updated: 2024/09/11 22:08:58 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	hundreds;
	char	tens;
	char	units;

	hundreds = '0';
	tens = '0';
	units = '0';
	while (hundreds <= '9')
	{
		tens = hundreds + 1;
		while (tens <= '9')
		{
			units = tens + 1;
			while (units <= '9')
			{
				write(1, &hundreds, 1);
				write(1, &tens, 1);
				write(1, &units, 1);
				write(1, "\n", 1);
				units++;
			}
			tens++;
		}
		hundreds++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
