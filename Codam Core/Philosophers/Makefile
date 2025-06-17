NAME = philo
CC = cc
CFLAGS = -Werror -Wall -Wextra -Wconversion

VPATH = src
SRCS = main.c
OBJS = $(SRCS:.c=.o)
INCLUDE = -I./include

all: $(NAME)
debug: CFLAGS += -g
debug: re

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(INCLUDE)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ $(INCLUDE)

clean:
	@rm -f $(OBJS)
    
fclean: clean
	@rm -f $(NAME)
	@rm -f philo
    
re: clean all