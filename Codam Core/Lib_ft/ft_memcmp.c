/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 18:26:39 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/20 00:13:51 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t			i;
	unsigned char	*u_ptr1;
	unsigned char	*u_ptr2;

	u_ptr1 = (unsigned char *)ptr1;
	u_ptr2 = (unsigned char *)ptr2;
	i = 0;
	while (i < num)
	{
		if (u_ptr1[i] != u_ptr2[i])
		{
			return (u_ptr1[i] - u_ptr2[i]);
		}
		if ((u_ptr1[i] == '\0' || u_ptr2[i] == '\0') && i < num)
		{
			return (u_ptr1[i] - u_ptr2[i]);
		}
		i++;
	}
	return (0);
}
