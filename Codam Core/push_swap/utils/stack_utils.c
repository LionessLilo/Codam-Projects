/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/14 14:25:39 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/14 17:02:06 by llourens      ########   odam.nl         */
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

t_stack_node	*find_largest_nbr(t_stack_node *tsatck_stack)
{
	long			long_largest;
	t_stack_node	*ptr_largest;

	if (!tsatck_stack)
		return ;
	long_largest = LONG_MIN;
	while (tsatck_stack)
	{
		if (tsatck_stack->int_nbr > long_largest)
		{
			long_largest = tsatck_stack->int_nbr;
			ptr_largest = tsatck_stack;
		}
		tsatck_stack = tsatck_stack->next;
	}
	return (ptr_largest);
}

int	stack_len(t_stack_node *tstack_stack)
{
	int	int_count;

	int_count = 0;
	if (!tstack_stack)
		return (0);
	while (tstack_stack)
	{
		tstack_stack = tstack_stack->next;
		int_count++;
	}
	return (int_count);
}
