/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   04_sort_five.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/31 16:16:31 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/31 18:16:18 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_five_nbr(t_stack_node **stack_a, t_stack_node **stack_b, int len)
{
	t_stack_node	*smallest;
	
	while (len > 3)
	{
		smallest = find_smallest(*stack_a);
		if (smallest->int_index_in_sorted_array == 0)
			pb(stack_a, stack_b, 1);
		else if (smallest->int_index_in_sorted_array == len - 1)
		{
			rra(stack_a, 1);
			pb(stack_a, stack_b, 1);
		}
		else
			ra(stack_a, 1);
	}
}
