/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/22 15:28:23 by root          #+#    #+#                 */
/*   Updated: 2024/12/29 23:16:02 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"
#include "../printf/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_isvalid_int(char *input_numbers)
{
	int	i;

	i = 0;
	while (input_numbers[i])
	{
		
	}
	return (1);
}

int	validate_input(int argc, char **argv, int **stack_a, int **stack_size)
{
	int	*input_numbers;

	if (argc < 2)
		return (ft_printf("Please input your numbers"), 0);
	input_numbers = malloc((argc - 1) * sizeof(int));
	if (!input_numbers)
		return (write(2, "could not malloc input_numbers", 30), 0);
	if (!is_valid_int(input_numbers))
		return (ft_printf("Only numbers are allowed"), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	stack_size;

	if (!validate_input(argc, argv, &stack_a, &stack_size))
		return (ft_printf("Not valid input"), 0);
}
