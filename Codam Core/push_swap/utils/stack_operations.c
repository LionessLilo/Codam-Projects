/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 08:04:07 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/06 11:05:01 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

//swap a: swaps the top two numbers of stack a
void	sa(int *int_stack_a_array, int stack_a_size)
{
	int	temp;

	if (stack_a_size >= 2)
	{
		temp = int_stack_a_array[0];
		int_stack_a_array[0] = int_stack_a_array[1];
		int_stack_a_array[1] = temp;
	}
}

//swap b: swaps the top two numbers of stack b
void	sb(int *int_stack_b_array, int stack_b_size)
{
	int	temp;

	if (stack_b_size >= 2)
	{
		temp = int_stack_b_array[0];
		int_stack_b_array[0] = int_stack_b_array[1];
		int_stack_b_array[1] = temp;
	}
}

//swap b: swaps the top two numbers of stacks a and b
void	ss(int *int_stack_a_array, int stack_a_size,
		int *int_stack_b_array, int stack_b_size)
{
	sa(int_stack_a_array, stack_a_size);
	sb(int_stack_b_array, stack_b_size);
}
