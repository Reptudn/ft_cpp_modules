SRC := Contact.cpp Phonebook.cpp main.cpp
NAME := phonebook
CXX := c++
FLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all