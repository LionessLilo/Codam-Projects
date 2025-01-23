/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   01_push_swap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 21:58:36 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/23 18:04:06 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"

void	free_split(char **split)
{
    int	i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a_node;
	t_stack_node	*b_node;
	char			**split_argv;
	int				len;

	a_node = NULL;
	b_node = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		split_argv = ft_split(argv[1], ' ');
	else
		split_argv = argv;
	init_stack(&a_node, split_argv);
	if (!is_sorted(a_node))
	{
		len = stack_len(a_node);
		if (len == 2)
			sa(&a_node, false);
		else if (len == 3)
			sort_three_nbr(&a_node);
		else if (len <= 5)
			sort_five_nbr(&a_node, &b_node);
		else
			sort_stacks(&a_node, &b_node);
	}
	free_stack(&a_node);
	free_split(&argv);
	return (0);
}
