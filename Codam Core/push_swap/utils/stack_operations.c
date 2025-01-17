/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/16 10:02:21 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/17 13:55:49 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"

static void	swap(t_stack_node **head)
{
	int	len;

	len = stack_len(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->ptr_next;
	(*head)->ptr_prev->ptr_prev = *head;
	
}

