# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: root <root@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2025/02/03 19:41:23 by root          #+#    #+#                  #
#    Updated: 2025/02/03 22:00:58 by root          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
export CFLAGS

SRCS = ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memset.c \
		ft_strlen.c 
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)
debug: CFLAGS += -g
debug: re

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all