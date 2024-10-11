/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 18:26:39 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/11 18:41:50 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		if (ptr1[i] != ptr2[i])
		{
			return (ptr1[i] - ptr2[i]);
		}
		if ((ptr1[i] == '\0' || ptr2[i] == '\0') && i < num)
		{
			return (ptr1[i] - ptr2[i]);
		}
		i++;
	}
	return (0);
}
