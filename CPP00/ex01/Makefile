SRC := main.cpp Contact.cpp PhoneBook.cpp 
NAME := phonebook
CXX := c++
FLAGS := -Wall -Wextra -Werror -std=c++98
OBJ := $(SRC:.cpp=.o)

all: $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all