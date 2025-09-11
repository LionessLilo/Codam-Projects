/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 13:30:33 by llourens      #+#    #+#                 */
/*   Updated: 2025/09/10 16:20:41 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>

typedef struct s_buffer
{
	char				*contents;
	int					fd;
	struct s_retrieved	*next;	
}						t_buffer;

/* SRCS */
char		*get_next_line(int fd);
t_buffer	*create_node(int fd);
t_buffer	*read_and_fill(t_buffer *list);

/* UTILS */
void		*ft_memset(void *memory, int filler, size_t size);
char		*ft_strchr(const char *str, int chr);

#endif