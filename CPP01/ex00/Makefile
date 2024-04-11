SRC := main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
NAME := BrainZ
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

run: all
	./$(NAME)

rerun: fclean run

re: fclean all