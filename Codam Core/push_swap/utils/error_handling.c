/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 17:21:33 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/15 19:07:51 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"

void	free_and_handle(t_stack_node *stack_a_node, char *message)
{
	free_stack(stack_a_node);
	ft_printf("%s\n", message);
	exit ;
}

void	free_stack(t_stack_node *stack_a_node)
{
	t_stack_node	*temp_node;
	t_stack_node	*current_node;

	if (!stack_a_node)
	{
		ft_printf("Could not free empty stack");
		return ;
	}
	current_node = stack_a_node;
	while (current_node)
	{
		temp_node = stack_a_node->ptr_next;
		free(current_node);
		current_node = temp_node;
	}
}
