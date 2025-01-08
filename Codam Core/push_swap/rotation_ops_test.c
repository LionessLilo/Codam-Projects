/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation_ops_test.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 15:26:50 by root          #+#    #+#                 */
/*   Updated: 2025/01/08 17:02:09 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./printf/ft_printf.h"
#include "./printf/libft/libft.h"
#include "./includes/push_swap.h"

int	main(void)
{
	int	int_stack_a_array[5] = {3, 5, 2, 4, 1};
	int	stack_a_size = 5;
	int	int_stack_b_array[5] = {8, 7, 6, 9, 10};
	int	stack_b_size = 5;
	int	stack_a_atoi;
	int	i;
	
	// //ra
	// ft_printf("Swap a: \n");
	// i = 0;
	// ft_printf("Current: \n");
	// while (i < (stack_a_size))
	// {
	// 	ft_printf("%d, ", int_stack_a_array[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// ft_printf("Changed: \n");
	// ra(int_stack_a_array, stack_a_size);
	// while (i < (stack_a_size))
	// {
	// 	ft_printf("%d, ", int_stack_a_array[i]);
	// 	i++;
	// }
	// ft_printf("\n");

	// //rb
	// ft_printf("Swap b: \n");
	// i = 0;
	// ft_printf("Current: \n");
	// while (i < (stack_b_size))
	// {
	// 	ft_printf("%d, ", int_stack_b_array[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// ft_printf("Changed: \n");
	// rb(int_stack_b_array, stack_b_size);
	// while (i < (stack_b_size))
	// {
	// 	ft_printf("%d, ", int_stack_b_array[i]);
	// 	i++;
	// }
	// ft_printf("\n");

	//rr
	// ft_printf("Swap a: \n");
	// i = 0;
	// ft_printf("Current a: \n");
	// while (i < (stack_a_size))
	// {
	// 	ft_printf("%d, ", int_stack_a_array[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// ft_printf("Current b: \n");
	// while (i < (stack_b_size))
	// {
	// 	ft_printf("%d, ", int_stack_b_array[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// ft_printf("Changed a: \n");
	// rr(int_stack_a_array, stack_a_size, int_stack_b_array, stack_b_size);
	// while (i < (stack_a_size))
	// {
	// 	ft_printf("%d, ", int_stack_a_array[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// ft_printf("Changed b: \n");
	// while (i < (stack_b_size))
	// {
	// 	ft_printf("%d, ", int_stack_b_array[i]);
	// 	i++;
	// }
	// ft_printf("\n");

	//rra
	// ft_printf("Swap a: \n");
	// i = 0;
	// ft_printf("Current: \n");
	// while (i < (stack_a_size))
	// {
	// 	ft_printf("%d, ", int_stack_a_array[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// ft_printf("Changed: \n");
	// rra(int_stack_a_array, stack_a_size);
	// while (i < (stack_a_size))
	// {
	// 	ft_printf("%d, ", int_stack_a_array[i]);
	// 	i++;
	// }
	// ft_printf("\n");

	//rrb
	// ft_printf("Swap b: \n");
	// i = 0;
	// ft_printf("Current: \n");
	// while (i < (stack_b_size))
	// {
	// 	ft_printf("%d, ", int_stack_b_array[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	// i = 0;
	// ft_printf("Changed: \n");
	// rra(int_stack_b_array, stack_b_size);
	// while (i < (stack_a_size))
	// {
	// 	ft_printf("%d, ", int_stack_b_array[i]);
	// 	i++;
	// }
	// ft_printf("\n");

	//rrr
	ft_printf("Swap a: \n");
	i = 0;
	ft_printf("Current a: \n");
	while (i < (stack_a_size))
	{
		ft_printf("%d, ", int_stack_a_array[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("Current b: \n");
	while (i < (stack_b_size))
	{
		ft_printf("%d, ", int_stack_b_array[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("Changed a: \n");
	rrr(int_stack_a_array, stack_a_size, int_stack_b_array, stack_b_size);
	while (i < (stack_a_size))
	{
		ft_printf("%d, ", int_stack_a_array[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("Changed b: \n");
	while (i < (stack_b_size))
	{
		ft_printf("%d, ", int_stack_b_array[i]);
		i++;
	}
	ft_printf("\n");

	return (0);
}
