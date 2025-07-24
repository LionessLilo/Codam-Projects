NAME = philo
CC = cc
INCLUDE = -I./include
CFLAGS = -Werror -Wall -Wextra -Wconversion -pthread -ggdb

VPATH = src utils
SRCS = cleanup.c \
		init.c \
		input_checks.c \
		main.c \
		monitor.c \
		philo.c \
		routine.c \
		error_handling.c \
		ft_split.c \
		lib_utils.c \
		clean_up_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(INCLUDE)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f $(OBJS)
    
fclean: clean
	@rm -f $(NAME)
	@rm -f philo
    
re: clean all