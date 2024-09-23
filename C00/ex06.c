/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex06.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/12 21:39:24 by lilo          #+#    #+#                 */
/*   Updated: 2024/09/23 18:13:20 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_write(char left_tens, char left_units, char right_tens, char right_units)
{

	if (left_tens > right_tens)
	{
		return;
	}
	if (left_tens == right_tens && left_units >= right_units)
	{
		return;
	}

	write(1, &left_tens, 1);
	write(1, &left_units, 1);
	write(1, " ", 1);
	write(1, &right_tens, 1);
	write(1, &right_units, 1);
	write(1, ", ", 2);
}

void ft_print_comb2(void)
{
	char left_tens;
	char left_units;
	char right_units;
	char right_tens;

	left_tens = '0';
	while (left_tens <= '9')
	{
		left_units = '0';
		while (left_units <= '9')
		{
			right_tens = '0';
			while (right_tens <= '9')
			{
				right_units = '0';
				while (right_units <= '9')
				{
					ft_write(left_tens, left_units, right_tens, right_units);
					right_units++;
				}
				right_tens++;
			}
			left_units++;
		}
		left_tens++;
	}
}

int main(void)
{
	ft_print_comb2();
	return (0);
}