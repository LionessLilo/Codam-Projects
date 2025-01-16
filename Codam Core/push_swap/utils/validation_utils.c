/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 20:42:41 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/16 09:11:51 by llourens      ########   odam.nl         */
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
	if (!stack_a)
	{
		ft_printf("No node to check");
		exit ;
	}
	while (stack_a)
	{
		if (stack_a->int_nbr == nbr)
			return (1);
		stack_a = stack_a->ptr_next;
	}
	return (0);
}
