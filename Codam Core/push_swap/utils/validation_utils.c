/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validation_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 20:42:41 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/15 20:55:08 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	is_duplicate(t_stack_node **stack_a, long nbr)
{
	
}