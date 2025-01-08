/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_operations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 08:04:07 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/08 14:08:24 by root          ########   odam.nl         */
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

//pushes the top number of stack b to stack a 
void	pa(int *int_stack_a_array, int *stack_a_size,
		int *int_stack_b_array, int *stack_b_size)
{
	int	i;

	if (*stack_b_size > 0)
	{
		i = *stack_a_size;
		while (i > 0)
		{
			int_stack_a_array[i] = int_stack_a_array[i - 1];
			i--;
		}
		int_stack_a_array[0] = int_stack_b_array[0];
		i = 0;
		while (i < (*stack_b_size - 1))
		{
			int_stack_b_array[i] = int_stack_b_array[i + 1];
			i++;
		}
		(*stack_a_size)++;
		(*stack_b_size)--;
	}
}

//pushes the top number of stack a to stack b
void	pb(int *int_stack_a_array, int *stack_a_size,
			int *int_stack_b_array, int *stack_b_size)
{
	int	i;

	if (*stack_a_size > 0)
	{
		i = *stack_b_size;
		while (i > 0)
		{
			int_stack_b_array[i] = int_stack_b_array[i - 1];
			i--;
		}
		int_stack_b_array[0] = int_stack_a_array[0];
		i = 0;
		while (i < (*stack_a_size - 1))
		{
			int_stack_a_array[i] = int_stack_a_array[i + 1];
			i++;
		}
		(*stack_a_size)--;
		(*stack_b_size)++;
	}
}
