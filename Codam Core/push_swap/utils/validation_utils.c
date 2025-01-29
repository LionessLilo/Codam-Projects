/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 20:42:41 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/29 17:39:29 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"
#include "../printf/ft_printf.h"

int	is_syntax_error(char *number)
{
	int		i;

	i = 0;
	if (number[i] == '+' || number[i] == '-')
		i++;
	while (number[i])
	{
		if (ft_isdigit(number[i]) == 0)
			return (1);
		if ((number[i] == '+' || number[i] == '-')
			&& ((number[i - 1] == '+' || number[i - 1] == '-')
				|| ft_isdigit(number[i - 1]) == 0))
			return (1);
		i++;
	}
	return (0);
}

int	is_duplicate(t_stack_node *stack_a, long nbr)
{
	while (stack_a)
	{
		if (stack_a->int_nbr && stack_a->int_nbr == nbr)
			return (1);
		else if (stack_a->int_nbr == 0 && nbr == 0)
			return (1);
		stack_a = stack_a->ptr_next;
	}
	return (0);
}

int	is_sorted(t_stack_node *stack)
{
	if (!stack)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	while (stack->ptr_next)
	{
		if (stack->int_nbr > stack->ptr_next->int_nbr)
			return (0);
		stack = stack->ptr_next;
	}
	return (1);
}
