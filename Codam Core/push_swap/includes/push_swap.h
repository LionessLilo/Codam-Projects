/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 15:45:56 by root          #+#    #+#                 */
/*   Updated: 2025/01/31 17:44:42 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					int_nbr;
	int					int_index_in_sorted_array;
	struct s_stack_node	*ptr_next;
	struct s_stack_node	*ptr_prev;
}						t_stack_node;


// Error handling
void			free_and_handle(t_stack_node **stack_a_node);
void			free_stack(t_stack_node **stack);

// Initialisation
void			init_stack(t_stack_node **stack_a_node, char **argv_list);
void			append_node(t_stack_node **stack_a, long long_nbr);

//Validation
int				is_syntax_error(char *number);
int				is_duplicate(t_stack_node *stack_a, long nbr);
int				is_sorted(t_stack_node *stack);


// Stack utils
t_stack_node	*find_highest(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
// Linked list utils
t_stack_node	*ft_lstlast(t_stack_node *lst);
int				stack_len(t_stack_node *stack);
// Operations
void			sa(t_stack_node **stack_a, int checker);
void			sb(t_stack_node **stack_b, int checker);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b, int checker);
void			ra(t_stack_node **stack_a, int checker);
void			rb(t_stack_node **stack_b, int checker);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b, int checker);
void 			rra(t_stack_node **stack_a, int checker);
void 			rrb(t_stack_node **stack_b, int checker);
void 			rrr(t_stack_node **stack_a, t_stack_node **stack_b, int checker);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b, int checker);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b, int checker);

// Algorithms
void			sort_three_nbr(t_stack_node **stack);
void 			sort_five_nbr(t_stack_node **a_node, t_stack_node **b_node, int len);
void			assign_indices(t_stack_node **stack);
void			radix_sort(t_stack_node **stack_a, t_stack_node **stack_b, int stack_len);

//Algorithm utils
int				*linkedlist_to_array(t_stack_node *stack);
int				*sort_array(int *array, int len);
void			push_smallest_to_b(t_stack_node **stack_a, t_stack_node **stack_b);

#endif