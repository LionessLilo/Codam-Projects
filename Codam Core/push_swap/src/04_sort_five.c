/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   04_sort_five.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/04 08:58:57 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/10 14:35:23 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_smallest_to_b(t_stack_node **stack_a,
			t_stack_node **stack_b, int *len)
{
	t_stack_node	*smallest;

	smallest = find_smallest(*stack_a);
	while (*len > 3 && smallest)
	{
		if (smallest == ft_lstlast(*stack_a))
		{
			rra(stack_a, 1);
			pb(stack_a, stack_b, 1);
			(*len)--;
		}
		else if (smallest == (*stack_a))
		{
			pb(stack_a, stack_b, 1);
			(*len)--;
		}
		else
		{
			ra(stack_a, 1);
		}
		smallest = find_smallest(*stack_a);
	}
}

static void	move_largest_to_top(t_stack_node **stack_a)
{
	t_stack_node	*largest;

	largest = find_highest(*stack_a);
	while (largest && largest != (*stack_a))
	{
		ra(stack_a, 1);
		largest = find_highest(*stack_a);
	}
}

void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b, int len)
{
	move_smallest_to_b(stack_a, stack_b, &len);
	move_largest_to_top(stack_a);
	sort_three_nbr(stack_a);
	pa(stack_a, stack_b, 1);
	if (stack_len(*stack_b) > 0)
		pa(stack_a, stack_b, 1);
}
