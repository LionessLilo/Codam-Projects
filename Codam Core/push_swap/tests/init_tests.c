/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_tests.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: root <root@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 14:32:23 by root          #+#    #+#                 */
/*   Updated: 2025/01/22 21:15:28 by root          ########   odam.nl         */
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

int	main(void)
{
	t_stack_node	*a_node;
	int				i;
	int				checker;
	t_stack_node	*temp;
	FILE			*fd;

	#pragma region Setup

	a_node = NULL;
	checker = 0;
	fd = fopen( "./tests/test_logs.txt", "w" );
	#pragma endregion

	#pragma region initialisation with 3 items
	// Arrange
	char *argv[] = {"4", "3", "1", NULL};
	fprintf(fd, "Argv: \n");
	i = 0;
	while (argv[i])
	{
		fprintf(fd, "Arg[%d]: %s\n", i, argv[i]);
		i++;
	}
	// Act
	init_stack_a(&a_node, argv);
	// Assert
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
	printf("\033[0;37mInitialise stack 3 items: ");
	if (a_node->int_nbr == ft_atol(argv[0]) && 
		a_node->ptr_next->int_nbr == ft_atol(argv[1]) && 
		a_node->ptr_next->ptr_next->int_nbr == ft_atol(argv[2]))
		log_tick();
	else
		fprintf(fd, "Error");
	#pragma endregion

	#pragma region initialisation with 10 items
	// Arrange
	a_node = NULL;
	fprintf(fd, "Argv list: \n");
	char *argv2[] = {"6",  "3", "1", "2", "5", "16", "45", "7", "9", "17", "8", NULL};
	fprintf(fd, "Argv: \n");
	i = 0;
	while (argv2[i])
	{
		fprintf(fd, "Arg[%d]: %s\n", i, argv2[i]);
		i++;
	}
	init_stack_a(&a_node, argv2);
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
	printf("\033[0;37mInitialise stack 10 items: ");
	if (a_node->int_nbr == ft_atol(argv2[0]) && 
		a_node->ptr_next->int_nbr == ft_atol(argv2[1]) && 
		a_node->ptr_next->ptr_next->int_nbr == ft_atol(argv2[2]) &&
		a_node->ptr_next->ptr_next->ptr_next->int_nbr == ft_atol(argv2[3]) &&
		a_node->ptr_next->ptr_next->ptr_next->ptr_next->int_nbr == ft_atol(argv2[4]) &&
		a_node->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->int_nbr == ft_atol(argv2[5]) &&
		a_node->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->int_nbr == ft_atol(argv2[6]) &&
		a_node->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->int_nbr == ft_atol(argv2[7]) &&
		a_node->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->int_nbr == ft_atol(argv2[8]) &&
		a_node->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->int_nbr == ft_atol(argv2[9]) &&
		a_node->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->ptr_next->int_nbr == ft_atol(argv2[10]))

		log_tick();
	else
		printf("\033[0;31mError\033[0;37m");
	// #pragma endregion

	fclose(fd);
	free_stack(&a_node);
	return (0);
}
