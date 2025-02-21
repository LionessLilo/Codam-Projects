# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: llourens <llourens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/02/11 17:51:04 by llourens      #+#    #+#                  #
#    Updated: 2025/02/21 14:40:08 by llourens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = files_test
LIBFTNAME = libft/libft.a
PRINTFNAME = ../../printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
export CFLAGS
INCLUDES = -I./libft -I./printf -I.
VPATH = ../../src ../../utils ../../libft ../../printf testing
PUSHSWAPDIR = push_swap
PRINTFDIR = ../../printf
LIBFTDIR = libft

SRCS = files_test.c \
	   input_and_cmd1.c \
	   output_and_cmd2.c \
	   error_handling.c \
	#    input_checks.c
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