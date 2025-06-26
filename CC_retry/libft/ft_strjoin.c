/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/26 15:09:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/26 16:46:56 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*new_string;

	new_string = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_string)
		return (NULL);
	while (*str1)
	{
		*new_string = *str1;
		new_string++;
		str1++;
	}
	while (*str2)
	{
		*new_string = *str2;
		new_string++;
		str2++;
	}
	*new_string = '\0';
	return (new_string);
}
