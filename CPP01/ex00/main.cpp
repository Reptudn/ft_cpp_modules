#include <iostream>
#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie newZombie(name);
	newZombie.announce();
}

Zombie* newZombie(std::string name)
{
	return new Zombie(name);
}

int main ()
{
	Zombie* zombie = newZombie("Zombie");
	zombie->announce();

	randomChump("Chump");
	return 0;
}