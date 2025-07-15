/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 16:04:36 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/15 17:52:07 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <philo.h>
# include <utils.h>

# define GREEN   "\033[0;32m"
# define RED     "\033[0;31m"
# define RESET   "\033[0m"

void	log_tick(void);
void	log_error(const char *message);
void	log_test(int condition, const char *message);

/* Static functions to test */
size_t	find_list_size(const char *str, char chr);
size_t	get_item_len(const char *str, char chr);
char	**populate_list(const char *str, char chr, char **list);
void	free_list(char **list_start, char **list);

/* Test Functions */
void	test_argc(void);

/* Helper functions*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);


#endif