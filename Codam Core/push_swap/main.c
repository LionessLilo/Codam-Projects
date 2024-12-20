/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/20 15:29:11 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/20 18:39:03 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf/libft/libft.h"
#include "printf/ft_printf.h"

char	*check_lib(char *str1, char *str2)
{
	char	*joined;

	joined = ft_strjoin(str1, str2);
	return (joined);
}

int	main(void)
{
	char	*str1 = "Hello";
	char	*str2 = "World";
	char	*all_ok;

	all_ok = check_lib(str1, str2);
	ft_printf("%s", all_ok);
	return (0);
}
