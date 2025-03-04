/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_int_tab.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/02 16:35:38 by root          #+#    #+#                 */
/*   Updated: 2025/02/16 12:26:22 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp_nbr;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		if ((tab[i] > tab[j]))
		{
			temp_nbr = tab[i];
			tab[i] = tab[j];
			tab[j] = temp_nbr;
			ft_sort_int_tab(tab, size);
		}
		i++;
		j++;
	}
}
