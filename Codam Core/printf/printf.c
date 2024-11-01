/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 15:06:52 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/01 14:53:58 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libftprintf.h"
#include "libftprintf.h"

static int	print_from_specifier(char specifier, va_list arg_pointer)
{
	int	count_from_specifier;

	count_from_specifier = 0;
	if (specifier == 'c')
		count_from_specifier += ft_print_char(va_arg(arg_pointer, int));
	else if (specifier == 's')
		count_from_specifier += ft_printstr(va_arg(arg_pointer, char *));
	else if (specifier == 'p')
		count_from_specifier += ft_print_hexadecimal(va_arg(arg_pointer, int));
	else if (specifier == 'd' || specifier == 'i')
		count_from_specifier += ft_print_number(va_arg(arg_pointer, int));
	// else if (specifier == 'u')
	// 	count_from_specifier
	// 		+= print_unsigned_int(va_arg(arg_pointer, unsigned long));
	// else if (specifier == 'x' || specifier == 'X)
	// 	count_from_specifier += print_hex(va_arg(arg_pointer, unsigned long));
	else if (specifier == '%')
		count_from_specifier += write(1, "%", 1);
	return (count_from_specifier);
}

static int	is_valid(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_pointer;
	int		count;

	if (!str)
		return (0);
	count = 0;
	va_start(arg_pointer, str);
	while (*str)
	{
		if (*str == '%' && is_valid(*++str))
			count += print_from_specifier(*str, arg_pointer);
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(arg_pointer);
	return (count);
}

// #include <stdio.h>
// #include "libftprintf.h"

// int main(void)
// {
//     char	*str = "Hello";
// 	char	a = '%';
// 	int		nbr = 42;
// 	int		printf_count;
// 	int		ft_printf_count;

// 	printf_count = (printf("printf count: %%\n", a));
// 	ft_printf_count = ft_printf("printf count: %%\n", a);
// 	printf("printf total: %d\n", printf_count);
// 	printf("ft_printf total: %d\n", ft_printf_count);

//     return 0;
// }