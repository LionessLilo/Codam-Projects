/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 16:22:22 by lilo          #+#    #+#                 */
/*   Updated: 2025/05/27 17:00:47 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	chr_compare(int str, int to_find)
{
	if (str != to_find)
		return (0);
	else
		return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i_str;
	int	i_tofind;

	i_str = 0;
	i_tofind = 0;
	while (str[i_str])
	{
		if (chr_compare(str[i_str], to_find[i_tofind]) == 1)
		{
			while (to_find[i_tofind]
				&& chr_compare(str[i_str], to_find[i_tofind]) == 1)
			{
				i_str++;
				i_tofind++;
				if (to_find[i_tofind] == '\0')
					return (&str[i_str - i_tofind]);
			}
			if (str[i_str] != '\0' && to_find[i_tofind] != '\0')
				i_tofind = 0;
		}
		i_str++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char str[] = "Hello, world!";
// 	char to_find[] = "world";

// 	char *result1 = ft_strstr(str, to_find);
// 	char *result2 = strstr(str, to_find);

// 	if ((result1 == NULL && result2 == NULL) || (result1 && result2 && strcmp(result1, result2) == 0))
// 		printf("ft_strstr matches strstr\n");
// 	else
// 		printf("ft_strstr does not match strstr\n");
// 	printf("%s\n%s\n", result1, result2);

// 	return 0;
// }