# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: llourens <llourens@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/20 18:11:09 by llourens      #+#    #+#                  #
#    Updated: 2024/12/20 18:42:37 by llourens      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
PRINTFDIR = printf
LIBFTDIR = libft

SRCS =  $(PRINTFDIR)/ft_print_c.c $(PRINTFDIR)/ft_print_di.c $(PRINTFDIR)/ft_print_p.c $(PRINTFDIR)/ft_print_str.c $(PRINTFDIR)/ft_print_u.c $(PRINTFDIR)/ft_print_xx.c $(PRINTFDIR)/ft_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(PRINTFDIR)/$(LIBFTDIR)
	@cp $(PRINTFDIR)/$(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): $(OBJS) makelibft
	@ar -rcs $(NAME) $(OBJS) $(PRINTFDIR)/$(LIBFTDIR)/$(LIBFTNAME)

clean:
	@rm -f $(OBJS)
	@cd $(PRINTFDIR)/$(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(PRINTFDIR)/$(LIBFTDIR) && make fclean
	
re: fclean all
