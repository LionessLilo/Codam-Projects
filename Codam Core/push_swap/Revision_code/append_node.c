/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   append_node.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 21:14:01 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/16 09:30:42 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//Write a function append_node(t_node **head, int value) to add a new node to the end of a linked list.
#include "revision.h"
#include "../printf/libft/libft.h"

void	append_node(t_stack_node **stack, int content)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (0);
	new_node->next = NULL;
	new_node->content = content;
	if (!*stack)
	{
		*stack = new_node;
	}
	else
	{
		last_node = ft_lstlast(*stack);
		last_node->next = new_node;
	}
}
