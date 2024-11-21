/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/19 13:02:59 by llourens      #+#    #+#                 */
/*   Updated: 2024/11/21 19:43:31 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	*ft_calloc(size_t num, size_t size);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*read_file(int fd);

#endif

