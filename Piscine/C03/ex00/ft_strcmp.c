/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 14:55:56 by lilo          #+#    #+#                 */
/*   Updated: 2025/05/27 15:05:05 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
}

// int	main(void)
// {
// 	char	s1[] = "Hello";
// 	char	s2[] = "Help!";

// 	printf("%d", ft_strcmp(s1, s2));
// 	return (0);
// }
