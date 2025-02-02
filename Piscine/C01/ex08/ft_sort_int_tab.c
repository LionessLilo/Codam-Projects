/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_int_tab.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/02 16:35:38 by root          #+#    #+#                 */
/*   Updated: 2025/02/02 17:50:38 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	
}

int	main(void)
{
	int tab[] = {5, 2, 4, 3, 1};
	int size = 5;
	int	i;

	i = 0;
	ft_sort_int_tab(tab, size);
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
}
