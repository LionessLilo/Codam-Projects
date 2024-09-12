/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex06.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/12 21:39:24 by lilo          #+#    #+#                 */
/*   Updated: 2024/09/12 23:48:02 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ninety_nine_display(void)
{
	char	right_units;
	char	right_tens;

	right_units = '0';
	right_tens = '0';

	while(right_tens <= '9')
	{
		right_units = '0';
		while(right_units <= '9')
		{
			write(1, &right_tens,1);
			write(1, &right_units, 1);
			write(1, "\n", 1);
			right_units++;
		}
		right_tens++;
	}
	return(0);
}

int	ft_print_comb2(void)
{
	ninety_nine_display();
	return(0);
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}