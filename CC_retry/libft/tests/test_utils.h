/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_utils.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 12:48:32 by lilo          #+#    #+#                 */
/*   Updated: 2025/06/23 16:31:10 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_H
# define TEST_UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include <ctype.h>

# define GREEN   "\033[0;32m"
# define RED     "\033[0;31m"
# define RESET   "\033[0m"

/* Test utils*/
void	log_test(int condition, const char *message);
void	log_tick(void);
void	log_error(const char *message);

/* Test functions*/
void	test_isalpha(void);
void	test_isdigit(void);
void	test_isalnum(void);
void	test_isprint(void);
void	test_strlen(void);
void	test_memset(void);
void	test_bzero(void);
void	test_memcpy(void);
void	test_memmove(void);


#endif