/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/16 14:20:42 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/31 13:21:49 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <philo.h>
# include <string.h>

# define GREEN   "\033[0;32m"
# define RED     "\033[0;31m"
# define RESET   "\033[0m"

/* Test utils*/
void	log_test(int condition, const char *message);
void	log_tick(void);
void	log_error(const char *message);
char	*ft_itoa(int nbr);
int		argv_check(char **input_list);
t_error	init_whiteboard_mutexes(t_whiteboard *whiteboard);
t_error	init_forks(t_whiteboard *whiteboard);
t_error	init_philosophers(t_whiteboard *whiteboard);
t_error	spawn_guests(t_whiteboard *whiteboard);

/* Test functions*/
void	test_argc(void);
void	test_argv(void);
void	test_input_checks(void);
void	test_input_to_whiteboard(void);
void	test_init_whiteboard_mutexes(void);
void	test_init_philosophers(void);
void	test_spawn_guests(void);

#endif