SRC := main.cpp Contact.cpp PhoneBook.cpp 
NAME := phonebook
CXX := c++
FLAGS := -Wall -Wextra -Werror -std=c++98
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME)

rerun: fclean run

re: fclean all