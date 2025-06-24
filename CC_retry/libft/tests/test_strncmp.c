/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_strncmp.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/24 15:04:27 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/24 16:05:24 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "./test_utils.h"

void	test_strncmp(void)
{
	int	my_strncmp;
	int	std_strncmp;

	my_strncmp = ft_strncmp("Hello", "Help!", 4);
	std_strncmp = strncmp("Hello", "Help!", 4);
	log_test((std_strncmp - my_strncmp) == 0, "The results do not match");

	my_strncmp = ft_strncmp("Hello", "Hello", 5);
	std_strncmp = strncmp("Hello", "Hello", 5);
	log_test((std_strncmp - my_strncmp) == 0, "The results do not match");

	my_strncmp = ft_strncmp("ABC", "ABC", 3);
	std_strncmp = strncmp("ABC", "ABC", 3);
	log_test(my_strncmp == 0, "The strings should match and don't");

	my_strncmp = ft_strncmp("ABC", "AB", 3);
	std_strncmp = strncmp("ABC", "AB", 3);
	log_test(my_strncmp == 67, "It did not find the difference correctly");
}

