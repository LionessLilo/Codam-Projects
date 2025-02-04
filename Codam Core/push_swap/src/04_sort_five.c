/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   04_sort_five.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/04 08:58:57 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/04 10:27:29 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b, int len)
{
	t_stack_node	*largest;
	t_stack_node	*smallest;

	largest = find_highest(*stack_a);
	smallest = find_smallest(*stack_a);
	if (!largest || !smallest)
    	return ;
	while (len > 3)
	{
		if (smallest == ft_lstlast(*stack_a))
		{
			rra(stack_a, 1);
			pb(stack_a, stack_b, 1);
			len--;
			smallest = find_smallest(*stack_a);
		}
		else if (smallest == (*stack_a))
		{
			pb(stack_a, stack_b, 1);
			len--;
			smallest = find_smallest(*stack_a);
		}
		else if (largest == (*stack_a))
		{
			ra(stack_a, 1);
			largest = find_highest(*stack_a);
		}
		else
		{
			ra(stack_a, 1);
			smallest = find_smallest(*stack_a);
		}
	}
	sort_three_nbr(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}

