# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: root <root@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2025/01/02 15:29:05 by root          #+#    #+#                  #
#    Updated: 2025/01/21 10:35:46 by llourens      ########   odam.nl          #
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

SRCS = src/02_init_stack_a.c utils/error_handling.c utils/validation_utils.c utils/linked_list_utils.c utils/stack_operations.c utils/rotate_operations.c
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