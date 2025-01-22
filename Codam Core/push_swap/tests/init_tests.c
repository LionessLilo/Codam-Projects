/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_tests.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 14:32:23 by root          #+#    #+#                 */
/*   Updated: 2025/01/22 15:15:01 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/libft/libft.h"
#include "../printf/ft_printf.h"
#include <stdio.h>

void free_split(char **split)
{
    int i = 0;

    if (!split)
        return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}


static void	log_tick(void)
{
	printf("\033[0;32m ✔ \033[0;37m \n");
}

static void	log_error(char *message)
{
	printf("\033[0;31m \033[0;37m \n%s\n\n", message);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a_node;
	char			**argv_list;
	int				i;
	int				checker;
	t_stack_node	*temp;
	FILE			*fd;

	#pragma region Setup
	a_node = NULL;
	checker = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv_list = ft_split(argv[1], ' ');
	else
		argv_list = argv + 1;
	fd = fopen( "./tests/test_logs.txt", "w" );
	#pragma endregion

	#pragma region initialisation
	// Arrange
	fprintf(fd, "Argv list: \n");
	i = 0;
	while (argv_list[i])
	{
		fprintf(fd, "Arg[%d]: %s\n", i, argv_list[i]);
		i++;
	}
	init_stack_a(&a_node, argv_list);
	fprintf(fd, "\n");
	fprintf(fd, "Nodes in the stack: \n");
	temp = a_node;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	temp = NULL;
	fprintf(fd, "\n");
	printf("\033[0;37mInitialise stack: ");
	if (a_node->ptr_next)
		log_tick();
	#pragma endregion

	fclose(fd);
	free_stack(&a_node);
	free_split(argv_list);
	return (0);
}
