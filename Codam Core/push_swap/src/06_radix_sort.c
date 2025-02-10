/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   06_radix_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/28 13:02:11 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/10 14:05:37 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"
#include "../printf/libft/libft.h"

void	radix_sort(t_stack_node **stack_a, 
			t_stack_node **stack_b, int stack_len)
{
	int	current_bit_position;
	int	processed_nbrs;
	t_stack_node	*largest_nbr;

	if (!stack_a || !*stack_a)
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	largest_nbr = find_highest(*stack_a);
	assign_indices(stack_a);
	current_bit_position = 0;
	if (largest_nbr->int_nbr < 99999)
	{
		while (current_bit_position < 7)
		{
			processed_nbrs = 0;
			while (processed_nbrs < stack_len)
			{
				if (((*stack_a)->int_index_in_sorted_array
						>> current_bit_position) & 1)
					ra(stack_a, 0);
				else
					pb(stack_a, stack_b, 0);
				processed_nbrs++;
			}
			while (*stack_b)
				pa(stack_a, stack_b, 0);
			current_bit_position++;
		}
	}
	else
	{
		while (current_bit_position < 10)
		{
			processed_nbrs = 0;
			while (processed_nbrs < stack_len)
			{
				if (((*stack_a)->int_index_in_sorted_array
						>> current_bit_position) & 1)
					ra(stack_a, 0);
				else
					pb(stack_a, stack_b, 0);
				processed_nbrs++;
			}
			while (*stack_b)
				pa(stack_a, stack_b, 0);
			current_bit_position++;
		}
	}
}
