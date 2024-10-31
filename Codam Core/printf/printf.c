/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 15:06:52 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/31 10:11:26 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

static int	print_from_specifiers(char specifier, va_list arg_pointer)
{
	int	count_from_specifier;

	count_from_specifier = 0;
	if (specifier == 'c')
		count_from_specifier += ft_print_char(va_arg(arg_pointer, int));
	else if (specifier == 's')
		count_from_specifier += ft_printstr(va_arg(arg_pointer, char *));
	// else if (specifier == 'p')
	// 	count_from_specifier += ft_print_hexadecimal(va_arg(arg_pointer, int));
	// else if (specifier == 'd' || specifier == 'i')
	// 	count_from_specifier += ft_putnbr(va_arg(arg_pointer, int));
	// else if (specifier == 'u')
	// 	count_from_specifier
	// 		+= print_unsigned_int(va_arg(arg_pointer, unsigned long));
	// else if (specifier == 'x')
	// 	count_from_specifier += print_hex(va_arg(arg_pointer, unsigned long));
	// else if (specifier == '%')
	// 	count_from_specifier += write(1, "%", 1);
	// return (count_from_specifier);
}

static int	is_valid(char *str)
{
	if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
		|| *str == 'i' || *str == 'u' || *str == 'x'
		|| *str == 'X' || *str == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_pointer;
	int		count;

	if (!str)
		return (NULL);
	count = 0;
	va_start(arg_pointer, str);
	while (*str)
	{
		if (*str == '%' && is_valid(*(++str)) == 1)
			count += print_from_specifier(*str, arg_pointer);
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(arg_pointer);
	return (count);
}

int	main(void)
{
	char *str = "Hello";

	printf("Testing with printf: %s\n", str);
	ft_printf("Test with my printf: %s", str);
}
