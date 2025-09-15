NAME = phonebook
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Contact.cpp \
PhoneBook.cpp \
main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:	
	rm -f $(NAME)

fclean: clean
	@rm -f phonebook

re: fclean all