SRC := main.cpp Span.cpp
HEADERS := Span.hop
NAME := spam
CXX := c++
FLAGS := -Wall -Wextra -Werror -std=c++17 # cpp 17 because of one feature i added
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