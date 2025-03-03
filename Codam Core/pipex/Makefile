# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: llourens <llourens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/02/11 17:51:04 by llourens      #+#    #+#                  #
#    Updated: 2025/03/03 19:04:00 by llourens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFTNAME = libft/libft.a
PRINTFNAME = printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
export CFLAGS
INCLUDES = -I./libft -I./printf -I.
VPATH = src utils libft printf testing
PUSHSWAPDIR = push_swap
PRINTFDIR = printf
LIBFTDIR = libft

SRCS = pipex.c \
	   02_input_and_cmd1.c \
	   03_output_and_cmd2.c \
	   get_cmd_path.c \
	   error_handling.c \
	   input_checks.c \

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
	@rm -f $(OBJS) $(GET_CMD_PATH_OBJS)
	@make -C $(PRINTFDIR) clean
    
fclean: clean
	@rm -f $(NAME) files
	@make -C $(PRINTFDIR) fclean
    
re: fclean all

# TESTING
#Gets the path directories(not sereated).
GET_CMD_PATH_SRCS = get_env_check.c \
					get_cmd_path.c

GET_CMD_PATH_OBJS = $(GET_CMD_PATH_SRCS:.c=.o)

get_cmd_path: $(GET_CMD_PATH_OBJS) $(PRINTFNAME)
	$(CC) $(CFLAGS) $(GET_CMD_PATH_OBJS) $(PRINTFNAME) -o get_cmd_path $(INCLUDES)