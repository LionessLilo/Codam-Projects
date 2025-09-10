#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	t_buffer	*test_list;

	printf("Creating a list\n");
	test_list = create_list(2);
	if (test_list->fd == 2 && test_list->next == NULL)
		printf("✔\n");
	return (0);
}
