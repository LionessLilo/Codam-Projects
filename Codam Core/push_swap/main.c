/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 20:08:49 by root          #+#    #+#                 */
/*   Updated: 2025/01/02 20:14:57 by root          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */



int	main(int argc, char **argv)
{
	int	*stack_a;
	int	stack_size;

	if (!validate_input(argc, argv, &stack_a, &stack_size))
		return (ft_printf("Not valid input"), 0);
}