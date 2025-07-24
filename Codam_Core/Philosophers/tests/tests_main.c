/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/16 14:09:17 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/24 11:59:24 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./tests.h"

int	main(void)
{
	printf("\nargc test: \n");
	test_argc();
	printf("\nargv test: \n");
	test_argv();
	printf("\ninput_checks: \n");
	test_input_checks();
	printf("\ninput_to_whiteboard: \n");
	test_input_to_whiteboard();
	printf("\ninit whiteboard mutexes: \n");
	test_init_whiteboard_mutexes();
	printf("\n");
	
	return (0);
}