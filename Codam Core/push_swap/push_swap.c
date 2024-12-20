/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/19 15:54:43 by root          #+#    #+#                 */
/*   Updated: 2024/12/19 17:22:03 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

char	*push_swap(char *stack_a)
// {
// 	int	i;
{
	char	*b = "World";
	char	*c;

	c = ft_strjoin(stack_a, b);
	return (c);
}
// 	i = 0;
// 	if (stack_a == NULL)
// 		return (NULL);
// 	if (*stack_a != )
// }

int	main(void)
{
	char	*a = "Hello";
	char	*print_working;

	print_working = push_swap(a);
	printf("%s", print_working);
	// int		fd;
	// char	*read_buffer;
	// char	*sorted_array;

	// fd = 0;
	// read_buffer = read(0, read_buffer, 10);
	// sorted_array = ft_push_swap(read_buffer);
	// printf("%d", sorted_array);

	return (0);
}
