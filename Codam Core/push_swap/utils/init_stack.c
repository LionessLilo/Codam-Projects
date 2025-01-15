/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 16:55:16 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/15 20:51:45 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"

void	init_stack_a(t_stack_node **stack_a_node, char **argv_list)
{
	int		i;
	long	long_nbr;

	i = 0;
	long_nbr = NULL;
	while (argv_list[i])
	{
		if (is_syntax_error(argv_list[i]) == 0)
			free_and_handle(stack_a_node, "syntax error");
		long_nbr = ft_atol(argv_list[i]);
		if (long_nbr < INT_MIN || long_nbr > INT_MAX)
			free_and_handle(stack_a_node, "Not a valid int size");
		if (is_duplicate(*stack_a_node, long_nbr) == 0)
			free_and_handle(stack_a_node, "Duplicate number");
		append_node(*stack_a_node, (int)long_nbr);
		i++;
	}
}


