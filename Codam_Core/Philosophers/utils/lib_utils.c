/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lib_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 14:00:29 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/12 18:11:49 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

size_t		ft_strlcpy(char *dst, const char *src, size_t size);
long int	ft_atol(const char *str);
int			ft_isdigit(int c);

size_t	ft_strlen(const char *string)
{
	size_t	length;

	length = 0;
	while (string[length])
		length++;
	return (length);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		len_src;
	const char	*end;

	len_src = ft_strlen(src);
	if (!dst || !src)
		return (len_src);
	if (size == 0)
		return (len_src);
	end = src + size - 1;
	while (*src && src != end)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (len_src);
}

long int	ft_atol(const char *str)
{
	int			sign;
	long int	nbr;

	sign = 1;
	nbr = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str) == 1)
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (sign * nbr);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
