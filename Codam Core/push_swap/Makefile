# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: root <root@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/19 13:18:32 by root          #+#    #+#                  #
#    Updated: 2024/12/19 17:14:20 by root          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libpushswap.a
LIBFTNAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = printf

SRCS =  push_swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): $(OBJS) makelibft
	@ar -rcs $(NAME) $(OBJS) $(LIBFTDIR)/$(LIBFTNAME)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all