/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_memcmp.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/24 16:33:31 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/24 16:58:08 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "./test_utils.h"

void	test_memcmp(void)
{
	int	my_memcmp;

	my_memcmp = ft_memcmp("Hello", "Help!", 5);
	log_test(my_memcmp == -4,
		"Shows a difference in the strings");

	my_memcmp = ft_memcmp("Hello", "Help!!!!", 8);
	log_test(my_memcmp == -4, "Shows a difference in the strings");

	my_memcmp = ft_memcmp("Hello", "Hello", 3);
	log_test(my_memcmp == 0,
		"Shows a difference in the strings");
}
