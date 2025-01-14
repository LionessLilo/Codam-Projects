/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/14 14:25:39 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/14 14:38:08 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_stack_sorted(t_stack_node *tstack_stack)
{
	if (!tstack_stack)
		return ;
	while (tstack_stack->next)
	{
		if (tstack_stack->int_nbr > tstack_stack->next->int_nbr)
			return (false);
		tstack_stack = tstack_stack->next;
	}
	return (true);
}
