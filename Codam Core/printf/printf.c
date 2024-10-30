/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 15:06:52 by llourens      #+#    #+#                 */
/*   Updated: 2024/10/30 19:06:30 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

static int	print_from_specifiers(char specifier, va_list arg_pointer)
{
	int	count_from_specifier;

	count_from_specifier = 0;
	if (specifier == 'c')
		write(1, specifier, 1);
	else if (specifier == 's')
		ft_printstr();
	else if (specifier == 'p')
		ft_print_hexadecimal();
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr();
	else if (specifier == 'u')
		print_unsigned_int();
	else if (specifier == )
	return (count_from_specifier);
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
			count += write (1, str, 1);
		str++;
	}
	va_end(arg_pointer);
	return (count);
}
