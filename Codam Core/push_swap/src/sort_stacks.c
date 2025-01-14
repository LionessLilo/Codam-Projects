/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_stacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/14 16:30:48 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/14 18:18:30 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stacks(t_stack_node **tstack_a, t_stack_node **tstack_b)
{
	int	len_tstack_a;

	len_tstack_a = stack_len(*tstack_a);
	if (len_tstack_a-- > 3 && !is_stack_sorted(*tstack_a))
		pb(tstack_b, tstack_a, false);
	if (len_tstack_a-- > 3 && !is_stack_sorted(*tstack_a))
		pb(tstack_b, tstack_a, false);
	while (len_tstack_a-- > 3 && !is_stack_sorted(*tstack_a))
	{
		init_nodes_a(*tstack_a, *tstack_b);
		move_a_to_b(tstack_a, tstack_b);
	}
}
