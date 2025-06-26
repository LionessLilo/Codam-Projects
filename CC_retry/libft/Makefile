# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: llourens <llourens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/05/02 11:04:34 by llourens      #+#    #+#                  #
#    Updated: 2025/06/26 16:36:26 by lilo          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SCRS = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c

OBJS = $(SCRS:.c=.o)

all: $(NAME)
.PHONY: tests

tests: $(NAME) clean
	cc -Wall -Wextra -Werror -g tests/*.c -lbsd $(NAME) -o tests/test_libft

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f main
	rm -f ./tests/test_main

re: fclean all