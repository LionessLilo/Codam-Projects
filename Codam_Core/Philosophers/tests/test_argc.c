/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_argc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/16 14:11:13 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/23 15:28:55 by lionesslilo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./tests.h"
#include <philo.h>

int	check_argc(int argc);

void	test_argc(void)
{
	int		argc;
	t_error	error;

	argc = 5;
	error = check_argc(argc);
	log_test(error == SUCCESS, "Check argc did not return 0 for argc 5");

	argc = 6;
	error = check_argc(argc);
	log_test(error == SUCCESS, "Check argc did not return 0 for argc 6");

	argc = 4;
	error = check_argc(argc);
	log_test(error == USER_INPUT_ERROR, "Did not error for argc smaller than 5");

	argc = 7;
	error = check_argc(argc);
	log_test(error == USER_INPUT_ERROR, "Did not error for argc greater than 6");

}
