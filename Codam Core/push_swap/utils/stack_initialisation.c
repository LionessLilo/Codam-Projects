/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_initialisation.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/14 13:10:43 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/14 14:30:06 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"


void	append_node(t_stack_node **tstack_stack, int int_num)
{
	t_stack_node	*tstack_new_node;
	t_stack_node	*tstack_last_node;

	if (!tstack_stack)
		return ;
	tstack_new_node = malloc(sizeof(t_stack_node));
	if (!tstack_new_node)
	{
		error_malloc("tstack_new_node in append_node");
		return ;
	}
	tstack_new_node->next = NULL;
	tstack_new_node->int_nbr = int_num;
	if (!*tstack_stack)
	{
		*tstack_stack = tstack_new_node;
		tstack_new_node->prev = NULL;
	}
	else
	{
		tstack_last_node = ft_lstlast(*tstack_stack);
		tstack_last_node->next = tstack_new_node;
		tstack_new_node->prev = tstack_new_node;
	}
}

/*Iniatilaises stack a by checking input is valid and appending nodes*/
void	init_stack_a(t_stack_node **a, char **argv)
{
	long	long_nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (is_syntax_error(argv[i]))
			handle_and_free(a);
		long_nbr = ft_atol(argv[i]);
		if (long_nbr < INT_MIN || long_nbr > INT_MAX)
			handle_and_free(a);
		if (is_duplicate(*a, (int)long_nbr))
			handle_and_free(a);
		append_node(a, (int)long_nbr);
		i++;
	}
}
