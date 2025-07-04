/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_utils.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/23 12:48:32 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/02 17:00:14 by lilo          ########   odam.nl         */
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
#include <fcntl.h>

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
void	test_strlcpy(void);
void	test_strlcat(void);
void	test_toupper(void);
void	test_tolower(void);
void	test_strchr(void);
void	test_strrchr(void);
void	test_strncmp(void);
void	test_memchr(void);
void	test_memcmp(void);
void	test_strnstr(void);
void	test_atoi(void);
void	test_strdup(void);
void	test_substr(void);
void	test_strjoin(void);
void	test_itoa(void);
void	test_strtrim(void);
void	test_strmapi(void);
void	test_striteri(void);
void	test_split(void);
void	test_putchar_fd(void);
void	test_putstr_fd(void);
void 	test_putendl_fd(void);

#endif