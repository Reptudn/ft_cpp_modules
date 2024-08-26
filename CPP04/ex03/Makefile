SRC := main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
HEADERS := AMateria.hpp ICharacter.hpp Character.hpp Cure.hpp Ice.hpp IMateriaSource.hpp MateriaSource.hpp
NAME := materia
CXX := c++
FLAGS := -Wall -Wextra -Werror
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
