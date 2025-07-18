/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_input_checks.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/16 16:25:47 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/18 17:25:19 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include "./tests.h"

void	test_input_checks(void)
{
	int		argc = 5;
	int		result;

	char 	*test1[] = {"name", "10", "200", "200", "200", NULL};
	result = input_checks(argc, test1);
	log_test(result == 0, "Input checks is returning an error for valid input");

	char 	*test2[] = {"name", "-10", "200", "200", NULL};
	result = input_checks(argc, test2);
	log_test(result == 41, "Input checks is not returning an error for not enough args");

	char 	*test3[] = {"name", "10", "2147483649", "200", "200", NULL};
	result = input_checks(argc, test3);
	log_test(result == 41, "Input checks is not returning an error for greater than MAX INT");

	char 	*test4[] = {"name", "10", "-2147483649", "200", "200", NULL};
	result = input_checks(argc, test4);
	log_test(result == 41, "Input checks is not returning an error for not less than MIN INT");

	char 	*test5[] = {"name", "600", "200", "200", "200", NULL};
	result = input_checks(argc, test5);
	log_test(result == 41, "Input checks is not returning an error for greater than 500 philosophers");

	char 	*test6[] = {NULL};
	result = input_checks(argc, test6);
	log_test(result == 41, "Input checks is not returning an error for NULL input");

	argc  = 2;
	char 	*test7[] = {"name", "10 200 200 200", NULL};
	result = input_checks(argc, test7);
	log_test(result == 0, "Input checks is returning an error for valid input");

	char 	*test8[] = {"name", "-10 200 200", NULL};
	result = input_checks(argc, test8);
	log_test(result == 41, "Input checks is not returning an error for not enough args");

	char 	*test9[] = {"name", "10 2147483649 200 200", NULL};
	result = input_checks(argc, test9);
	log_test(result == 41, "Input checks is not returning an error for greater than MAX INT");

	char 	*test10[] = {"name", "10 -2147483649 200 200", NULL};
	result = input_checks(argc, test10);
	log_test(result == 41, "Input checks is not returning an error for not less than MIN INT");

	char 	*test11[] = {"name", "600 200 200 200", NULL};
	result = input_checks(argc, test11);
	log_test(result == 41, "Input checks is not returning an error for greater than 500 philosophers");
}
