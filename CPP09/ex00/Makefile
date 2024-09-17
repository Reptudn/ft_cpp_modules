SRC := main.cpp BitconExchange.cpp
HEADERS := BitconExchange.hpp
NAME := btc
CXX := c++
FLAGS := -Wall -Wextra -Werror -std=c++11
OBJ := $(SRC:.cpp=.o)

$(NAME): $(OBJ)
		$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

%.o: %.cpp
		$(CXX) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

run: all
		./$(NAME)

rerun: fclean run

re: fclean all