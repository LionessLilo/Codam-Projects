/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 20:11:43 by root          #+#    #+#                 */
/*   Updated: 2025/01/02 21:15:52 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"
#include "../printf/libft/libft.h"
#include <stdlib.h>

int	is_valid_int(const char *cchar_input_numbers)
{
	int	i;

	i = 0;
	while (cchar_input_numbers[i])
	{
		if (cchar_input_numbers[i] == '+' || cchar_input_numbers[i] == '-')
			i++;
		if (!cchar_input_numbers[i])
			return (ft_printf("Please add a number"), 0);
		if (!ft_isdigit(cchar_input_numbers[i]))
			return (ft_printf("You entered a value that is not a number"), 0);
		i++;
	}
	return (1);
}

int	contains_duplicates(int *int_stack_a, int int_stack_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < int_stack_size - 1)
	{
		j = i + 1;
		while (j < int_stack_size)
		{
			if (int_stack_a[i] == int_stack_a[j])
			{
				ft_printf("You have entered a duplicate value");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_input(int argc, char **argv, int **stack_a, int *stack_size)
{
	int	*int_temp_atoi;
	int	i;

	i = 0;
	if (argc < 2)
		return (ft_printf("Not enough arguements"), 0);
	int_temp_atoi = malloc((argc - 1) * sizeof(int));
	if (!int_temp_atoi)
		return (ft_printf("Could not malloc int_temp_atoi"), 0);
	
	// Validate each argument

	// Check for duplicates
	

	// Pass valid input to stack_a
}
