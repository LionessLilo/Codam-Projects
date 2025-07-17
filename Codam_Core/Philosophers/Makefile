NAME = philo
CC = cc
INCLUDE = -I./include
CFLAGS = -Werror -Wall -Wextra -Wconversion -pthread

VPATH = src utils
SRCS = main.c \
		input_checks.c \
		lib_utils.c \
		ft_split.c \

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