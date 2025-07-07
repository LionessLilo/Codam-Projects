/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strnstr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/26 10:42:42 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/26 10:49:44 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "./test_utils.h"

void	test_strnstr(void)
{
	const char	*my_needlefound;
	const char	*std_nedlefound;

	my_needlefound = ft_strnstr("Hello World", "llo", 7);
	std_nedlefound = strnstr("Hello World", "llo", 7);
	log_test(memcmp(std_nedlefound, my_needlefound, 10) == 0,
		"Did not find the needle");

	my_needlefound = ft_strnstr("Hello World", "", 7);
	std_nedlefound = strnstr("Hello World", "", 7);
	log_test(memcmp(std_nedlefound, my_needlefound, 10) == 0,
		"Did not return haystack if needle is empty");
}
