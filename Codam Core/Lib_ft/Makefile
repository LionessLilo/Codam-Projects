# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: llourens <llourens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/10/09 11:29:31 by llourens      #+#    #+#                  #
#    Updated: 2024/10/11 18:15:39 by llourens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCS = ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_toupper.c ft_toupper.c ft_strchr.c ft_strchr.c ft_strncmp.c ft_memchr.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c mylib.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all