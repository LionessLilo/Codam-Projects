/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/14 15:25:56 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/14 16:25:55 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



void	sort_three_nbr(t_stack_node **tstack_a)
{
	t_stack_node	*tstack_largest_nbr_node;

	tstack_largest_nbr_node = find_largest_nbr(*tstack_a);
	if (tstack_largest_nbr_node == *tstack_a)
		ra(tstack_a, false);
	else if ((*tstack_a)->next == tstack_largest_nbr_node)
		rra(tstack_a, false);
	if ((*tstack_a)->int_nbr > (*tstack_a)->next->int_nbr)
		sa(&tstack_a, false);
}
