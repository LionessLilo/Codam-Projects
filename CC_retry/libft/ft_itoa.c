/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/26 17:07:31 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/27 16:56:54 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char	*exceptions(int nbr);
static int	count_digits(int nbr);
static char	*calculations_and_fill(int nbr, char *printable_nbr);

/* Converts an integer into a string. You need to free the itoa */

char	*ft_itoa(int nbr)
{
	int		nbr_size;
	char	*printable_nbr;
	char	*str_end;

	printable_nbr = exceptions(nbr);
	if (printable_nbr)
		return (printable_nbr);
	nbr_size = count_digits(nbr);
	printable_nbr = malloc(sizeof(char) * (nbr_size + 1));
	if (!printable_nbr)
		return (NULL);
	str_end = printable_nbr + nbr_size;
	*str_end = '\0';
	printable_nbr = calculations_and_fill(nbr, str_end);
	if (!printable_nbr)
		return (NULL);
	return (printable_nbr);
}

static char	*exceptions(int nbr)
{
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (nbr == 0)
		return (ft_strdup("0"));
	else
		return (NULL);
}

static int	count_digits(int nbr)
{
	int	size;

	size = 1;
	if (nbr < 0)
	{
		size++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

static char	*calculations_and_fill(int nbr, char *printable_nbr)
{
	int		sign;

	sign = nbr;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr / 10)
	{
		printable_nbr--;
		*printable_nbr = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	printable_nbr--;
	*printable_nbr = (nbr % 10) + '0';
	if (sign < 0)
	{
		printable_nbr--;
		*printable_nbr = '-';
	}
	return (printable_nbr);
}
