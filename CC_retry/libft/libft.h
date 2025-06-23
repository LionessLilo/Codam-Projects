/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 11:13:32 by llourens      #+#    #+#                 */
/*   Updated: 2025/06/23 13:32:51 by lilo          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *string);
void		*ft_memset(void *memory, int filler, size_t size);
void		ft_bzero(void *memory, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t size);
int			ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int chr);
int			ft_tolower(int chr);
char		*ft_strchr(const char *str, int chr);
char		*ft_strrchr(const char *str, int chr);
int			ft_strncmp(const char *str_1, const char *str_2, size_t size);
void		*ft_memchr(const void *str, int byte, size_t size);
void		*ft_memchr(const void *str, int byte, size_t size);
int			ft_memcmp(const void *str_1, const void *str_2, size_t size);
const char	*ft_strnstr(const char *haystack, const char *needle, size_t size);
int			ft_atoi(const char *str);

#endif