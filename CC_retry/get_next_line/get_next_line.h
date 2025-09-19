/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lilo <lilo@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/09/18 15:45:42 by lilo          #+#    #+#                 */
/*   Updated: 2025/09/19 12:10:34 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <unistd.h>

typedef struct s_buffer
{
	char			buffer[BUFFER_SIZE + 1];
	struct s_buffer	*next;
}					t_buffer;

/* SRC */
char				*get_next_line(int fd);
char				*fetch_line(int fd, char *leftover);
char				*extract_line(t_buffer *list);
t_buffer			*create_node(void);
char				*leftover_and_clean(char *fetched_line);

/* Utils */
char				*empty_string(void);
char				*ft_strchr(const char *str, int chr);
size_t				ft_strlen(const char *string);
void				free_list(t_buffer *list);
char				*ft_strjoin(char const *str1, char const *str2);

#endif