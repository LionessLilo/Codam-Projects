/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation_operations_2.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 16:30:16 by root          #+#    #+#                 */
/*   Updated: 2025/01/08 17:00:10 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

void	rra(int *int_stack_a_array, int stack_a_size)
{
	int	temp;
	int	i;

	i = stack_a_size - 1;
	if (stack_a_size < 2)
	{
		ft_printf("Not enough items in stack a for rra");
		return ;
	}
	temp = int_stack_a_array[stack_a_size - 1];
	while (i > 0)
	{
		int_stack_a_array[i] = int_stack_a_array[i - 1];
		i--;
	}
	int_stack_a_array[0] = temp;
}

void	rrb(int *int_stack_b_array, int stack_b_size)
{
	int	temp;
	int	i;

	i = stack_b_size - 1;
	if (stack_b_size < 2)
	{
		ft_printf("Not enough items in stack a for rra");
		return ;
	}
	temp = int_stack_b_array[stack_b_size - 1];
	while (i > 0)
	{
		int_stack_b_array[i] = int_stack_b_array[i - 1];
		i--;
	}
	int_stack_b_array[0] = temp;
}

void	rrr(int *int_stack_a_array, int stack_a_size,
			int *int_stack_b_array, int stack_b_size)
{
	rra(int_stack_a_array, stack_a_size);
	rrb(int_stack_b_array, stack_b_size);
}
