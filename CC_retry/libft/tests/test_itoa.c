/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_itoa.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/27 12:04:09 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/27 15:56:16 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "test_utils.h"

void	test_itoa(void)
{
	char	*printable_nbr;

	printable_nbr = ft_itoa(1234);
	log_test(memcmp(printable_nbr, "1234", 5) == 0,
		"Did not print positive number correctly");
	free(printable_nbr);

	printable_nbr = ft_itoa(-1234);
	log_test(memcmp(printable_nbr, "-1234", 5) == 0,
		"Did not print negative number correctly");
	free(printable_nbr);

	printable_nbr = ft_itoa(-2147483648);
	log_test(memcmp(printable_nbr, "-2147483648", 12) == 0,
		"Did not print int min number correctly");
	free(printable_nbr);

	printable_nbr = ft_itoa(2147483647);
	log_test(memcmp(printable_nbr, "2147483647", 11) == 0,
		"Did not print int max number correctly");
	free(printable_nbr);
}
