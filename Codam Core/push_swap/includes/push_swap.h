/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 15:45:56 by root          #+#    #+#                 */
/*   Updated: 2025/01/14 14:30:40 by llourens      ########   odam.nl         */
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
	bool				bool_is_above_median;
	bool				bool_is_cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

//main
int		main(int argc, char **argv);

// Error handling
void	error_malloc(char	*variable);

// stack initialisation
void	init_stack_a(t_stack_node **a, char **argv);
void	append_node(t_stack_node **tstack_stack, int int_num);

// Stack utils

// Commands

// Algorithms


#endif