/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 13:30:33 by llourens      #+#    #+#                 */
/*   Updated: 2024/12/06 20:11:59 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t num, size_t size);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*read_file(int fd);
char	*ft_strdup(const char *s);

#endif