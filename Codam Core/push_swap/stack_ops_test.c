/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_ops_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 09:23:47 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/08 14:41:19 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./printf/ft_printf.h"
#include "./printf/libft/libft.h"
#include "./includes/push_swap.h"

int	main(void)
{
	int	int_stack_a_array[4] = {4,5,6,8};
	int	stack_a_size = 4;
	int	int_stack_b_array[3] = {1,9,7};
	int	stack_b_size = 3;
	int	stack_a_atoi;
	int	i;

	//sa
	ft_printf("Swap a: \n");
	i = 0;
	ft_printf("Current: \n");
	while (i < (stack_a_size))
	{
		ft_printf("%d", int_stack_a_array[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("Changed: \n");
	sa(int_stack_a_array, stack_a_size);
	while (i < (stack_a_size))
	{
		ft_printf("%d", int_stack_a_array[i]);
		i++;
	}
	ft_printf("\n");

	//sb
	ft_printf("Swap b: \n");
	i = 0;
	ft_printf("Current: \n");
	while (i < (stack_b_size))
	{
		ft_printf("%d", int_stack_b_array[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("Changed: \n");
	sa(int_stack_b_array, stack_b_size);
	while (i < (stack_b_size))
	{
		ft_printf("%d", int_stack_b_array[i]);
		i++;
	}
	ft_printf("\n");

	//ss
	ft_printf("Swap a and b: \n");
	i = 0;
	ft_printf("Current a: \n");
	while (i < (stack_a_size))
	{
		ft_printf("%d", int_stack_a_array[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("Changed a: \n");
	ss(int_stack_a_array, stack_a_size,
		int_stack_b_array, stack_b_size);
	while (i < (stack_a_size))
	{
		ft_printf("%d", int_stack_a_array[i]);
		i++;
	}
	ft_printf("\n");


	i = 0;
	ft_printf("Current b: \n");
	while (i < (stack_b_size))
	{
		ft_printf("%d", int_stack_b_array[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("Changed b: \n");
	ss(int_stack_a_array, stack_a_size,
		int_stack_b_array, stack_b_size);
	while (i < (stack_b_size))
	{
		ft_printf("%d", int_stack_b_array[i]);
		i++;
	}
	ft_printf("\n");

	// pa
	ft_printf("Push a: \n");
	i = 0;
	ft_printf("Current A: \n");
	while (i < stack_a_size)
	{
		ft_printf("%d ", int_stack_a_array[i]);
		i++;
	}
	ft_printf("\n");

	i = 0;
	ft_printf("Current B: \n");
	while (i < stack_b_size)
	{
		ft_printf("%d ", int_stack_b_array[i]);
		i++;
	}
	ft_printf("\n");

	ft_printf("Changed A: \n");
	i = 0;
	pa(int_stack_a_array, &stack_a_size, int_stack_b_array, &stack_b_size);
	while (i < stack_a_size)
	{
		ft_printf("%d ", int_stack_a_array[i]);
		i++;
	}
	ft_printf("\n");

	ft_printf("Changed B: \n");
	i = 0;
	while (i < stack_b_size)
	{
		ft_printf("%d ", int_stack_b_array[i]);
		i++;
	}
	ft_printf("\n");

	//pb
	ft_printf("Push b: \n");

	i = 0;
	ft_printf("Current A: \n");
	while (i < stack_a_size)
	{
		ft_printf("%d ", int_stack_a_array[i]);
		i++;
	}
	ft_printf("\n");

	i = 0;
	ft_printf("Current B: \n");
	while (i < stack_b_size)
	{
		ft_printf("%d ", int_stack_b_array[i]);
		i++;
	}
	ft_printf("\n");

	ft_printf("Changed A: \n");
	i = 0;
	pb(int_stack_a_array, &stack_a_size, int_stack_b_array, &stack_b_size);
	while (i < stack_a_size)
	{
		ft_printf("%d ", int_stack_a_array[i]);
		i++;
	}
	ft_printf("\n");

	ft_printf("Changed B: \n");
	i = 0;
	while (i < stack_b_size)
	{
		ft_printf("%d ", int_stack_b_array[i]);
		i++;
	}
	ft_printf("\n");

	return (0);
}
