/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   02_init_stack_a.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 16:55:16 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/20 16:31:09 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"
#include "../printf/ft_printf.h"

void	init_stack_a(t_stack_node **stack_a_node, char **argv_list)
{
	int		i;
	long	long_nbr;

	i = 0;
	long_nbr = (long) NULL;
	while (argv_list[i])
	{
		if (is_syntax_error(argv_list[i]) == 1)
			free_and_handle(stack_a_node, "syntax error\n");
		long_nbr = ft_atol(argv_list[i]);
		if (long_nbr < INT_MIN || long_nbr > INT_MAX)
			free_and_handle(stack_a_node, "Not a valid int size\n");
		if (is_duplicate(*stack_a_node, long_nbr) == 1)
			free_and_handle(stack_a_node, "Duplicate number\n");
		append_node(stack_a_node, long_nbr);
		i++;
	}
}

void	append_node(t_stack_node **stack_a, long long_nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack_a)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->ptr_next = NULL;
	new_node->int_nbr = long_nbr;
	new_node->is_cheapest = 0;
	if (!*stack_a)
	{
		*stack_a = new_node;
		new_node->ptr_prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*stack_a);
		last_node->ptr_next = new_node;
		new_node->ptr_prev = last_node;
	}
}
