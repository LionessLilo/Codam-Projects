/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/03 21:19:24 by root          #+#    #+#                 */
/*   Updated: 2025/02/03 21:58:33 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *array, int c, size_t size)
{
	size_t			i;
	unsigned char	*uc_temp_array;
	unsigned char	uc_c;

	i = 0;
	uc_temp_array = (unsigned char *)array;
	uc_c = (unsigned char)c;
	while (i < size)
	{
		uc_temp_array[i] = uc_c;
		i++;
	}
	return (array);
}
