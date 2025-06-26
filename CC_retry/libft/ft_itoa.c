/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/26 17:07:31 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/26 17:57:30 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	count_digits(int nbr);

char	*ft_itoa(int nbr)
{
	int		remainder;
	int		malloc_size;
	char	*char_nbr;

	if (nbr == -2147483648)
		char_nbr = ft_strdup("-2147483648");
	char_nbr = malloc(sizeof(char) * (count_digits(nbr) + 1));

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
