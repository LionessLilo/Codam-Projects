/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation_oprations_1.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 14:45:35 by root          #+#    #+#                 */
/*   Updated: 2025/01/08 16:13:42 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

void	ra(int *int_stack_a_array, int stack_a_size)
{
	int	temp;
	int	i;

	i = 0;
	if (stack_a_size < 2)
	{
		ft_printf("Not enough items in stack a for ra");
		return ;
	}
	temp = int_stack_a_array[0];
	while (i < (stack_a_size - 1))
	{
		int_stack_a_array[i] = int_stack_a_array[i + 1];
		i++;
	}
	int_stack_a_array[stack_a_size - 1] = temp;
}

void	rb(int *int_stack_b_array, int stack_b_size)
{
	int	temp;
	int	i;

	i = 0;
	if (stack_b_size < 2)
	{
		ft_printf("Not enough items in stack a for ra");
		return ;
	}
	temp = int_stack_b_array[0];
	while (i < (stack_b_size - 1))
	{
		int_stack_b_array[i] = int_stack_b_array[i + 1];
		i++;
	}
	int_stack_b_array[stack_b_size - 1] = temp;
}

void	rr(int *int_stack_a_array, int stack_a_size,
			int *int_stack_b_array, int stack_b_size)
{
	ra(int_stack_a_array, stack_a_size);
	rb(int_stack_b_array, stack_b_size);
}
