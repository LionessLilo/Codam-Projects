/*Write a function create_node(int value) to allocate memory for a node and initialize its value.
Test it by creating a single node and printing its value.*/

#include "revision.h"

t_stack_node	*create_node(int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->age = value;
	new_node->next = NULL;
	return (new_node);
}

int	main(void)
{
	int				value;
	t_stack_node	*print_struct;
	int				int_print;

	value = 42;
	int_print = 0;
	print_struct = create_node(value);
	int_print = print_struct->age;
	printf("%d", int_print);
	return (0);
}
