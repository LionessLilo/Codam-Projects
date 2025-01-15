/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_pop_peek.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 21:13:22 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/15 21:13:32 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "revision.h"

//push
void	push(t_stack_stack *stack, int value)
{
	t_stack_node	*new_node;

	new_node = create_node(value);
	if (!new_node)
		return ;
	new_node->next = stack->top_node;
	stack->top_node = new_node;
	stack->size++;
}

//pop
int	pop(t_stack_stack *stack)
{
	t_stack_node	*temp;
	int				value;

	if (!stack->top_node)
		return (printf("stack underflow"), -1);
	temp = stack->top_node;
	value = temp->content;
	stack->top_node = stack->top_node->next;
	stack->size--;
	free(temp);
	return (value);
}

//peek (print)
void	print_stack(t_stack_stack *stack)
{
	t_stack_node	*current;

	current = stack->top_node;
	while (current)
	{
		printf("%d, ", current->content);
		current = current->next;
	}
}
