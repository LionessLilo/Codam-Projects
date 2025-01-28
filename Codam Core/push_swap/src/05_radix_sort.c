/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   05_radix_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/27 15:45:11 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/28 09:24:41 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"

void push_numbers(t_stack_node **stack_a, t_stack_node **stack_b, int stack_len, int current_bit_position, int *numbers_pushed, int *rotations)
{
    int processed_nbrs = 0;

    while (processed_nbrs < stack_len)
    {
        if (((*stack_a)->int_index_in_sorted_array >> current_bit_position) & 1)
        {
            ra(stack_a, 0);
            (*rotations)++;
        }
        else
        {
            pb(stack_a, stack_b, 0);
            (*numbers_pushed)++;
        }
        processed_nbrs++;
    }
}

void restore_stack(t_stack_node **stack_a, t_stack_node **stack_b, int numbers_pushed, int rotations)
{
    while (numbers_pushed > 0)
    {
        pa(stack_a, stack_b, 0);
        numbers_pushed--;
    }
    while (rotations > 0)
    {
        rra(stack_a, 0);
        rotations--;
    }
}

void process_numbers(t_stack_node **stack_a, t_stack_node **stack_b, int stack_len, int current_bit_position)
{
    int numbers_pushed = 0;
    int rotations = 0;

    push_numbers(stack_a, stack_b, stack_len, current_bit_position, &numbers_pushed, &rotations);
    restore_stack(stack_a, stack_b, numbers_pushed, rotations);
}

void radix_sort(t_stack_node **stack_a, t_stack_node **stack_b, int stack_len)
{
    int current_bit_position;

    if (!stack_a || !*stack_a || stack_len <= 1)
        return;

    assign_indices(stack_a); 
    current_bit_position = 0;

    while ((1 << current_bit_position) < stack_len)
    {
        process_numbers(stack_a, stack_b, stack_len, current_bit_position);
        current_bit_position++;
    }
}