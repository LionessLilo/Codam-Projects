# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: llourens <llourens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/10/09 11:29:31 by llourens      #+#    #+#                  #
#    Updated: 2024/10/20 00:09:33 by llourens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_toupper.c ft_tolower.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all