NAME = philo
CC = cc
INCLUDE = -I./include -I./tests
CFLAGS = -Werror -Wall -Wextra -Wconversion -pthread

VPATH = src utils
SRCS = ./tests/tests_main.c \
		input_checks.c \
		input_utils.c \
		lib_utils.c \
		ft_split.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(INCLUDE)

tests: $(NAME) clean
	cc -Wall -Wextra -Werror -ggdb tests/*.c -lbsd $(NAME) -o tests/test_philo

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f $(OBJS)
    
fclean: clean
	@rm -f $(NAME)
	@rm -f philo
	rm -f ./tests/test_philo
    
re: clean all