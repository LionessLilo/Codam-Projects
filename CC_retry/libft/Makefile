# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: llourens <llourens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/05/02 11:04:34 by llourens      #+#    #+#                  #
#    Updated: 2025/07/10 17:25:32 by lilo          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -ggdb

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
		ft_strjoin.c \
		ft_itoa.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_split.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
	
BONUS_SCRS = ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

OBJS = $(SCRS:.c=.o)
BONUS_OBJS = $(BONUS_SCRS:.c=.o)

all: $(NAME)
.PHONY: tests

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

tests: $(NAME) clean
	cc -Wall -Wextra -Werror -ggdb tests/*.c -lbsd $(NAME) -o tests/test_libft
	
bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f main
	rm -f ./tests/test_libft

re: fclean all
