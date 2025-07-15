/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/14 14:01:39 by lilo          #+#    #+#                 */
/*   Updated: 2025/07/15 17:46:42 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <philo.h>
#include <utils.h>

size_t	ft_strlen(const char *string);
int		error_message(char *message);
int		ft_isdigit(int c);
char	**ft_split(char const *str, char chr);
size_t	find_list_size(const char *str, char chr);

#endif