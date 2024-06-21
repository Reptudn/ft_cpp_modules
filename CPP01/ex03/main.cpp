#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

// TODO: when making a weapon, for some reason the destructor is called right away
int main()
{
	{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	std::cout << "\n" << std::endl;
	{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}

return 0;
}