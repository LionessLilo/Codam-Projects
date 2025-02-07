/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 21:58:36 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/07 18:18:41 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "../printf/libft/libft.h"
#include "../printf/ft_printf.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	handle_single_argument(char **argv, char ***split_argv)
{
	*split_argv = ft_split(argv[1], ' ');
	if (!(*split_argv)[0] || !(*split_argv)[1])
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

void	handle_sorted_case(t_stack_node **a_node, t_stack_node **b_node, int len)
{
	int	len_a;
	int	len_og;

	len_a = len;
	len_og = len;
	if (len_a > 5 && is_reverse_sorted(*a_node))
	{
		while (len_a-- > 0)
			pb(a_node, b_node, 1);
		len_a = len_og;
		while (len_a-- > 1)
		{
			rrb(b_node, 1);
			pa(a_node, b_node, 1);
		}
		pa(a_node, b_node, 1);
	}
}

void	sort_stack(t_stack_node **a_node, t_stack_node **b_node, int len)
{
	if (len == 2)
		sa(a_node, 1);
	else if (len == 3)
		sort_three_nbr(a_node);
	else if (len > 3 && len <= 5)
		sort_five(a_node, b_node, len);
	else
		radix_sort(a_node, b_node, len);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a_node;
	t_stack_node	*b_node;
	char			**split_argv;
	int				len;

	a_node = NULL;
	b_node = NULL;
	len = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_putendl_fd("Error", 2), 0);
	handle_multiple_arguments(argc, argv, &split_argv);
	init_stack(&a_node, split_argv);
	len = stack_len(a_node);
	handle_sorted_case(&a_node, &b_node, len);
	if (is_sorted(a_node))
		return (0);
	sort_stack(&a_node, &b_node, len);
	if (argc == 2)
		free_split(split_argv);
	free_stack(&a_node);
	free_stack(&b_node);
	return (0);
}
