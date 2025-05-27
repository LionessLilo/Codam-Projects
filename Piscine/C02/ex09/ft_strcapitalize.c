/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcapitalize.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 13:58:04 by lilo          #+#    #+#                 */
/*   Updated: 2025/05/27 14:31:15 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_is_spacer(int chr)
{
	if (chr == ' ' || chr == '+' || chr == '-')
		return (1);
	else
		return (0);
}

static int	ft_chr_is_lowercase(int chr)
{
	if (chr >= 'a' && chr <= 'z')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && ft_chr_is_lowercase(str[i]) == 1)
			str[i] = str[i] - 32;
		if (ft_chr_is_lowercase(str[i]) == 1
			&& ft_is_spacer(str[i - 1]) == 1)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
// int	main(void)
// {
// 	char string[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

// 	printf("%s", ft_strcapitalize(string));
// 	return (0);
// }
