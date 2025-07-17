/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 12:25:35 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/16 17:42:22 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>

// typedef struct s_rules
// {
	
// }	t_rules;

// typedef struct s_philo
// {
// 	t_rules	philo_rules;
// }	t_philo;

/* Src Functions */
int			input_checks(int argc, char **argv);

/* Util Functions */
char		**ft_split(char const *str, char chr);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *string);
int			ft_isdigit(int c);
long int	ft_atol(const char *str);



#endif