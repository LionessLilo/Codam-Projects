/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_atoi.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/26 10:56:05 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/26 12:22:52 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "./test_utils.h"

void	test_atoi(void)
{
	int	my_atoi;
	int	std_atoi;

	my_atoi = ft_atoi("-1234");
	std_atoi = atoi("-1234");
	log_test(my_atoi == std_atoi,
		"Did not produce the same integer for negative");

	my_atoi = ft_atoi("1234");
	std_atoi = atoi("1234");
	log_test(my_atoi == std_atoi,
		"Did not produce the same integer for positive");

	my_atoi = ft_atoi("  ++--+   -1234");
	std_atoi = atoi("  ++--+   -1234");
	log_test(my_atoi == std_atoi,
		"Did not produce the same integer for multiple signs");

	my_atoi = ft_atoi("  -1234");
	std_atoi = atoi("  -1234");
	log_test(my_atoi == std_atoi,
		"Did not produce the same integer for spaces and negative");

	my_atoi = ft_atoi("  1234");
	std_atoi = atoi("  1234");
	log_test(my_atoi == std_atoi,
		"Did not produce the same integer for space and positive");

	my_atoi = ft_atoi("  ++--+   1234");
	std_atoi = atoi("  ++--+   1234");
	log_test(my_atoi == std_atoi,
		"Did not produce the same integer for multiple signs and positive");
}
