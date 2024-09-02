SRC := main.cpp Bureaucrat.cpp
HEADERS := Bureaucrat.hpp
NAME := bureaucrat
CXX := c++
FLAGS := -Wall -Wextra -Werror -std=c++98
OBJ := $(SRC:.cpp=.o)

$(NAME): $(OBJ)
        $(CXX) $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

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