/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_argc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/16 14:11:13 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/11 15:47:59 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./tests.h"
#include <philo.h>

int	check_argc(int argc);

void	test_argc(void)
{
	int		argc;

	argc = 5;
	log_test(check_argc(argc) == 0, "Check argc did not return 0 for argc 5");

	argc = 6;
	log_test(check_argc(argc) == 0, "Check argc did not return 0 for argc 6");

	argc = 4;
	log_test(check_argc(argc) == 41, "Did not error for argc smaller than 5");

	argc = 7;
	log_test(check_argc(argc) == 41, "Did not error for argc greater than 6");
}

