# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: root <root@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2025/01/02 15:29:05 by root          #+#    #+#                  #
#    Updated: 2025/01/06 10:40:45 by llourens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
LIBFTNAME = libft.a
PRINTFNAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
PUSHSWAPDIR = push_swap
PRINTFDIR = printf
LIBFTDIR = libft

SRCS = utils/input_validation.c utils/stack_operations.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makeprintf:
	@make -C $(PRINTFDIR)
	@cp $(PRINTFDIR)/$(PRINTFNAME) .
	@mv $(PRINTFNAME) $(NAME)

$(NAME): $(OBJS) makeprintf
	@ar -rcs $(NAME) $(OBJS) $(PRINTFDIR)/$(PRINTFNAME)

clean:
	@rm -f $(OBJS)
	@make -C $(PRINTFDIR) clean
    
fclean: clean
	@rm -f $(NAME)
	@make -C $(PRINTFDIR) fclean
    
re: fclean all