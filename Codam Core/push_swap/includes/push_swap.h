/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 15:45:56 by root          #+#    #+#                 */
/*   Updated: 2025/01/15 20:47:39 by llourens      ########   odam.nl         */
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
	int					int_nbr;
	int					int_i;
	int					int_push_cost;
	int					bool_is_above_median;
	int					bool_is_cheapest;
	struct s_stack_node	*ptr_target_node;
	struct s_stack_node	*ptr_next;
	struct s_stack_node	*ptr_prev;
}						t_stack_node;

//main
int		main(int argc, char **argv);

// Error handling
void	free_and_handle(t_stack_node *stack_a_node, char *message);
void	free_stack(t_stack_node *stack_a_node);

// Initialisation
void	init_stack_a(t_stack_node **stack_a_node, char **argv_list);

//Validation
int		is_syntax_error(char *number);


// Stack utils


// Commands

// Algorithms


#endif