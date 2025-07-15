/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_argc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 16:16:11 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/15 18:02:18 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <tests.h>

int	check_argc(int argc);

void	test_argc(void)
{
	int	argc;
	int	result_argc;

	argc = 5;
	result_argc = check_argc(argc);
	log_test(result_argc == 0, "Did not return correct int for argc");
}
