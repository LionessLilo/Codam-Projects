NAME = philo
CC = cc
INCLUDE = -I./include
CFLAGS = -Werror -Wall -Wextra -Wconversion -pthread

VPATH = src utils
SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
debug: CFLAGS += -g
debug: re

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