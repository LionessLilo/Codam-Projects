# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: root <root@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2025/01/02 15:29:05 by root          #+#    #+#                  #
#    Updated: 2025/02/06 15:22:08 by llourens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
LIBFTNAME = libft/libft.a
PRINTFNAME = printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
export CFLAGS
INCLUDES = -I./includes -I./libft -I./printf
VPATH = src utils libft printf
MINITALKDIR = minitalk
PRINTFDIR = printf
LIBFTDIR = libft

SRCS = utils/error_handling.c \
		input_error_handling.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
debug: CFLAGS += -g
debug: re

%.a:
	+$(MAKE) -C $(dir $@)

$(NAME): $(OBJS) $(PRINTFNAME)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTFNAME) -o $(NAME) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@rm -f $(OBJS)
	@make -C $(PRINTFDIR) clean
    
fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTFDIR) fclean
    
re: fclean all