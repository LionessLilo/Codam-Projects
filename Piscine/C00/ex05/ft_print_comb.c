/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_comb.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/10 16:41:56 by lilo          #+#    #+#                 */
/*   Updated: 2024/09/25 15:51:24 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(char hundreds, char tens, char units)
{
	write(1, &hundreds, 1);
	write(1, &tens, 1);
	write(1, &units, 1);
	if (hundreds == '7' && tens == '8' && units == '9')
	{
		return ;
	}
	write(1, ",", 1);
	write(1, " ", 1);
}

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
				ft_write(hundreds, tens, units);
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
