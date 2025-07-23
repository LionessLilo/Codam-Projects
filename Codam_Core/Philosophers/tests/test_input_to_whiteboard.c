/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_input_to_whiteboard.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/18 14:59:46 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/23 15:31:09 by lionesslilo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include "tests.h"

void	test_input_to_whiteboard(void)
{
	t_whiteboard	*whiteboard_test;

	char 	*test1[] = {"10", "400", "200", "100", "15", NULL};
	init_whiteboard(&whiteboard_test, test1);
	log_test(whiteboard_test->nbr_philosophers == 10
		  && whiteboard_test->time_to_die == 400
		  && whiteboard_test->time_to_eat == 200
		  && whiteboard_test->time_to_sleep == 100
		  && whiteboard_test->times_to_eat == 15, 
		  "Whiteboard did not initialise input correctly");
	
	char 	*test2[] = {"10", "400", "200", "100", NULL};
	init_whiteboard(&whiteboard_test, test2);
	log_test(whiteboard_test->nbr_philosophers == 10
		  && whiteboard_test->time_to_die == 400
		  && whiteboard_test->time_to_eat == 200
		  && whiteboard_test->time_to_sleep == 100
		  && whiteboard_test->times_to_eat == -1, 
		  "Whiteboard did not initialise input correctly");
}
