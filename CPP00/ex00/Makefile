SRC := main.cpp
OBJ := $(SRC:.cpp=.o)
FLAGS := -Wall -Wextra -Werror -std=c++98

all: $(OBJ)
	c++ $(FLAGS) $(OBJ) -o megaphone

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f megaphone

re: fclean all