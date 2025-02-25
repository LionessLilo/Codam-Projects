# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: llourens <llourens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/02/11 17:51:04 by llourens      #+#    #+#                  #
#    Updated: 2025/02/25 18:02:51 by llourens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFTNAME = libft/libft.a
PRINTFNAME = printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
export CFLAGS
INCLUDES = -I./libft -I./printf -I.
VPATH = src utils libft printf
PUSHSWAPDIR = push_swap
PRINTFDIR = printf
LIBFTDIR = libft

SRCS = pipex.c \
	   input_and_cmd1.c \
	   output_and_cmd2.c \
	   error_handling.c \
	#    input_checks.c

FILES_SRCS = ./testing/file_testing/file_test.c \
	   input_and_cmd1.c \
	   output_and_cmd2.c \
	   error_handling.c \

OBJS = $(SRCS:.c=.o)
FILES_OBJS = $(FILES_SRCS:.c=.o)

all: $(NAME)
debug: CFLAGS += -g
debug: re

files: $(FILES_OBJS) $(PRINTFNAME)
	$(CC) $(CFLAGS) $(FILES_OBJS) $(PRINTFNAME) -o files $(INCLUDES)

%.a:
	+$(MAKE) -C $(dir $@)

$(NAME): $(OBJS) $(PRINTFNAME)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTFNAME) -o $(NAME) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@rm -f $(OBJS) $(FILES_OBJS)
	@make -C $(PRINTFDIR) clean
    
fclean: clean
	@rm -f $(NAME) files
	@make -C $(PRINTFDIR) fclean
    
re: fclean all