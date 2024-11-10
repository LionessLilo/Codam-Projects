/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 15:06:52 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/07 13:30:59 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

static int	print_from_specifier(char specifier, va_list arg_pointer)
{
	int	count_from_specifier;

	count_from_specifier = 0;
	if (specifier == 'c')
		count_from_specifier += ft_print_c(va_arg(arg_pointer, int));
	else if (specifier == 's')
		count_from_specifier += ft_print_str(va_arg(arg_pointer, char *));
	else if (specifier == 'p')
		count_from_specifier += ft_print_p(va_arg(arg_pointer, void *));
	else if (specifier == 'd' || specifier == 'i')
		count_from_specifier += ft_print_di(va_arg(arg_pointer, int));
	else if (specifier == 'u')
		count_from_specifier
			+= ft_print_u(va_arg(arg_pointer, unsigned long));
	else if (specifier == 'x' || specifier == 'X')
		count_from_specifier += ft_print_xx
			(va_arg(arg_pointer, unsigned long), specifier);
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
// #include "ft_printf.h"

// int main(void)
// {
//     char	*str = "Hello";
// 	int		nbr = 42;
// 	int		printf_count;
// 	int		ft_printf_count;
//     void	*ptr = &nbr;
// 	unsigned int max;

// 	printf("Character:\n");
// 	printf_count = 0;
// 	ft_printf_count = 0;
// 	printf_count = printf("%c\n", 'H');
// 	ft_printf_count = ft_printf("%c\n", 'H');
// 	printf("%d\n", printf_count);
// 	printf("%d\n", ft_printf_count);

// 	printf("decimal / int:\n");
// 	printf_count = 0;
// 	ft_printf_count = 0;
// 	printf_count = printf("%d\n", nbr);
// 	ft_printf_count = ft_printf("%d\n", nbr);
// 	printf("%d\n", printf_count);
// 	printf("%d\n", ft_printf_count);

// 	printf("string:\n");
// 	printf_count = 0;
// 	ft_printf_count = 0;
// 	printf_count = printf("%s\n", str);
// 	ft_printf_count = ft_printf("%s\n", str);
// 	printf("%d\n", printf_count);
// 	printf("%d\n", ft_printf_count);

// 	printf("Hex:\n");
// 	printf_count = 0;
// 	ft_printf_count = 0;
// 	printf("%x\n", 6);
// 	ft_printf("%x\n", 6);

// 	printf("%x\n", 10);
// 	ft_printf("%x\n", 10);

// 	printf("%x\n", 13);
// 	ft_printf("%x\n", 13);

// 	printf("%x\n", 20);
// 	ft_printf("%x\n", 20);

// 	printf("%x\n", 245);
// 	ft_printf("%x\n", 245);

// 	printf_count = printf("%X\n", 245);
// 	ft_printf_count = ft_printf("%X\n", 245);
// 	printf("%d\n", printf_count);
// 	printf("%d\n", ft_printf_count);

// 	printf("Void pointer:\n");
// 	printf_count = printf("%p", ptr);
// 	printf("\n");
// 	ft_printf_count = ft_printf("%p", ptr);
// 	printf("\n");
// 	printf("%d\n", printf_count);
// 	printf("%d", ft_printf_count);
// 	printf("\n");

// 	printf("\nUnsigned decimal:\n");
// 	max = 4294967295;
// 	printf_count = printf("%u", max);
// 	printf("\n");
// 	ft_printf_count = ft_printf("%u", max);
// 	printf("\n");
// 	printf("%d\n", printf_count);
// 	printf("%d", ft_printf_count);
//     return (0);
// }