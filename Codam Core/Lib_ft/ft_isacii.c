/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isacii.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 14:50:29 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/08 15:16:49 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_isascii(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 0 && str[i] <= 127)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char	*str;

	str = "\0";
	printf("Test 1: \"%s\" -> %d\n", str, ft_isascii(str));
	return (0);
}
