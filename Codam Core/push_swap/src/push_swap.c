/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 21:58:36 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/15 18:13:37 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a_node;
	t_stack_node	*b_node;
	int				len;

	a_node = NULL;
	b_node = NULL;
	if (argc == 1 || argc == 2 && !argv[1][0]) //!argv[1][0] checks for empty string
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' '); //turns argv+1 into a list
	init_stack_a(&a_node, argv + 1); //The argv list is sent to init_stack_a
	if (!is_stack_sorted(a_node))
	{
		len = stack_len(a_node);
		if (len == 2)
			sa(&a_node, false);
		else if (len == 3)
			sort_three_nbr(&a_node);
		else
			sort_stacks(&a_node, &b_node);
	}
	free_stack(&a_node);
	return (0);
}
