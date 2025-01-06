/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 15:45:56 by root          #+#    #+#                 */
/*   Updated: 2025/01/06 10:39:59 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int	is_valid_int(const char *cchar_input_numbers);
void	*sa(int *int_stack_a_array, int stack_a_size);
void	*sb(int *int_stack_b_array, int stack_b_size);
void	*ss(int *int_stack_a_array, int stack_a_size,
			int *int_stack_b_array, int stack_b_size);
			
#endif