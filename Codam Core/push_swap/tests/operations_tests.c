/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_tests.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/21 10:45:38 by llourens      #+#    #+#                 */
/*   Updated: 2025/01/21 14:32:31 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../printf/ft_printf.h"
#include <stdio.h>

static void	log_tick(void)
{
	printf("\033[0;32m ✔ \033[0;37m \n");
}

static void	log_error(char *message)
{
	printf("\033[0;31m%s\n\n\033[0;37m", message);
}

int	main(void)
{
	t_stack_node 	*a;
    t_stack_node 	*b;
    t_stack_node 	*c;
	FILE			*fd;
	t_stack_node	*temp;
	int				checker;
	
#pragma region ARRANGE
	a = NULL;
	b = NULL;
	c = NULL;

    a = (t_stack_node *)malloc(sizeof(t_stack_node));
    b = (t_stack_node *)malloc(sizeof(t_stack_node));
    c = (t_stack_node *)malloc(sizeof(t_stack_node));
	temp = malloc(sizeof(t_stack_node));
	fd = fopen( "./tests/test_logs.txt", "w" );
	checker = 0;

    if (!a || !b || !c) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    a->ptr_prev = NULL;
    a->int_nbr = 5;
    a->ptr_next = b;

    b->ptr_prev = a;
    b->int_nbr = 7;
    b->ptr_next = c;

    c->ptr_prev = b;
    c->int_nbr = 8;
    c->ptr_next = NULL;

	fprintf(fd, "Stack: \n");
	temp = a;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}

#pragma endregion

#pragma region SWAP
	sa(&a, checker);
	fprintf(fd, "Result of sa:\n");
	temp = a;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	if (a->int_nbr == 7 && a->ptr_next->int_nbr == 5 && a->ptr_next->ptr_next->int_nbr == 8)
		log_tick();
	else 
		log_error("init failure");
	fprintf(fd, "\n");
#pragma endregion

#pragma region ROTATE
	ra(&a, checker);
	fprintf(fd, "Result of ra:\n");
	temp = a;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	if (a->int_nbr == 5 && a->ptr_next->int_nbr == 8 && a->ptr_next->ptr_next->int_nbr == 7)
		log_tick();
	else 
		log_error("\033[0;31mra failure\033[0;37m");
	fprintf(fd, "\n");
#pragma endregion

#pragma region REVERSE ROTATE
	rra(&a, checker);
	fprintf(fd, "Result of rra:\n");
	temp = a;
	while (temp)
	{
		fprintf(fd, "%d\n", temp->int_nbr);
		temp = temp->ptr_next;
	}
	if (a->int_nbr == 7 && a->ptr_next->int_nbr == 5 && a->ptr_next->ptr_next->int_nbr == 8)
		log_tick();
	else 
		log_error("\033[0;31mrra failure\033[0;37m");
	fprintf(fd, "\n");
#pragma endregion

	while (a)
	{
		temp = a;
		a = a->ptr_next;
		free(temp);
	}
	fclose(fd);
	return (0);
}