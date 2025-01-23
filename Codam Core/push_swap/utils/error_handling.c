/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 17:21:33 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/23 17:31:46 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"

void	free_and_handle(t_stack_node **stack_a_node, char *message)
{
	free_stack(stack_a_node);
	ft_printf("%s\n", message);
	exit (1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp_node;
	t_stack_node	*current_node;

	if (!stack)
	{
		ft_printf("Could not free empty stack\n");
		return ;
	}
	current_node = *stack;
	while (current_node)
	{
		temp_node = current_node->ptr_next;
		current_node->int_nbr = 0;
		free(current_node);
		current_node = temp_node;
	}
	*stack = NULL;
}
