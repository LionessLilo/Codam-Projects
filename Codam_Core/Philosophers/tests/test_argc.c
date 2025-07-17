/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_argc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/16 14:11:13 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/16 16:55:30 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./tests.h"

int	check_argc(int argc);

void	test_argc(void)
{
	int	argc;
	int	result;

	argc = 5;
	result = check_argc(argc);
	log_test(result == 0, "Check argc did not return 0 for argc 5");

	argc = 6;
	result = check_argc(argc);
	log_test(result == 0, "Check argc did not return 0 for argc 6");

	argc = 4;
	result = check_argc(argc);
	log_test(result == 41, "Did not error for argc smaller than 5");

	argc = 7;
	result = check_argc(argc);
	log_test(result == 41, "Did not error for argc greater than 6");

}
