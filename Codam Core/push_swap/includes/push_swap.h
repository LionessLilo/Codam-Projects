/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 15:45:56 by root          #+#    #+#                 */
/*   Updated: 2025/01/10 19:25:44 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					nbr;
	int					current_position;
	int					final_index;
	int					i;
	int					cost_to_push;
	bool				is_above_median;	
	bool				is_cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}						t_stack_node;


// Stack initialization
void	stack_init(t_stack_node **a, char **argv);

// Stack utils
bool	is_stack_sorted(t_stack_node *stack);
int		stack_len(t_stack_node *stack);

// Input Validation
int		is_valid_int(const char *cchar_input_numbers);

// Operations
void	*sa(int *int_stack_a_array, int stack_a_size);
void	*sb(int *int_stack_b_array, int stack_b_size);
void	*ss(int *int_stack_a_array, int stack_a_size,
			int *int_stack_b_array, int stack_b_size);
void	pa(int *int_stack_a_array, int *stack_a_size,
			int *int_stack_b_array, int *stack_b_size);
void	pb(int *int_stack_a_array, int *stack_a_size,
			int *int_stack_b_array, int *stack_b_size);
void	ra(int *int_stack_a_array, int stack_a_size);
void	rb(int *int_stack_b_array, int stack_b_size);
void	rr(int *int_stack_a_array, int stack_a_size,
			int *int_stack_b_array, int stack_b_size);
void	rra(int *int_stack_a_array, int stack_a_size);
void	rrb(int *int_stack_b_array, int stack_b_size);
void	rrr(int *int_stack_a_array, int stack_a_size,
			int *int_stack_b_array, int stack_b_size);

#endif