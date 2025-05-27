/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/27 15:58:55 by lilo          #+#    #+#                 */
/*   Updated: 2025/05/27 16:20:59 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	dest_i;
	int	src_i;

	dest_i = 0;
	src_i = 0;
	while (dest[dest_i])
		dest_i++;
	dest[dest_i] = '\0';
	while (src[src_i] && src_i < nb)
	{
		dest[dest_i] = src[src_i];
		dest_i++;
		src_i++;
	}
	if (dest_i <= nb)
		dest[dest_i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char 			src[] = "Hello";
// 	char			dest[12] = "World";
// 	unsigned int	nb = 2;
// 	char			*cat_string = ft_strncat(dest, src, nb);

// 	printf("%s", cat_string);
// 	return 0;
// }
