#ifndef REVISION_H
# define REVISION_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					content;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct s_stack_stack
{
	t_stack_node	*top_node;
	long			size;
}					t_stack_stack;

//Level 1
t_stack_node	*create_node(int value);

#endif