/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   04_sort_five.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 18:44:14 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/23 19:26:00 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"

void	sort_five(t_stack_node **stack_a)
{
	t_stack_node	*smallest_node;
	t_stack_node	*first_node;
	t_stack_node	*last_node;
	t_stack_node	*stack_b = NULL;
	int				stack_size_a;

	smallest_node = find_smallest(*stack_a);
	stack_size_a = stack_len(*stack_a);
	last_node = ft_lstlast(*stack_a);
	while (stack_size_a > 3)
	{
			first_node = *stack_a;
			if (first_node == smallest_node)
				pb(stack_a, &stack_b, 0);
			else if (first_node->ptr_next == smallest_node) {
				ra(stack_a, 0);
				pb(stack_a, &stack_b, 0);
			}
			else if (last_node == smallest_node) {
				rra(stack_a, 0);
				pb(stack_a, &stack_b, 0);
			}
			else if (last_node->ptr_prev == smallest_node) {
				rra(stack_a, 0);
				rra(stack_a, 0);
				pb(stack_a, &stack_b, 0);
			}
			else {
				ra(stack_a, 0);
				ra(stack_a, 0);
				ra(stack_a, 0);
				pb(stack_a, &stack_b, 0);
			}
	}
}