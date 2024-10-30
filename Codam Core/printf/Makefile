# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: llourens <llourens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/10/30 17:53:40 by llourens      #+#    #+#                  #
#    Updated: 2024/10/30 18:01:51 by llourens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = ft_printf.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all