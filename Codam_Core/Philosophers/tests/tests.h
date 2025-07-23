/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/16 14:20:42 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/23 17:31:27 by lionesslilo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

#include <philo.h>

# define GREEN   "\033[0;32m"
# define RED     "\033[0;31m"
# define RESET   "\033[0m"

/* Test utils*/
void	log_test(int condition, const char *message);
void	log_tick(void);
void	log_error(const char *message);

/* Test functions*/
void	test_argc(void);
void	test_argv(void);
int		argv_check(char **input_list);
void	test_input_checks(void);
void	test_input_to_whiteboard(void);
t_error	init_whiteboard_mutexes(t_whiteboard **whiteboard);

#endif