/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_memchr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/24 16:07:19 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/24 16:30:05 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "./test_utils.h"

void	test_memchr(void)
{
	char	*my_memchr;
	char	*std_memchr;

	my_memchr = ft_memchr("Hello", 'l', 5);
	std_memchr = memchr("Hello", 'l', 5);
	log_test(memcmp(std_memchr, my_memchr, 4) == 0,
		"The returned pointers do not match");

	my_memchr = ft_memchr("Hello", 'l', 10);
	std_memchr = memchr("Hello", 'l', 10);
	log_test(memcmp(std_memchr, my_memchr, 10) == 0,
		"The returned pointers do not match");

	my_memchr = ft_memchr("Hello", 'l', 2);
	std_memchr = memchr("Hello", 'l', 2);
	log_test(my_memchr == NULL,
		"It is not returning NULL");
}
