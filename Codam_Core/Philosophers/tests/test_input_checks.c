/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_input_checks.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/16 16:25:47 by lilo          #+#    #+#                 */
/*   Updated: 2025/08/06 17:20:31 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include "./tests.h"
#include <string.h>

void	test_input_checks(void)
{
	int		result = 0;

	char 	*test1[] = {"name", "10", "200", "200", "200", NULL};
	result = input_checks(5, test1);
	log_test(result == 0, "Input checks is returning an error for valid input");

	char 	*test2[] = {"name", "-10", "200", "200", NULL};
	result = input_checks(4, test2);
	log_test(result == 41, "Input checks is not returning an error for not enough args");

	char 	*test3[] = {"name", "10", "2147483649", "200", "200", NULL};
	result = input_checks(5, test3);
	log_test(result == 41, "Input checks is not returning an error for greater than MAX INT");

	char 	*test4[] = {"name", "10", "-2147483649", "200", "200", NULL};
	result = input_checks(5, test4);
	log_test(result == 41, "Input checks is not returning an error for not less than MIN INT");

	char 	*test5[] = {"name", "600", "200", "200", "200", NULL};
	result = input_checks(5, test5);
	log_test(result == 41, "Input checks is not returning an error for greater than 500 philosophers");

	char 	*test6[] = {NULL};
	result = input_checks(0, test6);
	log_test(result == 41, "Input checks is not returning an error for NULL input");

	char 	*test7[] = {"name", "10 200 200 200", NULL};
	result = input_checks(2, test7);
	log_test(result == 0, "Input checks is returning an error for valid input");

	char 	*test8[] = {"name", "-10 200 200", NULL};
	result = input_checks(2, test8);
	log_test(result == 41, "Input checks is not returning an error for not enough args");

	char 	*test9[] = {"name", "10 2147483649 200 200", NULL};
	result = input_checks(2, test9);
	log_test(result == 41, "Input checks is not returning an error for greater than MAX INT");

	char 	*test10[] = {"name", "10 -2147483649 200 200", NULL};
	result = input_checks(2, test10);
	log_test(result == 41, "Input checks is not returning an error for not less than MIN INT");

	char 	*test11[] = {"name", "600 200 200 200", NULL};
	result = input_checks(2, test11);
	log_test(result == 41, "Input checks is not returning an error for argc 2 and more than 200 philos");

	char 	*test12[] = {"name", "10 200 200 200 200", NULL};
	result = input_checks(2, test12);
	log_test(result == 0, "Input checks is not returning 0 for 6 args");

	char 	*test13[] = {"name", "10", "200", "200", "200", "200", NULL};
	result = input_checks(6, test13);
	log_test(result == 0, "Input checks is not returning 0 for 6 args");
}
