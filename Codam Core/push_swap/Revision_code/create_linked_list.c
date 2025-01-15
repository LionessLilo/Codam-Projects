/*Write a function create_node(int value) to allocate memory for a node and initialize its value.
Test it by creating a single node and printing its value.*/

#include "revision.h"

t_stack_node	*create_node(int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->content = value;
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
	int_print = print_struct->content;
	printf("%d", int_print);
	return (0);
}

//push
void	push(t_stack_stack *stack, int value)
{
	t_stack_node	*new_node;

	new_node = create_node(value);
	if (!new_node)
		return ;
	new_node->next = stack->top_node;
	stack->top_node = new_node;
	stack->size++;
}

//pop
int	pop(t_stack_stack *stack)
{
	t_stack_node	*temp;
	int				value;

	if (!stack->top_node)
		return (printf("stack underflow"), -1);
	temp = stack->top_node;
	value = temp->content;
	stack->top_node = stack->top_node->next;
	stack->size--;
	free(temp);
	return (value);
}

//peek (print)
void	print_stack(t_stack_stack *stack)
{
	t_stack_node	*current;

	current = stack->top_node;
	while (current)
	{
		printf("%d, ", current->content);
		current = current->next;
	}
}
