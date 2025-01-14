/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 21:58:36 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/14 14:46:27 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack_node	*tstack_a;
	t_stack_node	*tstack_b;
	int				len;

	tstack_a = NULL;
	tstack_b = NULL;
	if (argc == 1 || argc == 2 && !argv[1][0])
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&tstack_a, argv + 1);
	if (!is_stack_sorted(tstack_a))
	{
		len = stack_len(tstack_a);
		if (len == 2)
			sa(&tstack_a, false);
		else if (len == 3)
			sort_three_nbr(&tstack_a);
		else
			sort_large(&tstack_a, &tstack_b);
	}
	free_stack(&tstack_a);
	return (0);
}
