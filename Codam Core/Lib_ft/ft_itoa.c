/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/20 00:38:11 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/21 16:04:34 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static char	*initialise_string(int nb, int int_len)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * int_len);
	if (!new_str)
		return (NULL);
	if (nb < 0)
	{
		new_str[int_len - 1] = '-';
	}
	return (new_str);
}

static char	*flip_string(char *new_str, int int_len)
{
	int		i;
	char	temp;

	i = 0;
	while (i < (int_len / 2))
	{
		temp = new_str[i];
		new_str[i] = new_str[int_len - (i + 1)];
		new_str[int_len - (i + 1)] = temp;
		i++;
	}
	return (new_str);
}

static int	int_size(int nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		size++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nb)
{
	int		remainder;
	int		int_len;
	char	print_number;
	char	*new_str;
	int		i;

	i = 0;
	int_len = int_size(nb);
	new_str = initialise_string(nb, int_len);
	if (nb < 0)
		nb = -nb;
	while (nb / 10)
	{
		remainder = nb % 10;
		print_number = remainder + '0';
		new_str[i] = print_number;
		i++;
		nb = nb / 10;
	}
	new_str[i] = (nb % 10) + '0';
	return (flip_string(new_str, int_len));
	free (new_str);
}
