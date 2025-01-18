/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 10:02:21 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/18 15:25:30 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"

static void	swap(t_stack_node **head)
{
	/**
	 * Put A into a variable 
	 * Find the second node and put itinto a variable
	 * Put third node put it into a variable
	 * Pointer to the first node must point to the 2nd node
	 * Update the next node of B to A
	 * Set B prev to NULL
	 * A next must be to C
	 * A prev must go to B
	 * if third node not null its prev must go to A
	 * 
	 * 
	 * 
	 */
	
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*c;

	//find len and checks
	a = *head;
	b = (*head)->ptr_next;
	c = (*head)->ptr_next->ptr_next;
	*head = b;
	b->ptr_next = a;
	b->ptr_prev = NULL;
	a->ptr_next = c;
	a->ptr_prev = b;
	if (c != NULL)
		c->ptr_prev = a;
