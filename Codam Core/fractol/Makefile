# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: llourens <llourens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/13 09:06:24 by llourens      #+#    #+#                  #
#    Updated: 2025/03/24 12:46:47 by llourens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBFTNAME = libft/libft.a
PRINTFNAME = printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
export CFLAGS
INCLUDES = -I./libft -I./printf -I. $(LIBMLX)/include
VPATH = src utils libft printf
FRACTOLDIR = fractol
PRINTFDIR = printf
LIBFTDIR = libft
LIBMLX42 = ./MLX42
LINKING = $(LIBMLX42)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS = ./testing/coordinate_functions.c \
		mandelbrot.c \
		mandelbrot_utils.c

OBJS = $(SRCS:.c=.o)

all: libmlx42 $(NAME)
debug: CFLAGS += -g -fsanitize=address
debug: re

libmlx42:
	@cmake $(LIBMLX42) -B $(LIBMLX42)/build && make -C $(LIBMLX42)/build -j4

%.a:
	+$(MAKE) -C $(dir $@)

$(NAME): $(OBJS) $(PRINTFNAME)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LINKING) $(PRINTFNAME) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@rm -rf $(LIBMLX42)/build
	@rm -f $(OBJS)
	@make -C $(PRINTFDIR) clean
    
fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTFDIR) fclean
    
re: clean all