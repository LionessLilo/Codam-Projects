/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   03_sort_three.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 13:50:37 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/23 17:50:24 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"

void	sort_three_nbr(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_highest(*a);
	if (biggest_node == *a) 
		ra(a, 0); 
	else if ((*a)->ptr_next == biggest_node) 
		rra(a, 0); 
	if ((*a)->int_nbr > (*a)->ptr_next->int_nbr)
		sa(a, 0);
}
