/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_argv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/16 14:54:29 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/11 15:50:29 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include "./tests.h"

void	test_argv(void)
{
	/* Valid input */
	char	*test1[] = {"15", "200", "200", "200", NULL};
	log_test(argv_check(test1) == 0, "argv_check did not  return 0 with valid numbers");

	/* Negative */
	char *test2[] = {"name", "-10", "200", "200", "200", NULL};
	log_test(argv_check(test2) == 41, "Did not return error for negative number");

	/* Not only digits */
	char *test3[] = {"name", "10", "20l0", "200", "200", NULL};
	log_test(argv_check(test3) == 41, "Did not return error for none digit number");

	/* Space */
	char *test4[] = {"name", "10", " ", "200", "200", NULL};
	log_test(argv_check(test4) == 41, "Did not return error for number with a space");

	/* Empty string */
	char *test5[] = {"name", "10", "", "200", "200", NULL};
	log_test(argv_check(test5) == 41, "Did not return error for an empty string");
}
