#include "HumanB.hpp"

HumanB::HumanB() : name("Unnamed Human") {}

HumanB::HumanB(std::string name) {
	this->name = name;
	// this->weapon = nullptr;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}

