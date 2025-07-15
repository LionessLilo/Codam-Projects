/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 12:37:52 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/15 17:53:21 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

void	log_tick(void);
void	log_error(const char *message);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

void	log_test(int condition, const char *message)
{
	if (condition)
		log_tick();
	else
		log_error(message);
}

void	log_tick(void)
{
	printf(GREEN "✓" RESET);
}

void	log_error(const char *message)
{
	printf(RED "\n✗ %s" RESET, message);
}

size_t	ft_strlcpy(char *dst,
				const char *src,
				size_t size)
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