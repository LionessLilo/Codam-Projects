#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	main(void)
{
	int	result;

	result = printf("%u\n", 4294967295U);
	printf("%d\n", result);
	result = ft_printf("%u\n", 4294967295U);
	printf("%d\n", result);
	return (0);
}
