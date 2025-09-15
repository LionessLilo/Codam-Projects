NAME = megaphone
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:	
	rm -f $(NAME)

fclean: clean
	@rm -f megaphone

re: fclean all